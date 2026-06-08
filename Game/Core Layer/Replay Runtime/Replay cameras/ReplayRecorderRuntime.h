#pragma once

#include "ReplayRecording.h"
#include "InputRecorder.h"
#include "StateRecorder.h"

class ReplayRecorderRuntime
{
public:

    void StartRecording();

    void StopRecording();

    void Tick(
        double Timestamp
    );

    const ReplayRecording&
    GetRecording() const;

private:

    ReplayRecording Recording;

    InputRecorder InputCapture;

    StateRecorder StateCapture;

    bool bRecording = false;
};


