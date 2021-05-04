#pragma once

#include <stddef.h>
#include <stdint.h>

uint32_t shoujo_memory_compare(const void *eval1, const void *eval2, const size_t len)
    __attribute__((pure, nonnull));

uint32_t shoujo_memory_is_zero(const void *const eval, const size_t len)
    __attribute__((pure, nonnull));

void shoujo_memory_insecure_wipe(void *const eval, const size_t len) __attribute__((nonnull));
void shoujo_stack_insecure_wipe(const size_t len);

uint32_t shoujo_memory_lock(void *const ptr, const size_t len) __attribute__((nonnull));
uint32_t shoujo_memory_unlock(void *const ptr, const size_t len) __attribute__((nonnull));
