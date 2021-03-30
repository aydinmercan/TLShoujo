#include "tlshoujo/memory.h"

void * __attribute__((malloc)) shoujo_alloc(const size_t * len);

void shoujo_free(void * const ptr);
