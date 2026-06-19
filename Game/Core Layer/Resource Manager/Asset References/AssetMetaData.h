#pragma once

#include <cstdint>

// AssetMetadata carrega informações de disco sobre um asset.
//
// Melhoria em relação à versão anterior:
//   - ImportDate trocado por UnixTimestamp (uint64_t) — serializável como POD,
//     consistente com SaveMetadata no Save System

struct AssetMetadata
{
    uint64_t FileSize        = 0;
    uint64_t MemoryUsage     = 0;
    uint64_t UnixTimestamp   = 0;   // data de importação como Unix epoch
    uint32_t Version         = 1;
    bool     bCompressed     = false;
};