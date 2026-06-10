#pragma once

#include <string>

struct AudioAsset
{
    AssetID ID = 0;

    std::string Name;

    EAudioAssetType Type;

    std::string AssetPath;
};
