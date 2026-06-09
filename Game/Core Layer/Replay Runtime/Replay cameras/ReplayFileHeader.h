#pragma once

#include <cstdint>
#include <string>

// ReplayFileHeader é o primeiro bloco de um arquivo .replay no disco.
//
// Melhorias em relação à versão anterior:
//   - MagicNumber: identifica o arquivo como replay válido antes de ler tudo
//   - TrackName e RecordingTimestamp: metadados para a UI de seleção de replays
//   - TargetFrameRate: informa o playback a que framerate o replay foi gravado

static constexpr uint32_t REPLAY_MAGIC_NUMBER = 0x52504C59; // "RPLY"

struct ReplayFileHeader
{
    uint32_t MagicNumber       = REPLAY_MAGIC_NUMBER;
    uint32_t Version           = 1;
    uint64_t FrameCount        = 0;
    uint64_t DurationMS        = 0;
    uint64_t RecordingTimestamp = 0; // Unix epoch
    uint32_t TargetFrameRate   = 60;
    char     TrackName[64]     = {};
};