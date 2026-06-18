#include "PoolManager.h"

void PoolManager::RegisterPool(
    uint32_t PoolID,
    PoolAllocator* Pool
)
{
    Pools[PoolID] = Pool;
}

PoolAllocator*
PoolManager::GetPool(
    uint32_t PoolID
)
{
    auto It =
        Pools.find(PoolID);

    if (It == Pools.end())
    {
        return nullptr;
    }

    return It->second;
}
