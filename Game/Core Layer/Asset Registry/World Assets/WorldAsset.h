#pragma once

#include <string>

struct WorldAsset
{
    AssetID ID = 0;

    std::string Name;

    EWorldAssetType Type;

    std::string AssetPath;
};
