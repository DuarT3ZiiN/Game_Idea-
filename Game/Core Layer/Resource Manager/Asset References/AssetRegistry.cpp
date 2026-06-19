#include "AssetRegistry.h"

void AssetRegistry::RegisterAsset(const AssetEntry& Entry)
{
    Assets.emplace(Entry.Reference.Handle.ID, Entry);
}

void AssetRegistry::UnregisterAsset(AssetID ID)
{
    Assets.erase(ID);
}

AssetEntry* AssetRegistry::FindAsset(AssetID ID)
{
    auto It = Assets.find(ID);
    return (It != Assets.end()) ? &It->second : nullptr;
}

const AssetEntry* AssetRegistry::FindAsset(AssetID ID) const
{
    auto It = Assets.find(ID);
    return (It != Assets.end()) ? &It->second : nullptr;
}

void AssetRegistry::UpdateLoadState(AssetID ID, ELoadState NewState)
{
    AssetEntry* Entry = FindAsset(ID);
    if (Entry)
        Entry->LoadState = NewState;
}

const std::unordered_map<AssetID, AssetEntry>& AssetRegistry::GetAll() const
{
    return Assets;
}