#include "PerformanceCounter.h"

void PerformanceCounter::Begin()
{
    Start =
        std::chrono::
        high_resolution_clock::
        now();
}

void PerformanceCounter::End()
{
    Finish =
        std::chrono::
        high_resolution_clock::
        now();
}

double
PerformanceCounter::GetElapsedMS() const
{
    return
        std::chrono::
        duration<double,
        std::milli>(
            Finish - Start
        ).count();
}


