#include <errno.h>
#include <sys/mman.h>

#include "tlshoujo/memory.h"

uint32_t shoujo_memory_lock(void * const ptr, const size_t len) {
#if defined(HAVE_MADVISE) && defined(MADV_DONTDUMP) && defined(NDEBUG)
    (void) madvise(ptr, len, MADV_DONTDUMP);
#endif

#ifdef HAVE_MLOCK
    return mlock(ptr, len) == 0;
#else
    errno = ENOSYS;
    return 0;
#endif
}

uint32_t shoujo_memory_unlock(void * const ptr, const size_t len) {
#if defined(HAVE_MADVISE) && defined(MADV_DODUMP) && defined(NDEBUG)
    (void) madvise(ptr, len, MADV_DODUMP);
#endif

#ifdef HAVE_MLOCK
    return munlock(ptr, len) == 0;
#else
    errno = ENOSYS;
    return 0;
#endif
}
