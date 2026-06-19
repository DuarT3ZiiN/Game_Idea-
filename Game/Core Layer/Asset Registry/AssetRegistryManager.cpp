#include "AssetRegistryManager.h"

void AssetRegistryManager::Initialize()
{
    // Conecta o AssetQuery às instâncias reais dos registries
    Query.Initialize(&VehicleAssets, &WorldAssets, &AudioAssets);
}

VehicleRegistry& AssetRegistryManager::Vehicles()       { return VehicleAssets; }
WorldRegistry&   AssetRegistryManager::World()          { return WorldAssets; }
AudioRegistry&   AssetRegistryManager::Audio()          { return AudioAssets; }
AssetQuery&      AssetRegistryManager::GetQuery()       { return Query; }

const VehicleRegistry& AssetRegistryManager::Vehicles() const { return VehicleAssets; }
const WorldRegistry&   AssetRegistryManager::World()    const { return WorldAssets; }
const AudioRegistry&   AssetRegistryManager::Audio()    const { return AudioAssets; }