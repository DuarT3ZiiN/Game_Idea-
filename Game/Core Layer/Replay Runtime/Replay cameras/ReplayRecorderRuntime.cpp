#include "ReplayRecorderRuntime.h"

void ReplayRecorderRuntime::StartRecording()
{
    bRecording = true;
}

void ReplayRecorderRuntime::StopRecording()
{
    bRecording = false;
}

void ReplayRecorderRuntime::Tick(
    double Timestamp
)
{
    if (!bRecording)
        return;

    ReplayFrame Frame;

    Frame.Timestamp =
        Timestamp;

    Frame.Input =
        InputCapture.Capture();

    StateCapture
        .CaptureVehicles(Frame);

    Recording.AddFrame(Frame);
}

const ReplayRecording&
ReplayRecorderRuntime::GetRecording() const
{
    return Recording;
}

