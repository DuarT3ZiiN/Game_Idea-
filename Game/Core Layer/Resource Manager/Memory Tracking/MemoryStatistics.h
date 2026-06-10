#pragma once

struct MemoryStatistics
{
    uint64_t TotalAllocated = 0;

    uint64_t TotalUsed = 0;

    uint64_t TotalCached = 0;

    uint64_t PeakUsage = 0;
};