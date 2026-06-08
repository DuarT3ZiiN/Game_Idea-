#include "SaveSystem.h"

#include <chrono>

void SaveSystem::Initialize(AsyncJobManager* InJobManager)
{
    JobManager = InJobManager;
}

SaveGame SaveSystem::BuildCurrentSaveGame(SaveSlotID Slot)
{
    SaveGame Save;

    Save.Metadata.SlotID        = Slot;
    Save.Metadata.Version       = SaveVersionManager::GetCurrentVersion();
    Save.Metadata.UnixTimestamp = static_cast<uint64_t>(
        std::chrono::duration_cast<std::chrono::seconds>(
            std::chrono::system_clock::now().time_since_epoch()
        ).count()
    );

    PlayerManager.CapturePlayerState(Save);
    WorldManager.CaptureWorldState(Save);

    return Save;
}

ESaveResult SaveSystem::SaveGameSlot(SaveSlotID Slot)
{
    if (Slot >= MAX_SAVE_SLOTS)
        return ESaveResult::SlotOutOfRange;

    const SaveGame Save = BuildCurrentSaveGame(Slot);

    return FileManager.SaveToDisk(Save, SaveFileManager::GetSavePath(Slot));
}

AsyncJobID SaveSystem::SaveGameAsync(SaveSlotID Slot)
{
    if (!JobManager || Slot >= MAX_SAVE_SLOTS)
        return INVALID_ASYNC_JOB;

    // Captura o estado agora, no main thread
    const SaveGame Snapshot = BuildCurrentSaveGame(Slot);

    AsyncJob Job;
    Job.Type      = EAsyncJobType::SaveGame;
    Job.DebugName = "SaveGameAsync";
    Job.Execute   = [this, Snapshot, Slot]()
    {
        FileManager.SaveToDisk(
            Snapshot,
            SaveFileManager::GetSavePath(Slot)
        );
    };

    return JobManager->Submit(Job);
}

ESaveResult SaveSystem::LoadGameSlot(SaveSlotID Slot)
{
    if (Slot >= MAX_SAVE_SLOTS)
        return ESaveResult::SlotOutOfRange;

    SaveGame Save;

    const ESaveResult LoadResult =
        FileManager.LoadFromDisk(Save, SaveFileManager::GetSavePath(Slot));

    if (LoadResult != ESaveResult::Success)
        return LoadResult;

    // Verificação de versão
    const ESaveResult VersionResult =
        SaveVersionManager::CheckCompatibility(Save.Metadata.Version);

    if (VersionResult == ESaveResult::VersionIncompatible)
        return ESaveResult::VersionIncompatible;

    if (VersionResult == ESaveResult::VersionUpgraded)
    {
        if (!SaveVersionManager::Migrate(Save, Save.Metadata.Version))
            return ESaveResult::VersionIncompatible;
    }

    PlayerManager.RestorePlayerState(Save);
    WorldManager.RestoreWorldState(Save);

    return ESaveResult::Success;
}

bool SaveSystem::GetSlotMetadata(
    SaveSlotID    Slot,
    SaveMetadata& OutMetadata
) const
{
    // Carrega o save completo e retorna apenas os metadados.
    // Ponto de melhoria futura: ler apenas o header do arquivo.
    SaveGame Save;

    const ESaveResult Result =
        const_cast<SaveFileManager&>(FileManager).LoadFromDisk(
            Save,
            SaveFileManager::GetSavePath(Slot)
        );

    if (Result != ESaveResult::Success)
        return false;

    OutMetadata = Save.Metadata;
    return true;
}

bool SaveSystem::SlotExists(SaveSlotID Slot) const
{
    return FileManager.FileExists(SaveFileManager::GetSavePath(Slot));
}