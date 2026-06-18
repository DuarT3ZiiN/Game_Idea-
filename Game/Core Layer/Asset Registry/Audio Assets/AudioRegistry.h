#pragma once

#include <unordered_map>
#include <vector>

#include "AudioAsset.h"

class AudioRegistry
{
public:

    void RegisterAudioAsset(const AudioAsset& Asset);

    void UnregisterAudioAsset(AssetID ID);

    const AudioAsset* FindAudioAsset(AssetID ID) const;

    // Retorna sons associados a um veículo (engine, exhaust, turbo)
    std::vector<AssetID> FindByVehicle(AssetID VehicleID) const;

    // Retorna todos os assets de um tipo (ex: todos os Engine sounds)
    std::vector<AssetID> FindByType(EAudioAssetType Type) const;

    const std::unordered_map<AssetID, AudioAsset>& GetAll() const;

private:

    std::unordered_map<AssetID, AudioAsset> Assets;
};