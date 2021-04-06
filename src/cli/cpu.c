#include "cpu.h"

#include <stdio.h>
#include <tlshoujo.h>

static void __attribute__((always_inline)) _probe(int (*test)(void), const char * name) {
    printf("Querying %s... ", name);
    printf("%s\n", test() ? "FOUND" : "MISSING");
}

static void cmd_cpu_print_all(void) {
    _probe(shoujo_probe_query_sse2, "SSE2");
    _probe(shoujo_probe_query_sse3, "SSE3");
    _probe(shoujo_probe_query_ssse3, "SSSE3");
    _probe(shoujo_probe_query_sse41, "SSE4.1");
    _probe(shoujo_probe_query_clmul, "CLMUL");
    _probe(shoujo_probe_query_aesni, "AES-NI");
    _probe(shoujo_probe_query_shani, "SHA-NI");
    _probe(shoujo_probe_query_avx, "AVX");
    _probe(shoujo_probe_query_avx2, "AVX2");
}

int command_cpu(int argc, char ** argv) {
    (void) argc;
    (void) argv;

    cmd_cpu_print_all();

    return 0;
}
