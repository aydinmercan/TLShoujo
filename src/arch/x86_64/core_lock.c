#include "internal/core.h"

static volatile int _locked;

void _core_lock(void)
{
	while (__sync_lock_test_and_set(&_locked, 1) != 0) {
		__asm__ __volatile__("pause" ::: "memory");
	}
}

void _core_unlock(void)
{
	__sync_lock_release(&_locked);
}
