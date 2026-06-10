#pragma once

#include "AssetRegistry.h"
#include "RuntimeCache.h"
#include "ResourceLoader.h"
#include "MemoryTracker.h"
#include "MemoryBudget.h"

class ResourceManager
{
public:

    void Initialize();

    AssetHandle LoadAsset(
        const AssetReference&
        Reference
    );

    void UnloadAsset(
        AssetHandle Handle
    );

    AssetEntry* GetAsset(
        AssetHandle Handle
    );

    const MemoryStatistics&
    GetMemoryStats() const;

private:

    AssetRegistry Registry;

    RuntimeCache Cache;

    ResourceLoader Loader;

    MemoryTracker Memory;

    MemoryBudget Budget;
};
