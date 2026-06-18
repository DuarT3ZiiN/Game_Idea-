#pragma once

#include <string>
#include <cstdint>

#include "AssetID.h"
#include "AssetCategory.h"

// AssetInfo é o registro canônico de um asset no AssetRegistryManager.
//
// Melhorias em relação à versão anterior:
//   - Todos os includes presentes (versão anterior usava AssetID e EAssetCategory
//     sem incluir os headers correspondentes)
//   - bStreamable: informa ao ResourceManager se o asset pode ser
//     carregado sob demanda (integração com seção 3.9)
//   - SizeBytes: tamanho em disco para budgeting do MemoryTracker

struct AssetInfo
{
    AssetID        ID          = INVALID_ASSET_ID;
    std::string    Name;
    std::string    Path;
    EAssetCategory Category    = EAssetCategory::World;
    uint64_t       SizeBytes   = 0;
    uint32_t       Version     = 1;
    bool           bStreamable = false;
    bool           bPreload    = false;
};