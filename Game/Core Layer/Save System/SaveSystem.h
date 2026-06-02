#pragma once

#include "SaveFileManager.h"
#include "PlayerSaveManager.h"
#include "WorldSaveManager.h"

class SaveSystem
{
public:

    void Initialize();

    bool SaveGameSlot(
        SaveSlotID Slot
    );

    bool LoadGameSlot(
        SaveSlotID Slot
    );

private:

    SaveFileManager FileManager;

    PlayerSaveManager PlayerManager;

    WorldSaveManager WorldManager;
};

