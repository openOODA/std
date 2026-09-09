#!/bin/bash
# qa/wal_kill_recover.sh — hostile SIGKILL timing proof for the on-disk WAL.
# The .oo probe cannot kill (sys_spawn/sys_kill are sealed residuals), so this
# driver owns the crash: writer appends 3 fsynced records then sleeps, the
# driver SIGKILLs it mid-sleep, and a FRESH process must replay all 3.
# A truncated copy must replay the verified prefix with the truncated flag.
set -u
STD=/home/jeryd/Projects/openOODA/std
# Pinned workspace toolchain: never inherit $OODA_COMPILER (shell init may
# point at a stale installed binary without the new lowering).
OODAC=/home/jeryd/Projects/openOODA/oodac/bin/oodac_bin.core
BIN=/tmp/ooda_write/probe_wal_disk
LOG=/tmp/ooda_write/wal_kill.log
export OODA_NO_JAIL=1
export OODA_COMPILER=$OODAC
mkdir -p /tmp/ooda_write
cd $STD || exit 1
rm -f .ooda-cache/ooda-tmp/wal_selftest.log
"$OODAC" check qa/probe_wal_disk.oo || exit 1
"$OODAC" build --backend c qa/probe_wal_disk.oo -o $BIN || exit 1
"$BIN" write "$LOG" 30000 &
WPID=$!
sleep 1
kill -KILL $WPID
wait $WPID 2>/dev/null
"$BIN" recover "$LOG" || exit 1
head -c -5 "$LOG" > "${LOG}.torn"
"$BIN" recover_torn "${LOG}.torn" || exit 1
rm -f "$LOG" "${LOG}.torn" $BIN
echo "OK	wal_kill_recover	kill+replay+torn"
