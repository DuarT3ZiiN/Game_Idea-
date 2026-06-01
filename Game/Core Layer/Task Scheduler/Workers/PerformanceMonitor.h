#pragma once

#include <unordered_map>
#include <string>

class PerformanceMonitor
{
public:

    void RegisterTime(
        const std::string& SystemName,
        double TimeMS
    );

    double GetAverageTime(
        const std::string& SystemName
    ) const;

private:

    std::unordered_map<
        std::string,
        double
    > Times;
};

