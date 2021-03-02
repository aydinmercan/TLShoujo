#include "tlshoujo/probe.h"

#include <stdint.h>

#define FEAT_EBX_AVX2  (0x00000020)
#define FEAT_EBX_SHANI (0x20000000)

#define FEAT_ECX_SSE3    (0x00000001)
#define FEAT_ECX_CLMUL   (0x00000002)
#define FEAT_ECX_SSSE3   (0x00000200)
#define FEAT_ECX_SSE41   (0x00080000)
#define FEAT_ECX_AESNI   (0x02000000)
#define FEAT_ECX_XSAVE   (0x04000000)
#define FEAT_ECX_OSXSAVE (0x08000000)
#define FEAT_ECX_AVX     (0x10000000)
#define FEAT_ECX_RDRAND  (0x40000000)

#define FEAT_EDX_SSE2 (0x04000000)

#define XCR0_SSE       (0x00000002)
#define XCR0_AVX       (0x00000004)
#define XCR0_OPMASK    (0x00000020)
#define XCR0_ZMM_HI256 (0x00000040)
#define XCR0_HI16_ZMM  (0x00000080)

static int _sse2  = 0;
static int _sse3  = 0;
static int _ssse3 = 0;
static int _sse41 = 0;
static int _clmul = 0;
static int _aesni = 0;
static int _shani = 0;
static int _avx   = 0;
static int _avx2  = 0;

static void _cpuid(uint32_t info[static 4], const uint32_t type) {
    __asm__ volatile("xchgq %%rbx, %q1;"
                     "cpuid;"
                     "xchgq %%rbx, %q1;"
                     : "=a"(info[0]), "=&r"(info[1]), "=c"(info[2]), "=d"(info[3])
                     : "0"(type), "2"(0U));
}

int __attribute__((flatten)) shoujo_probe_cpu_features(void) {
    uint32_t info[4] = {0}, xcr0 = 0U, id = 0U;

    _cpuid(info, 0U);
    // eax
    id = info[0];
    if (id == 0U) {
        return -1;
    }

    _cpuid(info, 1U);

    _sse2  = ((info[3] & FEAT_EDX_SSE2) != 0x00);
    _sse3  = ((info[2] & FEAT_ECX_SSE3) != 0x00);
    _ssse3 = ((info[2] & FEAT_ECX_SSSE3) != 0x00);
    _sse41 = ((info[2] & FEAT_ECX_SSE41) != 0x00);

    _clmul = ((info[2] & FEAT_ECX_CLMUL) != 0x00);
    _aesni = ((info[2] & FEAT_ECX_AESNI) != 0x00);

    info[0] = info[1] = info[2] = info[3] = 0;

    _cpuid(info, 7U);

    _shani = ((info[1] & FEAT_EBX_SHANI) != 0x00);
    _avx2  = ((info[1] & FEAT_EBX_AVX2) != 0x00);

    (void) xcr0;

    return 0;
}

int shoujo_probe_query_sse2(void) {
    return _sse2;
}

int shoujo_probe_query_sse3(void) {
    return _sse3;
}

int shoujo_probe_query_ssse3(void) {
    return _ssse3;
}

int shoujo_probe_query_sse41(void) {
    return _sse41;
}

int shoujo_probe_query_clmul(void) {
    return _clmul;
}

int shoujo_probe_query_aesni(void) {
    return _aesni;
}

int shoujo_probe_query_shani(void) {
    return _shani;
}

int shoujo_probe_query_avx(void) {
    return _avx;
}

int shoujo_probe_query_avx2(void) {
    return _avx2;
}

#undef FEAT_EBX_AVX2
#undef FEAT_EBX_SHANI

#undef FEAT_ECX_SSE3
#undef FEAT_ECX_CLMUL
#undef FEAT_ECX_SSSE3
#undef FEAT_ECX_SSE41
#undef FEAT_ECX_AESNI
#undef FEAT_ECX_XSAVE
#undef FEAT_ECX_OSXSAVE
#undef FEAT_ECX_AVX
#undef FEAT_ECX_RDRAND

#undef FEAT_EDX_SSE2

#undef XCR0_SSE
#undef XCR0_AVX
#undef XCR0_OPMASK
#undef XCR0_ZMM_HI256
#undef XCR0_HI16_ZMM
