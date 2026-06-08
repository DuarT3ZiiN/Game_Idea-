#pragma once

#include <vector>
#include <cstdint>

// GarageVehicleData — estado de um veículo salvo.
//
// Melhorias em relação à versão anterior:
//   - InstalledParts — IDs das peças de tuning instaladas (seção 2.3 do README)
//   - PaintColorID — cor atual da pintura
//   - NitroLevel — carga de nitro ao salvar

struct GarageVehicleData
{
    uint64_t VehicleID        = 0;
    uint32_t VehicleClass     = 0;
    float    Mileage          = 0.f;
    float    Damage           = 0.f;
    uint32_t PerformanceLevel = 0;
    uint32_t PaintColorID     = 0;
    float    NitroLevel       = 0.f;

    std::vector<uint32_t> InstalledParts; // IDs de peças de tuning instaladas
};

struct GarageSaveData
{
    std::vector<GarageVehicleData> Vehicles;
};