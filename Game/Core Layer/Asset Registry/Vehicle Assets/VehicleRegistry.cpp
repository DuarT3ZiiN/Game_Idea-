#include "VehicleRegistry.h"

void VehicleRegistry::RegisterVehicle(const VehicleAsset& Asset)
{
    Vehicles[Asset.ID] = Asset;
}

void VehicleRegistry::UnregisterVehicle(AssetID ID)
{
    Vehicles.erase(ID);
}

const VehicleAsset* VehicleRegistry::FindVehicle(AssetID ID) const
{
    auto It = Vehicles.find(ID);
    return (It != Vehicles.end()) ? &It->second : nullptr;
}

std::vector<AssetID> VehicleRegistry::FindByManufacturer(
    const std::string& Manufacturer
) const
{
    std::vector<AssetID> Result;

    for (const auto& [ID, Asset] : Vehicles)
    {
        if (Asset.Manufacturer == Manufacturer)
            Result.push_back(ID);
    }

    return Result;
}

std::vector<AssetID> VehicleRegistry::FindByClass(
    uint32_t PerformanceClass
) const
{
    std::vector<AssetID> Result;

    for (const auto& [ID, Asset] : Vehicles)
    {
        if (Asset.PerformanceClass == PerformanceClass)
            Result.push_back(ID);
    }

    return Result;
}

const std::unordered_map<AssetID, VehicleAsset>& VehicleRegistry::GetAll() const
{
    return Vehicles;
}