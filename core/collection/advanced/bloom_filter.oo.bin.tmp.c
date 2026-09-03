#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <unistd.h>
/* runtime decls (defined in chs_rt.c) */
typedef struct { uint32_t ref_count; uint32_t flags; } OoListHeader;
void *oo_list_alloc_payload(size_t elem_size, size_t cap);
void oo_list_quota_release_bytes(long long cap, size_t elem_size);
void oo_payload_free(void *ptr);
typedef struct { char *data; long long len; } OoStr;
typedef struct { long long *data; long long len; long long cap; } OoIList;
typedef struct { OoStr *data; long long len; long long cap; } OoSList;
typedef struct { double *data; long long len; long long cap; } OoFList;
typedef struct { int ok; OoStr val; } OoResS;
typedef struct { int ok; OoStr err; } OoResV;
typedef struct { int ok; long long val; OoStr err; } OoResI;
typedef struct { int ok; long long val; long long err; } OoResII;
typedef struct { int ok; int val; OoStr err; } OoResB;
typedef struct { int ok; double val; OoStr err; } OoResF;
typedef struct { int ok; OoIList val; OoStr err; } OoResLI;
typedef struct { int ok; OoSList val; OoStr err; } OoResLS;
typedef struct { int ok; OoFList val; OoStr err; } OoResLF;
void oo_str_retain(OoStr); void oo_str_release(OoStr); void oo_ilist_retain(OoIList); void oo_ilist_release(OoIList); void oo_slist_retain(OoSList); void oo_slist_release(OoSList); void oo_flist_retain(OoFList); void oo_flist_release(OoFList);
typedef struct { int ok; int has_val; long long val; OoStr err; } OoResO_I;
typedef struct { int ok; int has_val; OoStr val; OoStr err; } OoResO_S;
typedef struct { int ok; int has_val; int val; OoStr err; } OoResO_B;
typedef struct { int ok; int has_val; double val; OoStr err; } OoResO_F;
typedef struct { int ok; int has_val; OoIList val; OoStr err; } OoResO_LI;
typedef struct { int ok; int has_val; OoSList val; OoStr err; } OoResO_LS;
typedef struct { int ok; int has_val; OoFList val; OoStr err; } OoResO_LF;
typedef struct { int has_val; long long val; } OoOpt_I; typedef struct { int has_val; OoStr val; } OoOpt_S; typedef struct { int has_val; int val; } OoOpt_B; typedef struct { int has_val; double val; } OoOpt_F; typedef struct { int has_val; OoIList val; } OoOpt_LI; typedef struct { int has_val; OoSList val; } OoOpt_LS; typedef struct { int has_val; OoFList val; } OoOpt_LF;
static inline void oo_retain_OoOpt_I(OoOpt_I v) {} static inline void oo_release_OoOpt_I(OoOpt_I v) {} static inline void oo_retain_OoOpt_S(OoOpt_S v) { if (v.has_val) oo_str_retain(v.val); } static inline void oo_release_OoOpt_S(OoOpt_S v) { if (v.has_val) oo_str_release(v.val); } static inline void oo_retain_OoOpt_B(OoOpt_B v) {} static inline void oo_release_OoOpt_B(OoOpt_B v) {} static inline void oo_retain_OoOpt_F(OoOpt_F v) {} static inline void oo_release_OoOpt_F(OoOpt_F v) {} static inline void oo_retain_OoOpt_LI(OoOpt_LI v) { if (v.has_val) oo_ilist_retain(v.val); } static inline void oo_release_OoOpt_LI(OoOpt_LI v) { if (v.has_val) oo_ilist_release(v.val); } static inline void oo_retain_OoOpt_LS(OoOpt_LS v) { if (v.has_val) oo_slist_retain(v.val); } static inline void oo_release_OoOpt_LS(OoOpt_LS v) { if (v.has_val) oo_slist_release(v.val); } static inline void oo_retain_OoOpt_LF(OoOpt_LF v) { if (v.has_val) oo_flist_retain(v.val); } static inline void oo_release_OoOpt_LF(OoOpt_LF v) { if (v.has_val) oo_flist_release(v.val); }
typedef struct { int ok; OoOpt_I val; OoStr err; } OoRes_OoOpt_I; typedef struct { int ok; OoOpt_S val; OoStr err; } OoRes_OoOpt_S; typedef struct { int ok; OoOpt_B val; OoStr err; } OoRes_OoOpt_B; typedef struct { int ok; OoOpt_F val; OoStr err; } OoRes_OoOpt_F; typedef struct { int ok; OoOpt_LI val; OoStr err; } OoRes_OoOpt_LI; typedef struct { int ok; OoOpt_LS val; OoStr err; } OoRes_OoOpt_LS; typedef struct { int ok; OoOpt_LF val; OoStr err; } OoRes_OoOpt_LF;
static inline void oo_retain_OoRes_OoOpt_I(OoRes_OoOpt_I v) { if (v.ok) oo_retain_OoOpt_I(v.val); else oo_str_retain(v.err); } static inline void oo_release_OoRes_OoOpt_I(OoRes_OoOpt_I v) { if (v.ok) oo_release_OoOpt_I(v.val); else oo_str_release(v.err); } static inline void oo_retain_OoRes_OoOpt_S(OoRes_OoOpt_S v) { if (v.ok) oo_retain_OoOpt_S(v.val); else oo_str_retain(v.err); } static inline void oo_release_OoRes_OoOpt_S(OoRes_OoOpt_S v) { if (v.ok) oo_release_OoOpt_S(v.val); else oo_str_release(v.err); }
static inline void oo_retain_OoRes_OoOpt_B(OoRes_OoOpt_B v) { if (v.ok) oo_retain_OoOpt_B(v.val); else oo_str_retain(v.err); } static inline void oo_release_OoRes_OoOpt_B(OoRes_OoOpt_B v) { if (v.ok) oo_release_OoOpt_B(v.val); else oo_str_release(v.err); } static inline void oo_retain_OoRes_OoOpt_F(OoRes_OoOpt_F v) { if (v.ok) oo_retain_OoOpt_F(v.val); else oo_str_retain(v.err); } static inline void oo_release_OoRes_OoOpt_F(OoRes_OoOpt_F v) { if (v.ok) oo_release_OoOpt_F(v.val); else oo_str_release(v.err); }
static inline void oo_retain_OoRes_OoOpt_LI(OoRes_OoOpt_LI v) { if (v.ok) oo_retain_OoOpt_LI(v.val); else oo_str_retain(v.err); } static inline void oo_release_OoRes_OoOpt_LI(OoRes_OoOpt_LI v) { if (v.ok) oo_release_OoOpt_LI(v.val); else oo_str_release(v.err); } static inline void oo_retain_OoRes_OoOpt_LS(OoRes_OoOpt_LS v) { if (v.ok) oo_retain_OoOpt_LS(v.val); else oo_str_retain(v.err); } static inline void oo_release_OoRes_OoOpt_LS(OoRes_OoOpt_LS v) { if (v.ok) oo_release_OoOpt_LS(v.val); else oo_str_release(v.err); } static inline void oo_retain_OoRes_OoOpt_LF(OoRes_OoOpt_LF v) { if (v.ok) oo_retain_OoOpt_LF(v.val); else oo_str_retain(v.err); } static inline void oo_release_OoRes_OoOpt_LF(OoRes_OoOpt_LF v) { if (v.ok) oo_release_OoOpt_LF(v.val); else oo_str_release(v.err); }
typedef OoRes_OoOpt_LS OoRes_OoOpt_OoL_S; typedef OoRes_OoOpt_LI OoRes_OoOpt_OoL_I; typedef OoRes_OoOpt_LF OoRes_OoOpt_OoL_F; typedef OoOpt_LS OoOpt_OoL_S; typedef OoOpt_LI OoOpt_OoL_I; typedef OoOpt_LF OoOpt_OoL_F; typedef OoSList OoL_S; typedef OoIList OoL_I; typedef OoFList OoL_F; typedef OoResS OoRes_S; typedef OoResI OoRes_I; typedef struct { int has_val; OoResS val; } OoOpt_OoRes_S;
static inline void oo_retain_OoRes_S(OoResS v) { oo_str_retain(v.val); } static inline void oo_release_OoRes_S(OoResS v) { oo_str_release(v.val); } static inline void oo_retain_OoRes_I(OoResI v) { if (!v.ok) oo_str_retain(v.err); } static inline void oo_release_OoRes_I(OoResI v) { if (!v.ok) oo_str_release(v.err); } static inline void oo_retain_OoOpt_OoRes_S(OoOpt_OoRes_S v) { if (v.has_val) oo_retain_OoRes_S(v.val); } static inline void oo_release_OoOpt_OoRes_S(OoOpt_OoRes_S v) { if (v.has_val) oo_release_OoRes_S(v.val); }
static inline void oo_retain_OoOpt_OoL_S(OoOpt_LS v) { oo_retain_OoOpt_LS(v); } static inline void oo_release_OoOpt_OoL_S(OoOpt_LS v) { oo_release_OoOpt_LS(v); } static inline void oo_retain_OoOpt_OoL_I(OoOpt_LI v) { oo_retain_OoOpt_LI(v); } static inline void oo_release_OoOpt_OoL_I(OoOpt_LI v) { oo_release_OoOpt_LI(v); } static inline void oo_retain_OoOpt_OoL_F(OoOpt_LF v) { oo_retain_OoOpt_LF(v); } static inline void oo_release_OoOpt_OoL_F(OoOpt_LF v) { oo_release_OoOpt_LF(v); }
static inline void oo_retain_OoRes_OoOpt_OoL_S(OoRes_OoOpt_LS v) { oo_retain_OoRes_OoOpt_LS(v); } static inline void oo_release_OoRes_OoOpt_OoL_S(OoRes_OoOpt_LS v) { oo_release_OoRes_OoOpt_LS(v); } static inline void oo_retain_OoRes_OoOpt_OoL_I(OoRes_OoOpt_LI v) { oo_retain_OoRes_OoOpt_LI(v); } static inline void oo_release_OoRes_OoOpt_OoL_I(OoRes_OoOpt_LI v) { oo_release_OoRes_OoOpt_LI(v); } static inline void oo_retain_OoRes_OoOpt_OoL_F(OoRes_OoOpt_LF v) { oo_retain_OoRes_OoOpt_LF(v); } static inline void oo_release_OoRes_OoOpt_OoL_F(OoRes_OoOpt_LF v) { oo_release_OoRes_OoOpt_LF(v); }
void oo_reso_I_retain(OoResO_I); void oo_reso_I_release(OoResO_I); void oo_reso_S_retain(OoResO_S); void oo_reso_S_release(OoResO_S); void oo_reso_B_retain(OoResO_B); void oo_reso_B_release(OoResO_B); void oo_reso_F_retain(OoResO_F); void oo_reso_F_release(OoResO_F); void oo_reso_LI_retain(OoResO_LI); void oo_reso_LI_release(OoResO_LI); void oo_reso_LS_retain(OoResO_LS); void oo_reso_LS_release(OoResO_LS); void oo_reso_LF_retain(OoResO_LF); void oo_reso_LF_release(OoResO_LF);
static inline void oo_retain_OoResO_I(OoResO_I v) { oo_reso_I_retain(v); } static inline void oo_release_OoResO_I(OoResO_I v) { oo_reso_I_release(v); } static inline void oo_retain_OoResO_S(OoResO_S v) { oo_reso_S_retain(v); } static inline void oo_release_OoResO_S(OoResO_S v) { oo_reso_S_release(v); }
typedef struct { OoIList *data; long long len; long long cap; } OoLL_I;
OoLL_I oo_ll_I_new(void); OoLL_I oo_ll_I_push(OoLL_I,OoIList);
OoIList oo_ll_I_get(OoLL_I,long long); long long oo_ll_I_len(OoLL_I);
void oo_ll_I_release(OoLL_I); void oo_ll_I_retain(OoLL_I);
OoLL_I oo_ll_I_set(OoLL_I,long long,OoIList);
typedef struct { OoSList *data; long long len; long long cap; } OoLL_S;
OoLL_S oo_ll_S_new(void); OoLL_S oo_ll_S_push(OoLL_S,OoSList);
OoSList oo_ll_S_get(OoLL_S,long long); long long oo_ll_S_len(OoLL_S);
void oo_ll_S_release(OoLL_S); void oo_ll_S_retain(OoLL_S);
OoLL_S oo_ll_S_set(OoLL_S,long long,OoSList);
typedef struct { OoFList *data; long long len; long long cap; } OoLL_F;
OoLL_F oo_ll_F_new(void); OoLL_F oo_ll_F_push(OoLL_F,OoFList);
OoFList oo_ll_F_get(OoLL_F,long long); long long oo_ll_F_len(OoLL_F);
void oo_ll_F_release(OoLL_F); void oo_ll_F_retain(OoLL_F);
OoLL_F oo_ll_F_set(OoLL_F,long long,OoFList);
typedef struct { OoLL_I *data; long long len; long long cap; } OoLLL_I;
OoLLL_I oo_lll_I_new(void); OoLLL_I oo_lll_I_push(OoLLL_I,OoLL_I);
OoLL_I oo_lll_I_get(OoLLL_I,long long); long long oo_lll_I_len(OoLLL_I);
void oo_lll_I_release(OoLLL_I); void oo_lll_I_retain(OoLLL_I);
typedef struct { OoLL_S *data; long long len; long long cap; } OoLLL_S;
OoLLL_S oo_lll_S_new(void); OoLLL_S oo_lll_S_push(OoLLL_S,OoLL_S);
OoLL_S oo_lll_S_get(OoLLL_S,long long); long long oo_lll_S_len(OoLLL_S);
void oo_lll_S_release(OoLLL_S); void oo_lll_S_retain(OoLLL_S);
typedef struct { OoLL_F *data; long long len; long long cap; } OoLLL_F; OoLLL_F oo_lll_F_new(void); OoLLL_F oo_lll_F_push(OoLLL_F,OoLL_F); OoLL_F oo_lll_F_get(OoLLL_F,long long); long long oo_lll_F_len(OoLLL_F); void oo_lll_F_release(OoLLL_F); void oo_lll_F_retain(OoLLL_F);
typedef struct { OoLLL_I *data; long long len; long long cap; } OoLLLL_I; OoLLLL_I oo_llll_I_new(void); OoLLLL_I oo_llll_I_push(OoLLLL_I,OoLLL_I); OoLLL_I oo_llll_I_get(OoLLLL_I,long long); long long oo_llll_I_len(OoLLLL_I); void oo_llll_I_release(OoLLLL_I); void oo_llll_I_retain(OoLLLL_I);
typedef struct { OoLLL_S *data; long long len; long long cap; } OoLLLL_S; OoLLLL_S oo_llll_S_new(void); OoLLLL_S oo_llll_S_push(OoLLLL_S,OoLLL_S); OoLLL_S oo_llll_S_get(OoLLLL_S,long long); long long oo_llll_S_len(OoLLLL_S); void oo_llll_S_release(OoLLLL_S); void oo_llll_S_retain(OoLLLL_S);
typedef struct { OoLLL_F *data; long long len; long long cap; } OoLLLL_F; OoLLLL_F oo_llll_F_new(void); OoLLLL_F oo_llll_F_push(OoLLLL_F,OoLLL_F); OoLLL_F oo_llll_F_get(OoLLLL_F,long long); long long oo_llll_F_len(OoLLLL_F); void oo_llll_F_release(OoLLLL_F); void oo_llll_F_retain(OoLLLL_F);
typedef struct { int ok; OoLLL_I val; OoStr err; } OoResLLL_I; typedef struct { int ok; int has_val; OoLLL_I val; OoStr err; } OoResO_LLL_I;
OoIList oo_ilist_set(OoIList,long long,long long); OoSList oo_slist_set(OoSList,long long,OoStr); OoFList oo_flist_set(OoFList,long long,double);
OoStr oo_str_lit(const char*); OoStr oo_str_concat(OoStr,OoStr);
OoStr oo_str_concat_list(OoSList); OoStr oo_str_concat_multi(int, ...);
OoStr oo_str_xor_lit(const unsigned char*,long long,long long);
OoStr oo_chr(long long);
long long oo_str_byte_len(OoStr); long long oo_chars_len(OoStr);
OoStr oo_char_at(OoStr,long long); OoStr oo_str_slice(OoStr,long long,long long);
OoStr oo_tok_line(OoStr,long long,long long,OoStr);
void oo_emit_tmp_reset(void); void oo_emit_tmp_enter(void);
void oo_emit_tmp_leave(void); void oo_emit_tmp_release_print(void);
void oo_emit_tmp_own(OoStr); void oo_emit_tmp_release_all_print(void);
OoStr oo_emit_tmp_bind(OoStr);
int oo_str_contains(OoStr,OoStr);
int oo_char_is_digit(OoStr); int oo_char_is_alpha(OoStr); int oo_char_is_space(OoStr);
OoIList oo_ilist_new(void); OoIList oo_ilist_push(OoIList,long long); void oo_ilist_free(OoIList);
long long oo_ilist_get(OoIList,long long); long long oo_ilist_len(OoIList);
void oo_str_retain(OoStr); void oo_str_release(OoStr);
void oo_slist_retain(OoSList); void oo_slist_release(OoSList);
void oo_ilist_retain(OoIList); void oo_ilist_release(OoIList);
OoSList oo_slist_new(void); OoSList oo_slist_push(OoSList,OoStr); void oo_slist_free(OoSList);
OoStr oo_slist_get(OoSList,long long); long long oo_slist_len(OoSList);
OoFList oo_flist_new(void); OoFList oo_flist_push(OoFList,double);
double oo_flist_get(OoFList,long long); long long oo_flist_len(OoFList);
void oo_flist_retain(OoFList); void oo_flist_release(OoFList);
static inline void oo_retain_I(long long v) { } static inline void oo_release_I(long long v) { }
static inline void oo_retain_F(double v) { } static inline void oo_release_F(double v) { }
static inline void oo_retain_B(int v) { } static inline void oo_release_B(int v) { }
static inline void oo_retain_V(void) { } static inline void oo_release_V(void) { }
static inline void oo_retain_S(OoStr v) { oo_str_retain(v); } static inline void oo_release_S(OoStr v) { oo_str_release(v); }
static inline void oo_retain_OoStr(OoStr v) { oo_str_retain(v); } static inline void oo_release_OoStr(OoStr v) { oo_str_release(v); }
static inline void oo_retain_OoFList(OoFList v) { oo_flist_retain(v); } static inline void oo_release_OoFList(OoFList v) { oo_flist_release(v); }
static inline void oo_retain_OoIList(OoIList v) { oo_ilist_retain(v); } static inline void oo_release_OoIList(OoIList v) { oo_ilist_release(v); }
static inline void oo_retain_OoSList(OoSList v) { oo_slist_retain(v); } static inline void oo_release_OoSList(OoSList v) { oo_slist_release(v); }
static inline void oo_retain_OoLL_I(OoLL_I v) { if (v.data) { OoListHeader *h = ((OoListHeader*)v.data)-1; __atomic_fetch_add(&h->ref_count, 1, __ATOMIC_ACQ_REL); } } static inline void oo_release_OoLL_I(OoLL_I v) { oo_ll_I_release(v); }
static inline void oo_retain_OoLL_S(OoLL_S v) { if (v.data) { OoListHeader *h = ((OoListHeader*)v.data)-1; __atomic_fetch_add(&h->ref_count, 1, __ATOMIC_ACQ_REL); } } static inline void oo_release_OoLL_S(OoLL_S v) { oo_ll_S_release(v); }
static inline void oo_retain_OoLL_F(OoLL_F v) { if (v.data) { OoListHeader *h = ((OoListHeader*)v.data)-1; __atomic_fetch_add(&h->ref_count, 1, __ATOMIC_ACQ_REL); } } static inline void oo_release_OoLL_F(OoLL_F v) { oo_ll_F_release(v); }
static inline void oo_retain_OoLLL_I(OoLLL_I v) { if (v.data) { OoListHeader *h = ((OoListHeader*)v.data)-1; __atomic_fetch_add(&h->ref_count, 1, __ATOMIC_ACQ_REL); } } static inline void oo_release_OoLLL_I(OoLLL_I v) { oo_lll_I_release(v); }
static inline void oo_retain_OoLLL_S(OoLLL_S v) { if (v.data) { OoListHeader *h = ((OoListHeader*)v.data)-1; __atomic_fetch_add(&h->ref_count, 1, __ATOMIC_ACQ_REL); } } static inline void oo_release_OoLLL_S(OoLLL_S v) { oo_lll_S_release(v); }
static inline void oo_retain_OoLLL_F(OoLLL_F v) { if (v.data) { OoListHeader *h = ((OoListHeader*)v.data)-1; __atomic_fetch_add(&h->ref_count, 1, __ATOMIC_ACQ_REL); } } static inline void oo_release_OoLLL_F(OoLLL_F v) { oo_lll_F_release(v); }
static inline void oo_retain_OoLLLL_I(OoLLLL_I v) { if (v.data) { OoListHeader *h = ((OoListHeader*)v.data)-1; __atomic_fetch_add(&h->ref_count, 1, __ATOMIC_ACQ_REL); } } static inline void oo_release_OoLLLL_I(OoLLLL_I v) { oo_llll_I_release(v); }
static inline void oo_retain_OoLLLL_S(OoLLLL_S v) { if (v.data) { OoListHeader *h = ((OoListHeader*)v.data)-1; __atomic_fetch_add(&h->ref_count, 1, __ATOMIC_ACQ_REL); } } static inline void oo_release_OoLLLL_S(OoLLLL_S v) { oo_llll_S_release(v); }
static inline void oo_retain_OoLLLL_F(OoLLLL_F v) { if (v.data) { OoListHeader *h = ((OoListHeader*)v.data)-1; __atomic_fetch_add(&h->ref_count, 1, __ATOMIC_ACQ_REL); } } static inline void oo_release_OoLLLL_F(OoLLLL_F v) { oo_llll_F_release(v); }
long long oo_cap_grant_fs(void); long long oo_cap_grant_sys(void); long long oo_cap_grant_env(void); long long oo_cap_grant_net(void);
long long oo_cap_grant_time(void); long long oo_cap_grant_rand(void); long long oo_cap_grant_alloc(void); long long oo_cap_grant_arena(void); long long oo_cap_grant_ffi(void);
long long oo_cap_grant_thread(void); long long oo_cap_grant_gpu(void); long long oo_cap_grant_compiler_read(void);
long long oo_cap_grant_http(void); long long oo_cap_grant_tcp(void); long long oo_cap_grant_udp(void); long long oo_cap_grant_bind(void);
long long oo_cap_grant_fsread(void); long long oo_cap_grant_fswrite(void); long long oo_cap_grant_process(void); long long oo_cap_grant_sync(void);
long long oo_cap_grant_mem(void); long long oo_cap_grant_sign(void); long long oo_cap_grant_audio(void); long long oo_cap_grant_camera(void);
long long oo_cap_grant_usb(void); long long oo_cap_grant_hid(void); long long oo_cap_grant_window(void); long long oo_cap_grant_frame(void);
OoResS oo_dlopen(long long,OoStr); OoResS oo_dlsym(long long,OoStr,OoStr);
OoResS oo_dlclose(long long,OoStr);
OoStr crypto_md5_internal(OoStr); OoStr crypto_sha1_internal(OoStr);
OoStr crypto_aes_encrypt_internal(OoStr,OoStr);
long long oo_byte_at(OoStr,long long); long long oo_str_byte_at(OoStr,long long); long long oo_bytes_len(OoStr);
long long oo_limb_add(long long,long long,long long,long long*); long long oo_limb_sub(long long,long long,long long,long long*);
long long oo_limb_mul(long long,long long,long long,long long*); long long oo_limb_div(long long,long long,long long,long long*); long long oo_limb_cmp(long long,long long);
OoStr oo_byte_slice(OoStr,long long,long long); int oo_bytes_eq(OoStr,OoStr);
OoStr oo_bytes_from_str(OoStr); OoStr oo_bytes_concat(OoStr,OoStr);
OoIList oo_bytes_new(void); OoIList oo_bytes_push(OoIList,long long);
long long oo_bytes_get(OoIList,long long); OoStr oo_bytes_to_str(OoIList);
OoResS oo_tcp_bind(long long,long long); OoResS oo_tcp_connect(long long,OoStr,long long);
OoResS oo_tcp_accept(long long,long long);
OoResS oo_bind_udp(long long,long long); OoResS oo_tls_connect(long long,OoStr,long long);
OoResS oo_tcp_write(long long,long long,OoStr); OoResS oo_tcp_read(long long,long long,long long);
OoResS oo_udp_recv(long long,long long,long long); OoResS oo_tcp_close(long long,long long);
OoResS oo_udp_send(long long,long long,OoStr,long long,OoStr);
OoResS oo_sock_raw(long long,long long);
OoResS oo_sys_spawn(long long,OoStr); OoResS oo_sys_wait(long long,long long);
OoResS oo_sys_kill(long long,long long,long long);
OoSList sys_args(long long);
#define chars_len oo_chars_len
OoResS oo_sys_epoll_create(long long,long long); OoResS oo_sys_inotify_init(long long);
OoResS oo_sys_prctl(long long,long long);
OoResS oo_mutex_lock(long long,long long); OoResS oo_mutex_unlock(long long,long long);
OoResS oo_thread_spawn(long long,OoStr); OoResS oo_thread_join(long long,long long);
OoResS oo_thread_join_s(long long,OoStr); OoResS oo_gpu_launch(long long,OoStr);
OoResS oo_channel_new(long long); OoResS oo_channel_send(long long,long long,OoStr);
OoResS oo_channel_recv(long long,long long);
OoResS oo_actor_spawn(long long,OoStr); OoResS oo_actor_send(long long,long long,OoStr);
OoResS oo_actor_recv(long long,long long);
const char *oo_process_policy_getenv(const char*);
long long oo_now_ms(long long); void oo_sleep_ms(long long,long long);
long long oo_random(long long); void oo_seed(long long,long long);
long long oo_alloc_bytes(long long,long long); void oo_free_bytes(long long,long long);
long long oo_alloc(long long); void oo_free(long long); void (oo_write_int)(long long,long long,long long); long long (oo_read_int)(long long,long long); long long heap_alloc_test(void);
#ifndef oo_write_int
#define OO_WRITE_INT_GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define oo_write_int_2(p, v) (oo_write_int)((p), 0LL, (v))
#define oo_write_int_3(p, o, v) (oo_write_int)((p), (o), (v))
#define oo_write_int(...) OO_WRITE_INT_GET_MACRO(__VA_ARGS__, oo_write_int_3, oo_write_int_2)(__VA_ARGS__)
#endif
#ifndef oo_read_int
#define OO_READ_INT_GET_MACRO(_1, _2, NAME, ...) NAME
#define oo_read_int_1(p) (oo_read_int)((p), 0LL)
#define oo_read_int_2(p, o) (oo_read_int)((p), (o))
#define oo_read_int(...) OO_READ_INT_GET_MACRO(__VA_ARGS__, oo_read_int_2, oo_read_int_1)(__VA_ARGS__)
#endif
long long oo_meta_epoch(void);
long long oo_meta_mix(long long);
int oo_meta_is_path_a(void);
void oo_meta_decoy_touch(void);
void oo_cap_require(long long,long long,const char*);
OoResS oo_read_file(long long,OoStr); OoResV oo_write_file(long long,OoStr,OoStr);
int oo_path_exists(long long,OoStr); long long oo_file_size(long long,OoStr); OoResS oo_env_get(long long,OoStr);
OoResS oo_sys_exec(long long,int,OoStr*);
OoSList oo_sys_args(long long);
OoSList oo_fs_read_dir(long long,OoStr); int oo_fs_is_dir(long long,OoStr);
OoResV oo_fs_remove_file(long long,OoStr); OoResV oo_fs_rmdir(long long,OoStr); OoResV oo_fs_mkdir(long long,OoStr);
OoResV oo_fs_hardlink(long long,OoStr,OoStr); OoResV oo_fs_symlink(long long,OoStr,OoStr);
OoResS oo_rlimit_set_mem_mb(long long,long long); OoResS oo_rlimit_set_nofile(long long,long long); OoResS oo_rlimit_set_cpu_sec(long long,long long);
OoResS oo_arena_create(long long,long long); OoResS oo_arena_alloc(long long,long long,long long); OoResS oo_arena_reset(long long,long long);
long long oo_soa_layout(OoStr); long long oo_dod_layout(long long); long long oo_checkpoint(long long); long long oo_rollback(void);
OoResS oo_actor_restart(long long,long long); OoResS oo_otp_supervise(long long,long long);
OoResS oo_cap_rpc_send(long long,OoStr); OoResS oo_cap_rpc_recv(long long,OoStr);
OoStr oo_read_stdin(void); OoResS oo_read_stdin_chunk(long long); OoStr oo_file_stamp(OoStr);
OoStr oo_str_macro_expand(OoStr); OoStr oo_str_ast_macro(OoStr);
long long oo_import_c(long long,OoStr); long long oo_ffi_gen(long long,OoStr); long long oo_lto_xlang_link(long long,OoStr,OoStr);
int oo_landlock_is_available(void); OoResS oo_landlock_restrict(long long,OoStr,OoStr);
OoResS oo_dns_resolve(long long,OoStr); OoResS oo_dns_resolve_ipv4(long long,OoStr);
OoResS oo_proc_mem_read(long long,long long,long long);
OoResS oo_fetch(long long,OoStr);
void oo_print_str(OoStr); void oo_eprint_str(OoStr); void oo_print_int(long long); void oo_print_bool(int); void oo_print_double(double); void oo_println(void); void oo_eprintln(void);
double oo_sin(double); double oo_cos(double); double oo_ln(double);
double oo_exp(double); double oo_sqrt(double); double oo_pow(double,double);
int oo_str_eq(OoStr,OoStr); int oo_str_contains(OoStr,OoStr);
OoSList str_split(OoStr,OoStr);
OoStr oo_int_to_str(long long); OoStr str_trim(OoStr); OoStr oo_str_trim(OoStr); OoStr oo_str_to_lowercase(OoStr);
OoStr oo_str_to_uppercase(OoStr); int oo_str_starts_with(OoStr,OoStr); int oo_str_ends_with(OoStr,OoStr);
long long oo_str_index_of(OoStr,OoStr); OoStr oo_str_repeat(OoStr,long long);
typedef struct { long long kind; OoStr text; } Token;
static inline long long oo_str_to_int(OoStr s) { return s.data ? atoll(s.data) : 0LL; }
static inline long long oo_str_len(OoStr s) { return s.data ? (long long)strlen(s.data) : 0LL; }
static inline void oo_process_exit(long long c) { exit((int)c); }
static inline void oo_assert_eq_str(OoStr a, OoStr b) { if (!oo_str_eq(a, b)) { fprintf(stderr, "Assertion failed: assert_eq\n"); exit(1); } }
static inline void oo_assert_eq_long(long long a, long long b) { if (a != b) { fprintf(stderr, "Assertion failed: assert_eq\n"); exit(1); } }
static inline void oo_assert_eq_double(double a, double b) { if (a != b) { fprintf(stderr, "Assertion failed: assert_eq\n"); exit(1); } }
static inline int oo_res_eq(OoResS a, OoResS b) { return a.ok == b.ok && oo_str_eq(a.val, b.val); }
static inline int oo_res_eq_i(OoResI a, OoResI b) { return a.ok == b.ok && (a.ok ? a.val == b.val : oo_str_eq(a.err, b.err)); }
static inline void oo_assert_eq_ress(OoResS a, OoResS b) { if (!oo_res_eq(a, b)) { fprintf(stderr, "Assertion failed: assert_eq\n"); exit(1); } }
#define oo_assert_eq(a, b) _Generic((a), OoStr: oo_assert_eq_str, OoResS: oo_assert_eq_ress, double: oo_assert_eq_double, float: oo_assert_eq_double, default: oo_assert_eq_long)((a), (b))
#define assert_eq(a, b) oo_assert_eq(a, b)
static inline void oo_assert_ne_str(OoStr a, OoStr b) { if (oo_str_eq(a, b)) { fprintf(stderr, "Assertion failed: assert_ne\n"); exit(1); } }
static inline void oo_assert_ne_long(long long a, long long b) { if (a == b) { fprintf(stderr, "Assertion failed: assert_ne\n"); exit(1); } }
static inline void oo_assert_ne_double(double a, double b) { if (a == b) { fprintf(stderr, "Assertion failed: assert_ne\n"); exit(1); } }
static inline void oo_assert_ne_ress(OoResS a, OoResS b) { if (oo_res_eq(a, b)) { fprintf(stderr, "Assertion failed: assert_ne\n"); exit(1); } }
#define oo_assert_ne(a, b) _Generic((a), OoStr: oo_assert_ne_str, OoResS: oo_assert_ne_ress, double: oo_assert_ne_double, float: oo_assert_ne_double, default: oo_assert_ne_long)((a), (b))
#define assert_ne(a, b) oo_assert_ne(a, b)
#define oo_assert(a) do { if (!(a)) { fprintf(stderr, "Assertion failed: assert\n"); exit(1); } } while(0)
#define assert(a) oo_assert(a)
OoStr crypto_sha256_internal(OoStr); OoStr crypto_sha512_internal(OoStr); OoStr crypto_hmac_sha256_internal(OoStr,OoStr);
OoStr crypto_sha3_256_internal(OoStr);
OoStr crypto_aes_gcm_seal_internal(OoStr,OoStr,OoStr,OoStr); OoStr crypto_aes_gcm_open_internal(OoStr,OoStr,OoStr,OoStr,OoStr);
OoStr crypto_chacha20poly1305_seal_internal(OoStr,OoStr,OoStr,OoStr); OoStr crypto_chacha20poly1305_open_internal(OoStr,OoStr,OoStr,OoStr,OoStr);
OoStr crypto_mlkem768_keygen_internal(OoStr); OoStr crypto_mlkem768_encaps_internal(OoStr,OoStr); OoStr crypto_mlkem768_decaps_internal(OoStr,OoStr);
OoStr crypto_mldsa65_keygen_internal(OoStr); OoStr crypto_mldsa65_sign_internal(OoStr,OoStr,OoStr); OoStr crypto_mldsa65_verify_internal(OoStr,OoStr,OoStr);
OoStr cap_attenuate(OoStr,OoStr); int cap_attenuate_ok(OoStr,OoStr);
OoStr oo_cap_attenuate(OoStr,OoStr); int oo_cap_attenuate_ok(OoStr,OoStr);
OoStr oo_cap_kernel_seal(long long,OoStr); OoStr oo_enclave_enter(long long,OoStr);
OoResS json_parse_internal(OoStr); OoStr json_stringify_internal(OoStr);
OoResS python_embed_internal(long long,OoStr);
/* CAP-G5 residual: no product seccomp-bpf floor (process-local caps only) */
long long bf_mask(long long x);
long long bf_rotl(long long x, long long r);
__attribute__((cold, noinline)) long long bloom_filter_murmur3(long long key, long long seed);
__attribute__((cold, noinline)) OoResLI bloom_filter_new(long long mbits, long long k);
long long bf_bit(OoIList bf, long long key, long long hi);
__attribute__((cold, noinline)) OoResLI bloom_filter_add(OoIList bf, long long key);
__attribute__((cold, noinline)) OoResB bloom_filter_has(OoIList bf, long long key);
#line 1 "std/collections/advanced/bloom_filter.oo"
#line 1 "std/collections/advanced/bloom_filter.oo"

