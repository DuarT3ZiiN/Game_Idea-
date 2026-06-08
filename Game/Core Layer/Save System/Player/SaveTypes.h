#pragma once

#include <cstdint>

enum class ESaveType : uint8_t
{
    Player,
    World,
    Career,
    Garage,
    Settings
};

// Resultado tipado de operações de save/load — substitui bool cru
// para que os chamadores saibam exatamente o que deu errado.
enum class ESaveResult : uint8_t
{
    Success,
    FileNotFound,
    FileWriteError,
    FileReadError,
    VersionIncompatible,  // major version mismatch
    VersionUpgraded,      // save antigo migrado com sucesso
    CorruptedData,        // checksum falhou
    SlotOutOfRange
};