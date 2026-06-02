#include "JobDistributor.h"

#include <algorithm>

std::vector<std::pair<uint32_t, uint32_t>> JobDistributor::SplitWork(
    uint32_t TotalItems,
    uint32_t WorkerCount
)
{
    std::vector<std::pair<uint32_t, uint32_t>> Result;

    if (WorkerCount == 0 || TotalItems == 0)
        return Result;

    // Se temos mais workers do que itens, cada worker pega 1 item
    const uint32_t ActualWorkers = std::min(WorkerCount, TotalItems);
    const uint32_t ChunkSize     = TotalItems / ActualWorkers;

    uint32_t CurrentStart = 0;

    for (uint32_t i = 0; i < ActualWorkers; ++i)
    {
        const uint32_t Start = CurrentStart;
        const uint32_t End   = (i == ActualWorkers - 1)
            ? TotalItems                // último chunk absorve o restante
            : Start + ChunkSize;

        Result.emplace_back(Start, End);
        CurrentStart = End;
    }

    return Result;
}

uint32_t JobDistributor::OptimalChunkSize(
    uint32_t TotalItems,
    uint32_t WorkerCount
)
{
    if (WorkerCount == 0)
        return TotalItems;

    return std::max(1u, TotalItems / WorkerCount);
}