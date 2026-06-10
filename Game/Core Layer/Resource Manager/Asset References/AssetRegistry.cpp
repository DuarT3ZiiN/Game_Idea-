#include "AssetRegistry.h"

void AssetRegistry::RegisterAsset(
    const AssetEntry& Entry
)
{
    Assets.emplace(
        Entry.Reference.Handle.ID,
        Entry
    );
}

AssetEntry*
AssetRegistry::FindAsset(
    AssetID ID
)
{
    auto It =
        Assets.find(ID);

    if (It == Assets.end())
    {
        return nullptr;
    }

    return &It->second;
}
