#include "tlshoujo/memory.h"

void shoujo_memory_wipe(void * const eval, const size_t len) {
    volatile uint8_t * volatile tmp = (volatile uint8_t * volatile) eval;
    size_t i                        = 0U;

    while (i < len) {
        tmp[i++] = 0x00;
    }
}

void shoujo_stack_wipe(const size_t len) {
    uint8_t tmp[len];
    shoujo_memory_wipe(tmp, len);
}
