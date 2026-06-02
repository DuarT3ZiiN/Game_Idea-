#include "PerformanceMonitor.h"

#include <algorithm>

void PerformanceMonitor::RegisterTime(
    const std::string& SystemName,
    double             TimeMS
)
{
    std::lock_guard<std::mutex> Lock(Mutex);

    auto& Data = Times[SystemName];

    // Primeira leitura inicializa a média
    if (Data.AverageMS == 0.0)
        Data.AverageMS = TimeMS;
    else
        Data.AverageMS = Data.Alpha * TimeMS + (1.0 - Data.Alpha) * Data.AverageMS;

    Data.PeakMS = std::max(Data.PeakMS, TimeMS);
}

double PerformanceMonitor::GetAverageTime(
    const std::string& SystemName
) const
{
    std::lock_guard<std::mutex> Lock(Mutex);

    auto It = Times.find(SystemName);

    if (It == Times.end())
        return 0.0;

    return It->second.AverageMS;
}

double PerformanceMonitor::GetPeakTime(
    const std::string& SystemName
) const
{
    std::lock_guard<std::mutex> Lock(Mutex);

    auto It = Times.find(SystemName);

    if (It == Times.end())
        return 0.0;

    return It->second.PeakMS;
}

void PerformanceMonitor::ResetPeaks()
{
    std::lock_guard<std::mutex> Lock(Mutex);

    for (auto& Pair : Times)
        Pair.second.PeakMS = 0.0;
}