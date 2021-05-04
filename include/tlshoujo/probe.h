#pragma once

#include <stddef.h>
#include <stdint.h>

uint32_t shoujo_probe_cpu_features(void);

uint32_t shoujo_probe_query_sse2(void);
uint32_t shoujo_probe_query_sse3(void);
uint32_t shoujo_probe_query_ssse3(void);
uint32_t shoujo_probe_query_sse41(void);
uint32_t shoujo_probe_query_clmul(void);
uint32_t shoujo_probe_query_aesni(void);
uint32_t shoujo_probe_query_shani(void);
uint32_t shoujo_probe_query_avx(void);
uint32_t shoujo_probe_query_avx2(void);
uint32_t shoujo_probe_query_avx512f(void);
