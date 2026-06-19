#pragma once

#include <unordered_map>

#include "AssetEntry.h"

// AssetRegistry do Resource Manager — mantém o estado de carregamento
// de todos os assets conhecidos pelo ResourceManager.
//
// Melhorias em relação à versão anterior:
//   - Include de AssetEntry.h presente (versão anterior usava AssetEntry sem include)
//   - UnregisterAsset() para remoção em runtime
//   - UpdateLoadState() para o StreamingManager atualizar o estado sem expor internals
//   - GetAll() para iteração no MemoryTracker

class AssetRegistry
{
public:

    void RegisterAsset(const AssetEntry& Entry);

    void UnregisterAsset(AssetID ID);

    AssetEntry*       FindAsset(AssetID ID);
    const AssetEntry* FindAsset(AssetID ID) const;

    void UpdateLoadState(AssetID ID, ELoadState NewState);

    const std::unordered_map<AssetID, AssetEntry>& GetAll() const;

private:

    std::unordered_map<AssetID, AssetEntry> Assets;
};