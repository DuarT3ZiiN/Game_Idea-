#include "ReplayRecording.h"

void ReplayRecording::AddFrame(
    const ReplayFrame& Frame
)
{
    Frames.push_back(Frame);
}

const ReplayFrame&
ReplayRecording::GetFrame(
    uint64_t Index
) const
{
    return Frames[Index];
}

uint64_t
ReplayRecording::GetFrameCount() const
{
    return Frames.size();
}
