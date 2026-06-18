#include "FrameProfiler.h"

void FrameProfiler::BeginFrame()
{
    FrameCounter.Begin();
}

void FrameProfiler::EndFrame()
{
    FrameCounter.End();

    Metrics.FrameTimeMS =
        static_cast<float>(
            FrameCounter.GetElapsedMS()
        );

    Metrics.FPS =
        1000.0f /
        Metrics.FrameTimeMS;
}

const PerformanceMetrics&
FrameProfiler::GetMetrics() const
{
    return Metrics;
}
