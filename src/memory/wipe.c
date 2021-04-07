#include "tlshoujo/memory.h"

// TODO: document extensively about why memory "wiping" isn't exactly "secure" as it seems
void shoujo_memory_insecure_wipe(void * const eval, const size_t len) {
    volatile uint8_t * volatile tmp = (volatile uint8_t * volatile) eval;
    size_t i                        = 0U;

    while (i < len) {
        tmp[i++] = 0x00;
    }
}

void shoujo_stack_insecure_wipe(const size_t len) {
    uint8_t tmp[len];
    shoujo_memory_insecure_wipe(tmp, len);
}
