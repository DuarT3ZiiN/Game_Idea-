#include "AssetDataBaseQuery.h"

void AssetQuery::Initialize(
    const VehicleRegistry* InVehicles,
    const WorldRegistry*   InWorld,
    const AudioRegistry*   InAudio
)
{
    Vehicles = InVehicles;
    World    = InWorld;
    Audio    = InAudio;
}

std::vector<AssetID> AssetQuery::FindVehiclesByBrand(
    const std::string& Brand
) const
{
    if (!Vehicles)
        return {};

    return Vehicles->FindByManufacturer(Brand);
}

std::vector<AssetID> AssetQuery::FindDistrictAssets(
    uint32_t DistrictID
) const
{
    if (!World)
        return {};

    return World->FindByDistrict(DistrictID);
}

std::vector<AssetID> AssetQuery::FindEngineSounds(
    AssetID VehicleID
) const
{
    if (!Audio)
        return {};

    // Retorna apenas sons de engine e exhaust do veículo
    std::vector<AssetID> All = Audio->FindByVehicle(VehicleID);
    std::vector<AssetID> Result;

    for (AssetID ID : All)
    {
        const AudioAsset* Asset = Audio->FindAudioAsset(ID);
        if (!Asset)
            continue;

        if (Asset->Type == EAudioAssetType::Engine
         || Asset->Type == EAudioAssetType::Exhaust
         || Asset->Type == EAudioAssetType::Turbo)
        {
            Result.push_back(ID);
        }
    }

    return Result;
}