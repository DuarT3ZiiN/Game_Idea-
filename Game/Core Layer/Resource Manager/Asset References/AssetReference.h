#pragma once

#include <string>

#include "AssetHandle.h"
#include "AssetTypes.h"

struct AssetReference
{
    AssetHandle Handle;
    EAssetType  Type        = EAssetType::Unknown;
    std::string Path;
    bool        bStreamable = false;
    bool        bPreload    = false;
};