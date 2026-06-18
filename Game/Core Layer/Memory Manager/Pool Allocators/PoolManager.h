#pragma once

#include <unordered_map>

class PoolManager
{
public:

    void RegisterPool(
        uint32_t PoolID,
        PoolAllocator* Pool
    );

    PoolAllocator*
    GetPool(
        uint32_t PoolID
    );

private:

    std::unordered_map
    <
        uint32_t,
        PoolAllocator*
    > Pools;
};
