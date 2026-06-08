#pragma once

#include <functional>

#include "SaveFileManager.h"
#include "PlayerSaveManager.h"
#include "WorldSaveManager.h"
#include "SaveVersionManager.h"
#include "AsyncJobManager.h"

// SaveSystem — ponto de entrada público do Save System (seção 3.6 do README).
//
// Melhorias em relação à versão anterior:
//   - SaveGameSlot e LoadGameSlot retornam ESaveResult (não bool)
//   - SaveGameAsync submete o save para o AsyncJobManager no pool exclusivo
//     de SaveGame — não bloqueia o main thread
//   - LoadGameSlot faz versioning check e chama Migrate() se necessário
//   - GetSlotMetadata() carrega apenas o header do save (sem desserializar tudo)
//     para popular a UI de seleção de slots sem custo

class SaveSystem
{
public:

    void Initialize(AsyncJobManager* InJobManager = nullptr);

    // Save síncrono — use apenas em momentos sem restrição de frame (ex: quit)
    ESaveResult SaveGameSlot(SaveSlotID Slot);

    // Save assíncrono — captura estado agora, escreve em background
    AsyncJobID  SaveGameAsync(SaveSlotID Slot);

    // Load sempre síncrono (o jogo não pode continuar sem o save carregado)
    ESaveResult LoadGameSlot(SaveSlotID Slot);

    // Retorna apenas os metadados do slot (para UI de seleção)
    bool GetSlotMetadata(SaveSlotID Slot, SaveMetadata& OutMetadata) const;

    bool SlotExists(SaveSlotID Slot) const;

private:

    SaveGame BuildCurrentSaveGame(SaveSlotID Slot);

private:

    SaveFileManager   FileManager;
    PlayerSaveManager PlayerManager;
    WorldSaveManager  WorldManager;
    AsyncJobManager*  JobManager = nullptr;
};