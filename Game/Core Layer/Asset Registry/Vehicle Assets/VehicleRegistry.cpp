#include "VehicleRegistry.h"

void VehicleRegistry::RegisterVehicle(
    const VehicleAsset& Asset
)
{
    Vehicles[Asset.ID] = Asset;
}

const VehicleAsset*
VehicleRegistry::FindVehicle(
    AssetID ID
) const
{
    auto It =
        Vehicles.find(ID);

    if (It == Vehicles.end())
    {
        return nullptr;
    }

    return &It->second;
}
