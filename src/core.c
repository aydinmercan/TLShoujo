#include "tlshoujo/core.h"

#include "internal/impl.h"
#include "tlshoujo/probe.h"

volatile int _initialized = 0;

int shoujo_init(void) {
    if (_initialized != 0) {
        return 1;
    }

    if (shoujo_probe_cpu_features() != 0) {
        return -1;
    }

    //   _probe_chacha20_best();

    _initialized = 1;

    return 0;
}
