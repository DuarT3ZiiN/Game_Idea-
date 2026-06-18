#include "RuntimeProfiler.h"

void RuntimeProfiler::Update()
{
}

const PerformanceMetrics&
RuntimeProfiler::GetMetrics() const
{
    return Frame.GetMetrics();
}

