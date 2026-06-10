#pragma once

#include "VehicleRegistry.h"
#include "WorldRegistry.h"
#include "AudioRegistry.h"

class AssetRegistryManager
{
public:

    void Initialize();

    VehicleRegistry&
    Vehicles();

    WorldRegistry&
    World();

    AudioRegistry&
    Audio();

private:

    VehicleRegistry VehicleAssets;

    WorldRegistry WorldAssets;

    AudioRegistry AudioAssets;
};