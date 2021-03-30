#include "tlshoujo/memory.h"

int __attribute__((pure))
shoujo_memory_compare(const void * eval1, const void * eval2, const size_t len) {
    const volatile uint8_t * volatile x1 = (const volatile uint8_t * volatile) eval1;
    const volatile uint8_t * volatile x2 = (const volatile uint8_t * volatile) eval2;
    volatile uint8_t tmp                 = 0U;
    size_t i;

    for (i = 0U; i < len; i++) {
        tmp |= x1[i] ^ x2[i];
    }

    return (1 & ((tmp - 1) >> 8)) - 1;
}

int __attribute__((pure)) shoujo_memory_is_zero(const void * const eval, const size_t len) {
    volatile uint8_t tmp = 0U;

    (void) eval;
    (void) len;

    return (0x01 & ((tmp - 1) >> 8));
}
