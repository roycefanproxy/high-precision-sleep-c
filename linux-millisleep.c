#include "millisleep.h"
#include <errno.h>

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
