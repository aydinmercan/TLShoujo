#include "tlshoujo/logic.h"
#include "tlshoujo/memory.h"

uint32_t shoujo_memory_compare(const void * eval1, const void * eval2, const size_t len) {
    const volatile uint8_t * volatile x1 = (const volatile uint8_t * volatile) eval1;
    const volatile uint8_t * volatile x2 = (const volatile uint8_t * volatile) eval2;
    volatile uint8_t ctl                 = 0U;
    size_t i;

    for (i = 0U; i < len; i++) {
        ctl |= (uint8_t) ((uint8_t) x1[i] ^ (uint8_t)x2[i]);
    }

    return shoujo_u8_is_zero(ctl);
}

uint32_t shoujo_memory_is_zero(const void * const eval, const size_t len) {
    const volatile uint8_t * volatile x = (const volatile uint8_t * volatile) eval;
    volatile uint8_t ctl                = 0U;
    size_t i;

    for (i = 0; i < len; i++) {
        ctl |= x[i];
    }
    return shoujo_u8_is_zero(ctl);
}
