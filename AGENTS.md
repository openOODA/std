# std: Agent Engineering Standards (v1)

This repository houses the openOODA standard library across 8 functional domains (`core`, `fs`, `net`, `sec`, `science`, `app`, `hw`, `meta`).
All work in this repository strictly defers to the organization standards in [`openOODA/AGENTS.md`](file:///home/ubermetroid/Projects/openOODA/openOODA/AGENTS.md).

---

## 1. Standard Library Architecture & Invariants
- **Domain Encapsulation**: 8 domains, each accessed via a domain `anchor.oo` root.
- **Zero-Heap Performance**: Arena-backed data structures, linear arenas with bulk resets, zero-leak ARC.
- **Zero Ambient Authority**: Every privileged operation requires explicit capability token arguments (`&FsReadCap`, `&NetCap`, etc.).

---

## 2. Invariants & Quality Standards
- **The Page Rule**: Every `.oo` page must be between 16 and 256 lines. Pure import shims skip the floor.
- **Directory Density**: At most 8 `.oo` pages per directory. Crowded modules split along domain seams with child `anchor.oo` files.
- **4-Element Academy Header**: Mandatory on every `.oo` page (`// #`, `// Logline:`, `// Setup:`, `// Beats:`).
- **Double-Run Determinism**: All `qa/*.oo` verification probes must pass sequentially in fresh processes.

---

## 3. Local Verification Commands
```bash
cli check core/anchor.oo
cli qa
```
