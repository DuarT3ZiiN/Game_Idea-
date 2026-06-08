#pragma once

class ReplayPlaybackRuntime
{
public:

    void Start(
        const ReplayRecording* Replay
    );

    void Pause();

    void Resume();

    void Stop();

    void Tick(
        double DeltaTime
    );

private:

    const ReplayRecording*
        Recording = nullptr;

    uint64_t CurrentFrame = 0;

    EReplayState State =
        EReplayState::Finished;
};


