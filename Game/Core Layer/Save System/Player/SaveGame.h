#pragma once

#include "SaveMetadata.h"
#include "PlayerSaveData.h"
#include "WorldSaveData.h"
#include "GarageSaveData.h"

struct SaveGame
{
    SaveMetadata   Metadata;
    PlayerSaveData Player;
    WorldSaveData  World;
    GarageSaveData Garage;
};