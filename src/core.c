#include "tlshoujo/core.h"

#include "internal/impl.h"
#include "tlshoujo/probe.h"

extern void _shoujo_core_lock(void);
extern void _shoujo_core_unlock(void);

static volatile int _initialized = 0;

volatile int _core_lock;

int __attribute__((flatten)) shoujo_init(void) {
    _shoujo_core_lock();

    if (_initialized != 0) {
        return 1;
    }

    if (shoujo_probe_cpu_features() != 0) {
        _shoujo_core_unlock();
        return -1;
    }

    _initialized = 1;

    _shoujo_core_unlock();

    return 0;
}
