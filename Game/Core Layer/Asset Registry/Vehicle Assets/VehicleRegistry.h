#pragma once

#include <unordered_map>

class VehicleRegistry
{
public:

    void RegisterVehicle(
        const VehicleAsset& Asset
    );

    const VehicleAsset*
    FindVehicle(
        AssetID ID
    ) const;

private:

    std::unordered_map
    <
        AssetID,
        VehicleAsset
    > Vehicles;
};

