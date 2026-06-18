#pragma once

#include <unordered_map>
#include <vector>

#include "WorldAsset.h"

class WorldRegistry
{
public:

    void RegisterWorldAsset(const WorldAsset& Asset);

    void UnregisterWorldAsset(AssetID ID);

    const WorldAsset* FindAsset(AssetID ID) const;

    // Retorna todos os assets de um distrito — usado pelo streaming ao carregar região
    std::vector<AssetID> FindByDistrict(uint32_t DistrictID) const;

    // Retorna todos os assets de um tipo (ex: todos os Checkpoints)
    std::vector<AssetID> FindByType(EWorldAssetType Type) const;

    const std::unordered_map<AssetID, WorldAsset>& GetAll() const;

private:

    std::unordered_map<AssetID, WorldAsset> Assets;
};