#include "millisleep.h"
#include <errno.h>

int32_t millisleep(int32_t millisecond)
{
    struct timespec req = { millisecond / 1000u, millisecond % 1000u * 1000000u };
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
