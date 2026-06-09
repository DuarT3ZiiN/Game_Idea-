#pragma once

#include <vector>
#include <cassert>

#include "ReplayFrame.h"
#include "ReplayFileHeader.h"

// ReplayRecording armazena todos os frames gravados.
//
// Melhorias em relação à versão anterior:
//   - Header integrado — um único objeto contém tudo que o serializer precisa
//   - GetFrameByTimestamp() — busca binária para scrubbing (seek para tempo)
//   - GetFrame() faz assert em índice inválido em vez de undefined behavior
//   - MaxFrames cap — evita crescimento ilimitado em gravações longas

static constexpr uint64_t REPLAY_MAX_FRAMES = 108000; // 30min @ 60fps

class ReplayRecording
{
public:

    void AddFrame(const ReplayFrame& Frame);

    const ReplayFrame& GetFrame(uint64_t Index) const;

    // Retorna o frame mais próximo do timestamp (segundos) — para scrubbing
    uint64_t GetFrameIndexByTimestamp(double TimestampSeconds) const;

    uint64_t GetFrameCount() const;

    bool IsFull() const;

    ReplayFileHeader& GetHeader()             { return Header; }
    const ReplayFileHeader& GetHeader() const { return Header; }

private:

    ReplayFileHeader            Header;
    std::vector<ReplayFrame>    Frames;
};