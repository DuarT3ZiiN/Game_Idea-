#pragma once

class FrameProfiler
{
public:

    void BeginFrame();

    void EndFrame();

    const PerformanceMetrics&
    GetMetrics() const;

private:

    PerformanceMetrics Metrics;

    PerformanceCounter FrameCounter;
};