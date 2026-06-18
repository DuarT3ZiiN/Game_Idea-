#pragma once

#include <string>
#include <cstdint>

#include "AssetID.h"
#include "VehicleAssetTypes.h"

// VehicleAsset descreve um veículo registrado no AssetRegistryManager.
//
// Melhorias em relação à versão anterior:
//   - Includes obrigatórios presentes
//   - PerformanceClass: necessário para filtros de evento (seção 1.1.1.2
//     menciona classes de veículo como critério de entrada em corridas)
//   - Year e TopSpeed: dados exibidos na UI da garagem

struct VehicleAsset
{
    AssetID          ID               = INVALID_ASSET_ID;
    std::string      VehicleName;
    std::string      Manufacturer;
    EVehicleAssetType Type            = EVehicleAssetType::VehicleDefinition;
    std::string      AssetPath;

    uint32_t         Year             = 0;
    uint32_t         PerformanceClass = 0; // 1–5 (C→S)
    float            TopSpeed         = 0.f;
};