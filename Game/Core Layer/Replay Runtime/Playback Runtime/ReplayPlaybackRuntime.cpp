#include "ReplayPlaybackRuntime.h"

void ReplayPlaybackRuntime::Start(
    const ReplayRecording* Replay
)
{
    Recording = Replay;

    CurrentFrame = 0;

    State =
        EReplayState::Playback;
}

void ReplayPlaybackRuntime::Pause()
{
    State =
        EReplayState::Paused;
}

void ReplayPlaybackRuntime::Resume()
{
    State =
        EReplayState::Playback;
}

void ReplayPlaybackRuntime::Stop()
{
    State =
        EReplayState::Finished;
}

void ReplayPlaybackRuntime::Tick(
    double DeltaTime
)
{
    if (State !=
        EReplayState::Playback)
    {
        return;
    }

    if (!Recording)
        return;

    if (CurrentFrame >=
        Recording->GetFrameCount())
    {
        Stop();

        return;
    }

    const ReplayFrame& Frame =
        Recording->GetFrame(
            CurrentFrame
        );

    // aplicar snapshots

    CurrentFrame++;
}

