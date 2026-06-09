#include "ReplayPlaybackRuntime.h"

void ReplayPlaybackRuntime::Start(const ReplayRecording* Replay)
{
    Recording    = Replay;
    CurrentFrame = 0;
    TimeAccum    = 0.0;
    State        = EReplayState::Playback;
}

void ReplayPlaybackRuntime::Pause()
{
    if (State == EReplayState::Playback)
        State = EReplayState::Paused;
}

void ReplayPlaybackRuntime::Resume()
{
    if (State == EReplayState::Paused)
        State = EReplayState::Playback;
}

void ReplayPlaybackRuntime::Stop()
{
    State = EReplayState::Finished;
}

void ReplayPlaybackRuntime::Scrub(double TimestampSeconds)
{
    if (!Recording)
        return;

    CurrentFrame = Recording->GetFrameIndexByTimestamp(TimestampSeconds);
    State        = EReplayState::Scrubbing;
}

void ReplayPlaybackRuntime::Tick(double DeltaTime)
{
    if (!Recording)
        return;

    if (State == EReplayState::Scrubbing)
    {
        // Em scrubbing, aplica exatamente o frame atual sem avançar
        if (CurrentFrame < Recording->GetFrameCount())
        {
            const ReplayFrame& Frame = Recording->GetFrame(CurrentFrame);
            if (OnFrameApplied)
                OnFrameApplied(Frame);
        }
        return;
    }

    if (State != EReplayState::Playback)
        return;

    TimeAccum += DeltaTime * static_cast<double>(PlaybackSpeed);

    // Avança frames enquanto o tempo acumulado cobrir timestamps
    while (CurrentFrame < Recording->GetFrameCount())
    {
        const ReplayFrame& Frame = Recording->GetFrame(CurrentFrame);

        if (Frame.Timestamp > TimeAccum)
            break;

        if (OnFrameApplied)
            OnFrameApplied(Frame);

        ++CurrentFrame;
    }

    if (CurrentFrame >= Recording->GetFrameCount())
        Stop();
}

void ReplayPlaybackRuntime::SetOnFrameApplied(ReplayFrameCallback Callback)
{
    OnFrameApplied = std::move(Callback);
}

float ReplayPlaybackRuntime::GetProgress() const
{
    if (!Recording || Recording->GetFrameCount() == 0)
        return 0.f;

    return static_cast<float>(CurrentFrame)
         / static_cast<float>(Recording->GetFrameCount());
}