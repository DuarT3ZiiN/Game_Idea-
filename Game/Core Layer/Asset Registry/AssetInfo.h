#pragma once

#include <string>

struct AssetInfo
{
    AssetID ID = 0;

    std::string Name;

    std::string Path;

    EAssetCategory Category;
};

