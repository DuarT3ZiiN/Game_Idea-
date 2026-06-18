#pragma once

class RuntimeProfiler
{
public:

    void Update();

    const PerformanceMetrics&
    GetMetrics() const;

private:

    FrameProfiler Frame;
};