#include "JobDistributor.h"

std::vector<
    std::pair<uint32_t,uint32_t>
>
JobDistributor::SplitWork(
    uint32_t TotalItems,
    uint32_t WorkerCount
)
{
    std::vector<
        std::pair<uint32_t,uint32_t>
    > Result;

    if (WorkerCount == 0)
        return Result;

    uint32_t ChunkSize =
        TotalItems / WorkerCount;

    uint32_t CurrentStart = 0;

    for (uint32_t i = 0;
         i < WorkerCount;
         ++i)
    {
        uint32_t Start = CurrentStart;

        uint32_t End =
            (i == WorkerCount - 1)
            ? TotalItems
            : Start + ChunkSize;

        Result.emplace_back(Start, End);

        CurrentStart = End;
    }

    return Result;
}


