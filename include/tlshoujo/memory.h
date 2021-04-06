#pragma once

#include <stddef.h>
#include <stdint.h>

int __attribute__((pure))
shoujo_memory_compare(const void * eval1, const void * eval2, const size_t len);

int __attribute__((pure)) shoujo_memory_is_zero(const void * const eval, const size_t len);

void shoujo_memory_wipe(void * const eval, const size_t len);
void shoujo_stack_wipe(const size_t len);

int shoujo_memory_lock(void * const ptr, const size_t len);
int shoujo_memory_unlock(void * const ptr, const size_t len);
