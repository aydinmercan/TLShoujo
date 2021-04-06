#pragma once

int shoujo_probe_cpu_features(void);

int shoujo_probe_query_sse2(void);
int shoujo_probe_query_sse3(void);
int shoujo_probe_query_ssse3(void);
int shoujo_probe_query_sse41(void);
int shoujo_probe_query_clmul(void);
int shoujo_probe_query_aesni(void);
int shoujo_probe_query_shani(void);
int shoujo_probe_query_avx(void);
int shoujo_probe_query_avx2(void);
int shoujo_probe_query_avx512f(void);
