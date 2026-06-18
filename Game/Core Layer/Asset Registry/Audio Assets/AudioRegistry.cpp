#include "AudioRegistry.h"

void AudioRegistry::RegisterAudioAsset(const AudioAsset& Asset)
{
    Assets[Asset.ID] = Asset;
}

void AudioRegistry::UnregisterAudioAsset(AssetID ID)
{
    Assets.erase(ID);
}

const AudioAsset* AudioRegistry::FindAudioAsset(AssetID ID) const
{
    auto It = Assets.find(ID);
    return (It != Assets.end()) ? &It->second : nullptr;
}

std::vector<AssetID> AudioRegistry::FindByVehicle(AssetID VehicleID) const
{
    std::vector<AssetID> Result;

    for (const auto& [ID, Asset] : Assets)
    {
        if (Asset.VehicleID == VehicleID)
            Result.push_back(ID);
    }

    return Result;
}

std::vector<AssetID> AudioRegistry::FindByType(EAudioAssetType Type) const
{
    std::vector<AssetID> Result;

    for (const auto& [ID, Asset] : Assets)
    {
        if (Asset.Type == Type)
            Result.push_back(ID);
    }

    return Result;
}

const std::unordered_map<AssetID, AudioAsset>& AudioRegistry::GetAll() const
{
    return Assets;
}