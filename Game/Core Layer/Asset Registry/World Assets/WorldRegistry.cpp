#include "WorldRegistry.h"

void WorldRegistry::RegisterWorldAsset(const WorldAsset& Asset)
{
    Assets[Asset.ID] = Asset;
}

void WorldRegistry::UnregisterWorldAsset(AssetID ID)
{
    Assets.erase(ID);
}

const WorldAsset* WorldRegistry::FindAsset(AssetID ID) const
{
    auto It = Assets.find(ID);
    return (It != Assets.end()) ? &It->second : nullptr;
}

std::vector<AssetID> WorldRegistry::FindByDistrict(uint32_t DistrictID) const
{
    std::vector<AssetID> Result;

    for (const auto& [ID, Asset] : Assets)
    {
        if (Asset.DistrictID == DistrictID)
            Result.push_back(ID);
    }

    return Result;
}

std::vector<AssetID> WorldRegistry::FindByType(EWorldAssetType Type) const
{
    std::vector<AssetID> Result;

    for (const auto& [ID, Asset] : Assets)
    {
        if (Asset.Type == Type)
            Result.push_back(ID);
    }

    return Result;
}

const std::unordered_map<AssetID, WorldAsset>& WorldRegistry::GetAll() const
{
    return Assets;
}