#pragma once

#include <vector>

class AssetQuery
{
public:

    std::vector<AssetID>
    FindVehiclesByBrand(
        const std::string& Brand
    );

    std::vector<AssetID>
    FindDistrictAssets(
        uint32_t DistrictID
    );

    std::vector<AssetID>
    FindEngineSounds(
        AssetID VehicleID
    );
};
