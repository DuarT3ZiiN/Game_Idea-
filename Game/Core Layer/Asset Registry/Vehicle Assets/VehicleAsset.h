#pragma once

#include <string>

struct VehicleAsset
{
    AssetID ID = 0;

    std::string VehicleName;

    std::string Manufacturer;

    EVehicleAssetType Type;

    std::string AssetPath;
};
