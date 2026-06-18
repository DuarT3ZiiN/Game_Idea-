#pragma once

#include <cstdint>

enum class EVehicleAssetType : uint8_t
{
    VehicleDefinition,   // dados base do veículo (massa, dimensões, stats)
    VehiclePhysics,      // tuning de física (suspensão, friction curves)
    VehicleAudio,        // engine sound, exhaust, turbo
    VehicleCustomization, // paint, wheels, body kits
    VehicleAnimation,    // skeleton, rigs
    VehicleAI            // comportamento de IA para este veículo (seção 2.2)
};