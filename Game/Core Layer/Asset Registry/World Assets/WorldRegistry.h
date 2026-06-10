#pragma once

#include <unordered_map>

class WorldRegistry
{
public:

    void RegisterWorldAsset(
        const WorldAsset& Asset
    );

    const WorldAsset*
    FindAsset(
        AssetID ID
    ) const;

private:

    std::unordered_map
    <
        AssetID,
        WorldAsset
    > Assets;
};