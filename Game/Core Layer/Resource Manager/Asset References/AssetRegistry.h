#pragma once

#include <unordered_map>

class AssetRegistry
{
public:

    void RegisterAsset(
        const AssetEntry& Entry
    );

    AssetEntry* FindAsset(
        AssetID ID
    );

private:

    std::unordered_map<
        AssetID,
        AssetEntry
    > Assets;
};