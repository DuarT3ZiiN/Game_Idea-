#include "ReplayRecorderRuntime.h"

#include "ECSWorld.h"
#include "ComponentStorage.h"

void ReplayRecorderRuntime::StartRecording()
{
    bRecording   = true;
    FrameCounter = 0;
    Recording    = ReplayRecording{};
}

const ReplayRecording& ReplayRecorderRuntime::StopRecording()
{
    bRecording = false;
    return Recording;
}

void ReplayRecorderRuntime::Tick(
    double            Timestamp,
    ECSWorld&         World,
    ComponentStorage& Components
)
{
    if (!bRecording || Recording.IsFull())
        return;

    ReplayFrame Frame;
    Frame.FrameID   = FrameCounter++;
    Frame.Timestamp = Timestamp;

    // Captura input do veículo do jogador (EntityID 1 como convenção por ora)
    // TODO: receber PlayerEntityID como parâmetro quando PlayerManager existir
    Frame.Input = InputCapture.Capture(Frame.FrameID, Timestamp);

    // Captura estado de todos os veículos via ECS
    StateCapture.CaptureVehicles(Frame, World, Components);

    Recording.AddFrame(Frame);
}

const ReplayRecording& ReplayRecorderRuntime::GetRecording() const
{
    return Recording;
}