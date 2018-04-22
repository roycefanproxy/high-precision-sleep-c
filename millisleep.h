#ifndef WRAPPER_MILLISLEEP_H
#define WRAPPER_MILLISLEEP_H
#if defined(__linux__)

#include <time.h>
#include <stdint.h>

#    if !defined(_POSIX_C_SOURCE) 
#error POSIX not support
#    elif _POSIX_C_SOURCE < 199309L
#error POSIX standard not supported. (_POSIX_C_SOURCE < 199309L)
#    endif // _POSIX_C_SOURCE

int32_t millisleep(int32_t milliseconds);

#elif defined(_WIN64)

#include <Windows.h>

__int32 millisleep(__int32 milliseconds);

#endif // OS


enum sleep_ret_val { SLP_SUCCESS, SLP_FAULT, SLP_INTR, SLP_INVAL };


#endif // WRAPPER_MILLISLEEP_H
