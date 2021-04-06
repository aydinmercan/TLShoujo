#include <errno.h>
#include <sys/mman.h>

#include "tlshoujo/memory.h"

int shoujo_memory_lock(void * const ptr, const size_t len) {
#if defined(HAVE_MADVISE) && defined(MADV_DONTDUMP) && defined(NDEBUG)
    (void) madvise(ptr, len, MADV_DONTDUMP);
#endif

#ifdef HAVE_MLOCK
    return mlock(ptr, len);
#else
    errno = ENOSYS;
    return -1;
#endif
}

int shoujo_memory_unlock(void * const ptr, const size_t len) {
#if defined(HAVE_MADVISE) && defined(MADV_DODUMP) && defined(NDEBUG)
    (void) madvise(ptr, len, MADV_DODUMP);
#endif

#ifdef HAVE_MLOCK
    return munlock(ptr, len);
#else
    errno = ENOSYS;
    return -1;
#endif
}