#line 13 "std/collections/advanced/bloom_filter.oo"
#ifndef OO_FN_bf_mask
#define OO_FN_bf_mask
long long bf_mask(long long x) {
#undef OO_ENS_CHECK
#define OO_ENS_CHECK(result) (1)
#line 13 "std/collections/advanced/bloom_filter.oo" /* col 29 */
  long long __ret_val = (x & 4294967295LL);
  return __ret_val;
}
#endif

#line 15 "std/collections/advanced/bloom_filter.oo"
#ifndef OO_FN_bf_rotl
#define OO_FN_bf_rotl
long long bf_rotl(long long x, long long r) {
#undef OO_ENS_CHECK
#define OO_ENS_CHECK(result) (1)
#line 16 "std/collections/advanced/bloom_filter.oo" /* col 5 */
  long long v_lvl2 = bf_mask(x);
#line 17 "std/collections/advanced/bloom_filter.oo" /* col 5 */
  long long __ret_val = bf_mask((((v_lvl2 << r)) | ((v_lvl2 >> ((32LL - r))))));
  return __ret_val;
}
#endif

#line 20 "std/collections/advanced/bloom_filter.oo"
#ifndef OO_FN_bloom_filter_murmur3
#define OO_FN_bloom_filter_murmur3
__attribute__((cold, noinline)) long long bloom_filter_murmur3(long long key, long long seed) {
#undef OO_ENS_CHECK
#define OO_ENS_CHECK(result) (1)
#line 21 "std/collections/advanced/bloom_filter.oo" /* col 5 */
  long long k_lvl2 = bf_mask(key);
#line 22 "std/collections/advanced/bloom_filter.oo" /* col 5 */
#line 22 "std/collections/advanced/bloom_filter.oo" /* col 5 */
  k_lvl2 = bf_mask((k_lvl2 * 3432918353LL));
#line 23 "std/collections/advanced/bloom_filter.oo" /* col 5 */
#line 23 "std/collections/advanced/bloom_filter.oo" /* col 5 */
  k_lvl2 = bf_rotl(k_lvl2, 15LL);
#line 24 "std/collections/advanced/bloom_filter.oo" /* col 5 */
#line 24 "std/collections/advanced/bloom_filter.oo" /* col 5 */
  k_lvl2 = bf_mask((k_lvl2 * 461845907LL));
#line 25 "std/collections/advanced/bloom_filter.oo" /* col 5 */
  long long h_lvl2 = (bf_mask(seed) ^ k_lvl2);
#line 26 "std/collections/advanced/bloom_filter.oo" /* col 5 */
#line 26 "std/collections/advanced/bloom_filter.oo" /* col 5 */
  h_lvl2 = bf_rotl(h_lvl2, 13LL);
#line 27 "std/collections/advanced/bloom_filter.oo" /* col 5 */
#line 27 "std/collections/advanced/bloom_filter.oo" /* col 5 */
  h_lvl2 = bf_mask(((h_lvl2 * 5LL) + 3864294244LL));
#line 28 "std/collections/advanced/bloom_filter.oo" /* col 5 */
#line 28 "std/collections/advanced/bloom_filter.oo" /* col 5 */
  h_lvl2 = (h_lvl2 ^ 4LL);
#line 29 "std/collections/advanced/bloom_filter.oo" /* col 5 */
#line 29 "std/collections/advanced/bloom_filter.oo" /* col 5 */
  h_lvl2 = (h_lvl2 ^ ((h_lvl2 >> 16LL)));
#line 30 "std/collections/advanced/bloom_filter.oo" /* col 5 */
#line 30 "std/collections/advanced/bloom_filter.oo" /* col 5 */
  h_lvl2 = bf_mask((h_lvl2 * 2246822507LL));
#line 31 "std/collections/advanced/bloom_filter.oo" /* col 5 */
#line 31 "std/collections/advanced/bloom_filter.oo" /* col 5 */
  h_lvl2 = (h_lvl2 ^ ((h_lvl2 >> 13LL)));
#line 32 "std/collections/advanced/bloom_filter.oo" /* col 5 */
#line 32 "std/collections/advanced/bloom_filter.oo" /* col 5 */
  h_lvl2 = bf_mask((h_lvl2 * 3266489909LL));
#line 33 "std/collections/advanced/bloom_filter.oo" /* col 5 */
#line 33 "std/collections/advanced/bloom_filter.oo" /* col 5 */
  h_lvl2 = (h_lvl2 ^ ((h_lvl2 >> 16LL)));
#line 34 "std/collections/advanced/bloom_filter.oo" /* col 5 */
  long long __ret_val = bf_mask(h_lvl2);
  return __ret_val;
}
#endif

