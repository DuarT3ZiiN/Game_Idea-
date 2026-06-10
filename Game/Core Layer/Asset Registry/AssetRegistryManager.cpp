#include "AssetRegistryManager.h"

void AssetRegistryManager::Initialize()
{
}

VehicleRegistry&
AssetRegistryManager::Vehicles()
{
    return VehicleAssets;
}

WorldRegistry&
AssetRegistryManager::World()
{
    return WorldAssets;
}

AudioRegistry&
AssetRegistryManager::Audio()
{
    return AudioAssets;
}