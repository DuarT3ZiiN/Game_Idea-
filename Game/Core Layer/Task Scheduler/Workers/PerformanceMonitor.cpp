#include "PerformanceMonitor.h"

void PerformanceMonitor::RegisterTime(
    const std::string& SystemName,
    double TimeMS
)
{
    Times[SystemName] = TimeMS;
}

double PerformanceMonitor::GetAverageTime(
    const std::string& SystemName
) const
{
    auto It =
        Times.find(SystemName);

    if (It == Times.end())
        return 0.0;

    return It->second;
}
