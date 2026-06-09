#pragma once

#include <functional>

#include "ReplayRecording.h"
#include "ReplayTypes.h"

using ReplayFrameCallback = std::function<void(const ReplayFrame&)>;

// ReplayPlaybackRuntime executa o replay frame a frame.
//
// Melhorias em relação à versão anterior:
//   - Scrub(timestamp) — seek para qualquer ponto via GetFrameIndexByTimestamp
//   - PlaybackSpeed — suporta slow motion e fast forward (0.5x, 2x, etc.)
//   - OnFrameApplied callback — desacopla o playback da aplicação de estado
//     (quem consome o frame decide o que fazer com o VehicleStateSnapshot)
//   - GetProgress() — [0,1] para barra de progresso na UI

class ReplayPlaybackRuntime
{
public:

    void Start(const ReplayRecording* Replay);
    void Pause();
    void Resume();
    void Stop();

    // Seek para o timestamp mais próximo (segundos)
    void Scrub(double TimestampSeconds);

    void Tick(double DeltaTime);

    // Callback chamado para cada frame aplicado — receptor decide como usar
    void SetOnFrameApplied(ReplayFrameCallback Callback);

    float         GetProgress()      const;
    EReplayState  GetState()         const { return State; }
    uint64_t      GetCurrentFrame()  const { return CurrentFrame; }

    float PlaybackSpeed = 1.f; // 0.5 = slow motion, 2.0 = fast forward

private:

    const ReplayRecording* Recording     = nullptr;
    uint64_t               CurrentFrame  = 0;
    EReplayState           State         = EReplayState::Finished;
    double                 TimeAccum     = 0.0;

    ReplayFrameCallback    OnFrameApplied;
};