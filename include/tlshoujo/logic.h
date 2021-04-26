#pragma once

#include <stddef.h>
#include <stdint.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"

static inline uint32_t __attribute__((pure, always_inline))
shoujo_mux(uint32_t ctl, uint32_t one, uint32_t zero) {
    return zero ^ (-ctl & (one ^ zero));
}

static inline uint32_t __attribute__((pure, always_inline)) shoujo_not(uint32_t ctl) {
    return ctl ^ 0x01;
}

static inline uint32_t __attribute__((pure, always_inline)) shoujo_equals(uint32_t x, uint32_t y) {
    uint32_t ctl = x ^ y;
    return shoujo_not((ctl | -ctl) >> 31);
}

static inline uint32_t __attribute__((pure, always_inline)) shoujo_u8_is_zero(uint8_t ctl) {
    return (0x01 & ((ctl - 1) >> 8));
}

#pragma GCC diagnostic pop
