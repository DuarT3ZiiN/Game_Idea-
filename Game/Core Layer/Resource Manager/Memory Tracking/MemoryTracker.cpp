#include "MemoryTracker.h"

void MemoryTracker::Initialize(const MemoryBudget& InBudget)
{
    Budget = InBudget;
}

void MemoryTracker::Allocate(uint64_t Bytes)
{
    Stats.TotalAllocated += Bytes;
    Stats.TotalUsed      += Bytes;

    if (Stats.TotalUsed > Stats.PeakUsage)
        Stats.PeakUsage = Stats.TotalUsed;
}

void MemoryTracker::Free(uint64_t Bytes)
{
    if (Bytes > Stats.TotalUsed)
        Stats.TotalUsed = 0;
    else
        Stats.TotalUsed -= Bytes;
}

void MemoryTracker::TrackAsset(AssetID ID, uint64_t Bytes)
{
    AssetMemory[ID] = Bytes;
    Allocate(Bytes);
}

void MemoryTracker::UntrackAsset(AssetID ID)
{
    auto It = AssetMemory.find(ID);
    if (It == AssetMemory.end())
        return;

    Free(It->second);
    AssetMemory.erase(It);
}

uint64_t MemoryTracker::GetAssetMemory(AssetID ID) const
{
    auto It = AssetMemory.find(ID);
    return (It != AssetMemory.end()) ? It->second : 0;
}

bool MemoryTracker::IsOverBudget() const
{
    return Stats.IsOverBudget(Budget.TotalBudgetBytes());
}

const MemoryStatistics& MemoryTracker::GetStatistics() const
{
    return Stats;
}