#include "tlshoujo/core.h"

#include "internal/core.h"
#include "internal/impl.h"
#include "tlshoujo/probe.h"

static volatile int _initialized = 0;

uint32_t shoujo_init(void) {
    _core_lock();

    if (_initialized != 0) {
        return 0;
    }

    if (shoujo_probe_cpu_features() != 1) {
        _core_unlock();
        return 0;
    }

    _initialized = 1;

    _core_unlock();

    return 1;
}