#line 37 "std/collections/advanced/bloom_filter.oo"
#ifndef OO_FN_bloom_filter_new
#define OO_FN_bloom_filter_new
__attribute__((cold, noinline)) OoResLI bloom_filter_new(long long mbits, long long k) {
#undef OO_ENS_CHECK
#define OO_ENS_CHECK(result) (1)
#line 38 "std/collections/advanced/bloom_filter.oo" /* col 5 */
if (__builtin_expect_with_probability(((mbits < 8LL)), 1, 0.95)) {
#line 38 "std/collections/advanced/bloom_filter.oo" /* col 20 */
  OoResLI __ret_val = ((OoResLI){0, oo_ilist_new(), oo_str_lit("bloom m")});
  if (__ret_val.ok) { oo_ilist_retain(__ret_val.val); } else { oo_str_retain(__ret_val.err); } 
  return __ret_val;
}
#line 39 "std/collections/advanced/bloom_filter.oo" /* col 5 */
if (__builtin_expect_with_probability(((k < 1LL)), 1, 0.95)) {
#line 39 "std/collections/advanced/bloom_filter.oo" /* col 16 */
  OoResLI __ret_val = ((OoResLI){0, oo_ilist_new(), oo_str_lit("bloom k")});
  if (__ret_val.ok) { oo_ilist_retain(__ret_val.val); } else { oo_str_retain(__ret_val.err); } 
  return __ret_val;
}
#line 40 "std/collections/advanced/bloom_filter.oo" /* col 5 */
if ((k > 16LL)) {
#line 40 "std/collections/advanced/bloom_filter.oo" /* col 17 */
  OoResLI __ret_val = ((OoResLI){0, oo_ilist_new(), oo_str_lit("bloom k")});
  if (__ret_val.ok) { oo_ilist_retain(__ret_val.val); } else { oo_str_retain(__ret_val.err); } 
  return __ret_val;
}
#line 41 "std/collections/advanced/bloom_filter.oo" /* col 5 */
  long long words_lvl2 = (((mbits + 31LL)) / 32LL);
#line 42 "std/collections/advanced/bloom_filter.oo" /* col 5 */
  OoIList bf_lvl2 = oo_ilist_new();
#line 43 "std/collections/advanced/bloom_filter.oo" /* col 5 */
#line 43 "std/collections/advanced/bloom_filter.oo" /* col 5 */
  { OoIList __tmp = bf_lvl2; bf_lvl2 = oo_ilist_push(bf_lvl2, mbits); oo_ilist_release(__tmp); }
#line 44 "std/collections/advanced/bloom_filter.oo" /* col 5 */
#line 44 "std/collections/advanced/bloom_filter.oo" /* col 5 */
  { OoIList __tmp = bf_lvl2; bf_lvl2 = oo_ilist_push(bf_lvl2, k); oo_ilist_release(__tmp); }
#line 45 "std/collections/advanced/bloom_filter.oo" /* col 5 */
  long long i_lvl2 = 0LL;
#line 46 "std/collections/advanced/bloom_filter.oo" /* col 5 */
while (1) {
if (__builtin_expect_with_probability((!((i_lvl2 < words_lvl2))), 0, 0.95)) {
break;
}
#line 47 "std/collections/advanced/bloom_filter.oo" /* col 9 */
#line 47 "std/collections/advanced/bloom_filter.oo" /* col 9 */
  { OoIList __tmp = bf_lvl2; bf_lvl2 = oo_ilist_push(bf_lvl2, 0LL); oo_ilist_release(__tmp); }
#line 48 "std/collections/advanced/bloom_filter.oo" /* col 9 */
#line 48 "std/collections/advanced/bloom_filter.oo" /* col 9 */
  i_lvl2 = (i_lvl2 + 1LL);
}
#line 50 "std/collections/advanced/bloom_filter.oo" /* col 5 */
  OoResLI __ret_val = ((OoResLI){1, bf_lvl2, oo_str_lit("")});
  if (__ret_val.ok) { oo_ilist_retain(__ret_val.val); } else { oo_str_retain(__ret_val.err); } 
  oo_ilist_release(bf_lvl2); 
  return __ret_val;
  oo_ilist_release(bf_lvl2); 
}
#endif

