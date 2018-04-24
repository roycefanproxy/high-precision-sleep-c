#include "millisleep.h"
#include <time.h>
#include <stdint.h>
#include <errno.h>
#if !defined(_POSIX_C_SOURCE) 
#error POSIX not support
#elif _POSIX_C_SOURCE < 199309L
#error POSIX standard not supported. (_POSIX_C_SOURCE < 199309L)
#endif // _POSIX_C_SOURCE

enum sleep_ret_val { SLP_SUCCESS, SLP_FAULT, SLP_INTR, SLP_INVAL };

int32_t millisleep(int32_t milliseconds)
{
    struct timespec req = { milliseconds / 1000, (milliseconds % 1000) * 1000000 };
    struct timespec rem;

    if (nanosleep(&req, &rem)) {
        switch (errno) {
        case EFAULT:
            return SLP_FAULT;
            break;
        case EINTR:
            return SLP_INTR;
            break;
        case EINVAL:
            return SLP_INVAL;
            break;
        }
    }

    return SLP_SUCCESS;
}
