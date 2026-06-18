#pragma once

#include <chrono>

class PerformanceCounter
{
public:

    void Begin();

    void End();

    double GetElapsedMS() const;

private:

    std::chrono::high_resolution_clock::
        time_point Start;

    std::chrono::high_resolution_clock::
        time_point Finish;
};