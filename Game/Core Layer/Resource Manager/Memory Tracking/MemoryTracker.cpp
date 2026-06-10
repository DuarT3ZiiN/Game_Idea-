#include "MemoryTracker.h"

void MemoryTracker::Allocate(
    uint64_t Bytes
)
{
    Stats.TotalAllocated += Bytes;
    Stats.TotalUsed += Bytes;

    if (
        Stats.TotalUsed >
        Stats.PeakUsage
    )
    {
        Stats.PeakUsage =
            Stats.TotalUsed;
    }
}

void MemoryTracker::Free(
    uint64_t Bytes
)
{
    Stats.TotalUsed -= Bytes;
}

const MemoryStatistics&
MemoryTracker::GetStatistics() const
{
    return Stats;
}

