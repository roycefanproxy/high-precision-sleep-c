#ifndef WRAPPER_MILLISLEEP_H
#define WRAPPER_MILLISLEEP_H
#include <time.h>
#include <stdint.h>
#if !defined(_POSIX_C_SOURCE) 
#error POSIX not support
#elif _POSIX_C_SOURCE < 199309L
#error POSIX standard not supported. (_POSIX_C_SOURCE < 199309L)
#endif

enum sleep_ret_val { SLP_SUCCESS, SLP_FAULT, SLP_INTR, SLP_INVAL };

int32_t millisleep(int32_t millisecond);

#endif // WRAPPER_MILLISLEEP_H
