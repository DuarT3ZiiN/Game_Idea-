#pragma once

#include <string>
#include <cstdint>

#include "AssetID.h"
#include "AudioAssetTypes.h"

// AudioAsset descreve um asset de áudio.
//
// Melhorias em relação à versão anterior:
//   - Includes presentes
//   - VehicleID: som de motor/exaustão pertence a um veículo específico —
//     permite que AssetQuery::FindEngineSounds(VehicleID) funcione corretamente
//   - DurationSeconds: necessário para o streaming decidir se pré-carrega

struct AudioAsset
{
    AssetID         ID              = INVALID_ASSET_ID;
    std::string     Name;
    EAudioAssetType Type            = EAudioAssetType::Ambience;
    std::string     AssetPath;
    AssetID         VehicleID       = INVALID_ASSET_ID; // 0 = não associado a veículo
    float           DurationSeconds = 0.f;
};