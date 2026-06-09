#pragma once

#include "ReplayRecording.h"
#include "InputRecorder.h"
#include "StateRecorder.h"

class ECSWorld;
class ComponentStorage;

// ReplayRecorderRuntime coordena a gravação frame a frame.
//
// Melhorias em relação à versão anterior:
//   - Tick() recebe ECSWorld e ComponentStorage para captura real do ECS
//   - GetState() / IsRecording() para consulta externa
//   - FrameCounter monotônico para IDs únicos por frame
//   - StopRecording() retorna const ref para o recording completo

class ReplayRecorderRuntime
{
public:

    void StartRecording();

    const ReplayRecording& StopRecording();

    void Tick(
        double            Timestamp,
        ECSWorld&         World,
        ComponentStorage& Components
    );

    const ReplayRecording& GetRecording() const;

    EReplayState GetState()     const { return bRecording ? EReplayState::Recording : EReplayState::Finished; }
    bool         IsRecording()  const { return bRecording; }

private:

    ReplayRecording Recording;
    InputRecorder   InputCapture;
    StateRecorder   StateCapture;

    bool     bRecording    = false;
    uint64_t FrameCounter  = 0;
};