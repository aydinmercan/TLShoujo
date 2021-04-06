#include "tlshoujo/probe.h"

#include <stdint.h>

#include "config.h"

#define EAX (0)
#define EBX (1)
#define ECX (2)
#define EDX (3)

// clang-format off
#define CPU_DEFINE(name)                                      \
    static int _ ## name = 0;                                 \
    int shoujo_probe_query_ ## name(void) { return _##name; } \
    int shoujo_probe_query_ ## name(void) // Shitty hack for semicolon

#define CPU_QUERY(target, register, bitflag)                \
    do {                                                    \
        _ ## target = ((info[register] & bitflag) != 0x00); \
    } while (CPU_QUERY_COMPTIME_FLAG_ ## target)
// clang-format on

CPU_DEFINE(sse2);
CPU_DEFINE(sse3);
CPU_DEFINE(ssse3);
CPU_DEFINE(sse41);
CPU_DEFINE(clmul);
CPU_DEFINE(aesni);
CPU_DEFINE(shani);
CPU_DEFINE(avx);
CPU_DEFINE(avx2);
CPU_DEFINE(avx512f);

extern void _cpuid(uint32_t info[static 4], const uint32_t type);

int __attribute__((flatten)) shoujo_probe_cpu_features(void) {
    uint32_t info[4] = {0}, xcr0 = 0U, id = 0U;

    // Check if we can use CPUID properly
    _cpuid(info, 0U);
    id = info[EAX];
    if (id == 0U) {
        return -1;
    }

    // Reset and get feature bits
    info[0] = info[1] = info[2] = info[3] = 0;
    _cpuid(info, 1U);

    CPU_QUERY(sse2, EDX, 0x04000000);
    CPU_QUERY(sse3, ECX, 0x00000001);
    CPU_QUERY(ssse3, ECX, 0x00000200);
    CPU_QUERY(sse41, ECX, 0x0080000);
    CPU_QUERY(clmul, ECX, 0x00000002);
    CPU_QUERY(aesni, ECX, 0x02000000);
    CPU_QUERY(avx, ECX, 0x10000000);

    // Reset and get extended feature bits
    info[0] = info[1] = info[2] = info[3] = 0;
    _cpuid(info, 7U);

    CPU_QUERY(shani, EBX, 0x20000000);
    CPU_QUERY(avx2, EBX, 0x00000020);
    CPU_QUERY(avx512f, EBX, (1 << 16));

    (void) xcr0;

    return 0;
}

#undef EAX
#undef EBX
#undef ECX
#undef EDX

#undef CPU_QUERY
#undef CPU_DEFINE