#line 53 "std/collections/advanced/bloom_filter.oo"
#ifndef OO_FN_bf_bit
#define OO_FN_bf_bit
long long bf_bit(OoIList bf, long long key, long long hi) {
  int __bf_null = (bf.data == NULL);
#undef OO_ENS_CHECK
#define OO_ENS_CHECK(result) (1)
#line 54 "std/collections/advanced/bloom_filter.oo" /* col 5 */
  long long m_lvl2 = oo_ilist_get(bf, 0LL);
#line 55 "std/collections/advanced/bloom_filter.oo" /* col 5 */
  long long h_lvl2 = bloom_filter_murmur3(key, (2654435761LL + (hi * 9749LL)));
#line 56 "std/collections/advanced/bloom_filter.oo" /* col 5 */
  long long idx_lvl2 = (h_lvl2 % m_lvl2);
#line 57 "std/collections/advanced/bloom_filter.oo" /* col 5 */
if (__builtin_expect_with_probability(((idx_lvl2 < 0LL)), 1, 0.95)) {
#line 57 "std/collections/advanced/bloom_filter.oo" /* col 18 */
#line 57 "std/collections/advanced/bloom_filter.oo" /* col 18 */
  idx_lvl2 = (0LL - idx_lvl2);
}
#line 58 "std/collections/advanced/bloom_filter.oo" /* col 5 */
  long long __ret_val = (idx_lvl2 % m_lvl2);
  return __ret_val;
}
#endif

