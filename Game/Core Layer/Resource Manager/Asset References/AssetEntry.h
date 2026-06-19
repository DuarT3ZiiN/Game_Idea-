#pragma once

#include <cstdint>

#include "AssetReference.h"
#include "AssetMetaData.h"

// ELoadState rastreia o ciclo de vida de um asset no ResourceManager.
// Necessário para o StreamingManager saber o que está pendente vs carregado.

enum class ELoadState : uint8_t
{
    Unloaded,
    Pending,    // solicitado, aguardando worker assíncrono
    Loading,    // sendo carregado por um AsyncWorker
    Loaded,     // em memória e disponível
    Evicting    // marcado para descarregamento
};

struct AssetEntry
{
    AssetReference Reference;
    AssetMetadata  Metadata;
    ELoadState     LoadState  = ELoadState::Unloaded;
    void*          RuntimeData = nullptr;
};