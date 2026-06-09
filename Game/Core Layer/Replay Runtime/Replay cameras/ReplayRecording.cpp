#include "ReplayRecording.h"

void ReplayRecording::AddFrame(const ReplayFrame& Frame)
{
    if (IsFull())
        return;

    Frames.push_back(Frame);

    Header.FrameCount = Frames.size();

    if (!Frames.empty())
        Header.DurationMS = static_cast<uint64_t>(
            Frames.back().Timestamp * 1000.0
        );
}

const ReplayFrame& ReplayRecording::GetFrame(uint64_t Index) const
{
    assert(Index < Frames.size() && "ReplayFrame index fora dos limites");
    return Frames[static_cast<size_t>(Index)];
}

uint64_t ReplayRecording::GetFrameIndexByTimestamp(
    double TimestampSeconds
) const
{
    if (Frames.empty())
        return 0;

    // Busca binária pelo timestamp mais próximo
    uint64_t Lo = 0;
    uint64_t Hi = Frames.size() - 1;

    while (Lo < Hi)
    {
        const uint64_t Mid = (Lo + Hi) / 2;

        if (Frames[static_cast<size_t>(Mid)].Timestamp < TimestampSeconds)
            Lo = Mid + 1;
        else
            Hi = Mid;
    }

    return Lo;
}

uint64_t ReplayRecording::GetFrameCount() const
{
    return static_cast<uint64_t>(Frames.size());
}

bool ReplayRecording::IsFull() const
{
    return Frames.size() >= REPLAY_MAX_FRAMES;
}