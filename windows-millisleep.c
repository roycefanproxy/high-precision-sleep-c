#include "millisleep.h"
#define WIN32_LEAN_AND_MEAN

__int32 millisleep(__int32 milliseconds)
{
    static bool initialized;
    static double ticks_per_millisec;


    if (milliseconds < 0)
        return SLP_INVAL;

    // for delays longer than 10 seconds, ignore the delay
    if (milliseconds > (1000 * 10)) {
        Sleep(milliseconds);
    } else {
        if (!initialized) {
            LARGE_INTEGER ticks_per_sec;

            if (QueryPerformanceFrequency(&ticks_per_second))
                ticks_per_millisec = (double) ticks_per_sec.QuadPart / 1000000.0;
            initialized = true;
        }
        
        __int32 sleep_millis = (__int32) milliseconds - 16;

        __int64 wait_ticks = milliseconds * ticks_per_millisec;

        LARGE_INTEGER counter_before;
        if (QueryPerformanceCounter(&counter_before)) {
            __int64 wait_until = counter_before.QuadPart + wait_ticks;

            if (sleep_millis > 0)
                Sleep(sleep_millis);

            LARGE_INTEGER counter_after;
            while (1) {
                // if query failed
                if (!QueryPerformanceCounter(&counter_after))
                    break;

                if (counter_after.QuadPart >= wait_until)
                    break;
            }

        }
    }

    return SLP_SUCCESS;
}