#line 61 "std/collections/advanced/bloom_filter.oo"
#ifndef OO_FN_bloom_filter_add
#define OO_FN_bloom_filter_add
__attribute__((cold, noinline)) OoResLI bloom_filter_add(OoIList bf, long long key) {
  int __bf_null = (bf.data == NULL);
#undef OO_ENS_CHECK
#define OO_ENS_CHECK(result) (1)
#line 62 "std/collections/advanced/bloom_filter.oo" /* col 5 */
if (__builtin_expect_with_probability(((oo_ilist_len(bf) < 3LL)), 1, 0.95)) {
#line 62 "std/collections/advanced/bloom_filter.oo" /* col 27 */
  OoResLI __ret_val = ((OoResLI){0, oo_ilist_new(), oo_str_lit("bloom short")});
  if (__ret_val.ok) { oo_ilist_retain(__ret_val.val); } else { oo_str_retain(__ret_val.err); } 
  return __ret_val;
}
#line 63 "std/collections/advanced/bloom_filter.oo" /* col 5 */
  long long k_lvl2 = oo_ilist_get(bf, 1LL);
#line 64 "std/collections/advanced/bloom_filter.oo" /* col 5 */
  OoIList o_lvl2 = bf;
  oo_ilist_retain(o_lvl2); 
#line 65 "std/collections/advanced/bloom_filter.oo" /* col 5 */
  long long hi_lvl2 = 0LL;
#line 66 "std/collections/advanced/bloom_filter.oo" /* col 5 */
while (1) {
if (__builtin_expect_with_probability((!((hi_lvl2 < k_lvl2))), 0, 0.95)) {
break;
}
#line 67 "std/collections/advanced/bloom_filter.oo" /* col 9 */
  long long idx_lvl3 = bf_bit(o_lvl2, key, hi_lvl2);
#line 68 "std/collections/advanced/bloom_filter.oo" /* col 9 */
  long long w_lvl3 = (2LL + (idx_lvl3 / 32LL));
#line 69 "std/collections/advanced/bloom_filter.oo" /* col 9 */
  long long b_lvl3 = (idx_lvl3 % 32LL);
#line 70 "std/collections/advanced/bloom_filter.oo" /* col 9 */
  long long cur_lvl3 = oo_ilist_get(o_lvl2, w_lvl3);
#line 71 "std/collections/advanced/bloom_filter.oo" /* col 9 */
#line 71 "std/collections/advanced/bloom_filter.oo" /* col 9 */
  { OoIList __tmp = o_lvl2; o_lvl2 = oo_ilist_set(o_lvl2, w_lvl3, (cur_lvl3 | ((1LL << b_lvl3)))); oo_ilist_release(__tmp); }
#line 72 "std/collections/advanced/bloom_filter.oo" /* col 9 */
#line 72 "std/collections/advanced/bloom_filter.oo" /* col 9 */
  hi_lvl2 = (hi_lvl2 + 1LL);
}
#line 74 "std/collections/advanced/bloom_filter.oo" /* col 5 */
  OoResLI __ret_val = ((OoResLI){1, o_lvl2, oo_str_lit("")});
  if (__ret_val.ok) { oo_ilist_retain(__ret_val.val); } else { oo_str_retain(__ret_val.err); } 
  oo_ilist_release(o_lvl2); 
  return __ret_val;
  oo_ilist_release(o_lvl2); 
}
#endif

