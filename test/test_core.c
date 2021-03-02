#include <stdio.h>
#include <stdlib.h>
#include <tlshoujo.h>

static __attribute__((always_inline)) void _probe(int (*test)(void), const char * name) {
    printf("Querying %s... ", name);
    printf("%s\n", test() ? "FOUND" : "MISSING");
}

int main(int argc, char ** argv) {
    (void) argc;
    (void) argv;

    if (shoujo_init() < 0) {
        perror("init");
        exit(EXIT_FAILURE);
    }

    _probe(shoujo_probe_query_sse2, "SSE2");
    _probe(shoujo_probe_query_sse3, "SSE3");
    _probe(shoujo_probe_query_ssse3, "SSSE3");
    _probe(shoujo_probe_query_sse41, "SSE4.1");
    _probe(shoujo_probe_query_clmul, "CLMUL");
    _probe(shoujo_probe_query_aesni, "AES-NI");
    _probe(shoujo_probe_query_shani, "SHA-NI");
    _probe(shoujo_probe_query_avx, "AVX");
    _probe(shoujo_probe_query_avx2, "AVX2");

    return 0;
}
