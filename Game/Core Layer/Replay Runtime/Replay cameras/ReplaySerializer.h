#pragma once

#include "ReplayRecording.h"

// ReplaySerializer persiste e carrega gravações em disco.
//
// Melhorias em relação à versão anterior:
//   - Usa BinarySerializer (mesmo padrão do Save System) para consistência
//   - SaveReplay valida que a gravação tem pelo menos 1 frame
//   - LoadReplay verifica MagicNumber antes de desserializar os frames
//   - GetDefaultPath() — caminho padrão baseado em slot e timestamp

class ReplaySerializer
{
public:

    bool SaveReplay(
        const ReplayRecording& Recording,
        const char*            Filename
    );

    bool LoadReplay(
        ReplayRecording& Recording,
        const char*      Filename
    );

    static const char* GetDefaultPath(uint32_t SlotID);
};