#line 77 "std/collections/advanced/bloom_filter.oo"
#ifndef OO_FN_bloom_filter_has
#define OO_FN_bloom_filter_has
__attribute__((cold, noinline)) OoResB bloom_filter_has(OoIList bf, long long key) {
  int __bf_null = (bf.data == NULL);
#undef OO_ENS_CHECK
#define OO_ENS_CHECK(result) (1)
#line 78 "std/collections/advanced/bloom_filter.oo" /* col 5 */
if (__builtin_expect_with_probability(((oo_ilist_len(bf) < 3LL)), 1, 0.95)) {
#line 78 "std/collections/advanced/bloom_filter.oo" /* col 27 */
  OoResB __ret_val = ((OoResB){0, 0, oo_str_lit("bloom short")});
  if (!__ret_val.ok) { oo_str_retain(__ret_val.err); } 
  return __ret_val;
}
#line 79 "std/collections/advanced/bloom_filter.oo" /* col 5 */
  long long k_lvl2 = oo_ilist_get(bf, 1LL);
#line 80 "std/collections/advanced/bloom_filter.oo" /* col 5 */
  long long hi_lvl2 = 0LL;
#line 81 "std/collections/advanced/bloom_filter.oo" /* col 5 */
while (1) {
if (__builtin_expect_with_probability((!((hi_lvl2 < k_lvl2))), 0, 0.95)) {
break;
}
#line 82 "std/collections/advanced/bloom_filter.oo" /* col 9 */
  long long idx_lvl3 = bf_bit(bf, key, hi_lvl2);
#line 83 "std/collections/advanced/bloom_filter.oo" /* col 9 */
  long long w_lvl3 = (2LL + (idx_lvl3 / 32LL));
#line 84 "std/collections/advanced/bloom_filter.oo" /* col 9 */
  long long b_lvl3 = (idx_lvl3 % 32LL);
#line 85 "std/collections/advanced/bloom_filter.oo" /* col 9 */
if ((((oo_ilist_get(bf, w_lvl3) & ((1LL << b_lvl3)))) == 0LL)) {
#line 85 "std/collections/advanced/bloom_filter.oo" /* col 48 */
  OoResB __ret_val = ((OoResB){1, 0, oo_str_lit("")});
  if (!__ret_val.ok) { oo_str_retain(__ret_val.err); } 
  return __ret_val;
}
#line 86 "std/collections/advanced/bloom_filter.oo" /* col 9 */
#line 86 "std/collections/advanced/bloom_filter.oo" /* col 9 */
  hi_lvl2 = (hi_lvl2 + 1LL);
}
#line 88 "std/collections/advanced/bloom_filter.oo" /* col 5 */
  OoResB __ret_val = ((OoResB){1, 1, oo_str_lit("")});
  if (!__ret_val.ok) { oo_str_retain(__ret_val.err); } 
  return __ret_val;
}
#endif
