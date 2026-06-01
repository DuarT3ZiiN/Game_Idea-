#pragma once

#include <vector>
#include <utility>

class JobDistributor
{
public:

    static std::vector<
        std::pair<uint32_t,uint32_t>
    >
    SplitWork(
        uint32_t TotalItems,
        uint32_t WorkerCount
    );
};

