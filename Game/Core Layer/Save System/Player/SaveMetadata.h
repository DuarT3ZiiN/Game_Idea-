#pragma once

#include <string>
#include <cstdint>

#include "SaveVersion.h"
#include "SaveSlotID.h"

// SaveMetadata contém dados de identificação do arquivo de save.
//
// Melhorias em relação à versão anterior:
//   - Timestamp como uint64_t (Unix epoch) — serializável como POD,
//     sem problemas de tamanho variável ao escrever em binário
//   - Checksum de 32 bits — verificado ao carregar para detectar corrupção
//   - SaveName como std::string apenas no .h; a serialização cuida do tamanho

struct SaveMetadata
{
    SaveSlotID   SlotID          = INVALID_SAVE_SLOT;
    std::string  SaveName;
    uint64_t     UnixTimestamp   = 0;   // segundos desde epoch UTC
    uint64_t     PlayTimeSeconds = 0;
    SaveVersion  Version;
    uint32_t     Checksum        = 0;   // CRC32 do payload, calculado pelo BinarySerializer
};