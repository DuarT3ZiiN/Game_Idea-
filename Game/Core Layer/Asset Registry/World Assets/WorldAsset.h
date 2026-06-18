#pragma once

#include <string>
#include <cstdint>

#include "AssetID.h"
#include "WorldAssetTypes.h"

// WorldAsset descreve um asset do mundo (distrito, rota, checkpoint, etc.).
//
// Melhorias em relação à versão anterior:
//   - Includes presentes
//   - DistrictID: associa o asset ao distrito onde pertence —
//     necessário para o streaming carregar/descarregar assets por região
//   - bStreamable: districts e navmeshes são sempre streamáveis

struct WorldAsset
{
    AssetID         ID          = INVALID_ASSET_ID;
    std::string     Name;
    EWorldAssetType Type        = EWorldAssetType::District;
    std::string     AssetPath;
    uint32_t        DistrictID  = 0;  // 0 = global (não pertence a um distrito específico)
    bool            bStreamable = false;
};