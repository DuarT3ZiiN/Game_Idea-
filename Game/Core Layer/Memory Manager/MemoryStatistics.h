#pragma once

struct MemoryStatistics
{
    MemorySize TotalAllocated = 0;

    MemorySize TotalFreed = 0;

    MemorySize CurrentUsage = 0;

    MemorySize PeakUsage = 0;

    uint64_t AllocationCount = 0;

    uint64_t FreeCount = 0;
};
