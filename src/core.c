#include "tlshoujo/core.h"

#include "tlshoujo/probe.h"

static volatile int initialized = 0;

int shoujo_init(void) {
    if (initialized != 0) {
        return 1;
    }

    if (shoujo_probe_cpu_features() != 0) {
        return -1;
    }

    initialized = 1;

    return 0;
}
