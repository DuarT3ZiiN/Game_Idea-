#include "ResourceManager.h"

void ResourceManager::Initialize()
{
}

AssetHandle
ResourceManager::LoadAsset(
    const AssetReference&
    Reference
)
{
    AssetEntry Entry;

    Entry.Reference =
        Reference;

    Entry.RuntimeData =
        Loader.Load(
            Reference
        );

    Registry.RegisterAsset(
        Entry
    );

    Cache.Add(
        Reference.Handle.ID,
        Entry.RuntimeData
    );

    return Reference.Handle;
}

void ResourceManager::UnloadAsset(
    AssetHandle Handle
)
{
    Cache.Remove(
        Handle.ID
    );

    Loader.Unload(
        Handle.ID
    );
}

AssetEntry*
ResourceManager::GetAsset(
    AssetHandle Handle
)
{
    return Registry.FindAsset(
        Handle.ID
    );
}

const MemoryStatistics&
ResourceManager::GetMemoryStats() const
{
    return Memory.GetStatistics();
}

