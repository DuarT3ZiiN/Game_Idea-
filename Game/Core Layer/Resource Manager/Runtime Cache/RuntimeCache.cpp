#include "RuntimeCache.h"

void RuntimeCache::Add(
    AssetID ID,
    void* Data
)
{
    CachedAssets[ID] = Data;
}

void RuntimeCache::Remove(
    AssetID ID
)
{
    CachedAssets.erase(ID);
}

void* RuntimeCache::Find(
    AssetID ID
)
{
    auto It =
        CachedAssets.find(ID);

    if (It == CachedAssets.end())
    {
        return nullptr;
    }

    return It->second;
}
