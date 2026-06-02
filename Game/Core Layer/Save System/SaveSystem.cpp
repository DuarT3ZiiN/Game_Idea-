#include "SaveSystem.h"

void SaveSystem::Initialize()
{
}

bool SaveSystem::SaveGameSlot(
    SaveSlotID Slot
)
{
    SaveGame Save;

    Save.Metadata.SlotID =
        Slot;

    Save.Metadata.Version =
        SaveVersionManager::
        GetCurrentVersion();

    PlayerManager
        .CapturePlayerState(
            Save
        );

    WorldManager
        .CaptureWorldState(
            Save
        );

    return FileManager.SaveToDisk(
        Save,
        "SaveSlot_" +
        std::to_string(Slot) +
        ".sav"
    );
}

bool SaveSystem::LoadGameSlot(
    SaveSlotID Slot
)
{
    SaveGame Save;

    if (!FileManager.LoadFromDisk(
        Save,
        "SaveSlot_" +
        std::to_string(Slot) +
        ".sav"
    ))
    {
        return false;
    }

    if (!SaveVersionManager::
        IsCompatible(
            Save.Metadata.Version
        ))
    {
        return false;
    }

    PlayerManager
        .RestorePlayerState(
            Save
        );

    WorldManager
        .RestoreWorldState(
            Save
        );

    return true;
}

