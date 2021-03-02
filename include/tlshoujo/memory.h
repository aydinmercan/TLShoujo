#pragma once

#include <stddef.h>
#include <stdint.h>

int shoujo_memory_compare(const void * eval1, const void * eval2, const size_t len);
int shoujo_memory_is_zero(const void * const eval, const size_t len);
