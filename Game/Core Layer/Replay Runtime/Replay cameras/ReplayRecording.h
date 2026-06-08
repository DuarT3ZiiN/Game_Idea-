#pragma once

#include <vector>

class ReplayRecording
{
public:

    void AddFrame(
        const ReplayFrame& Frame
    );

    const ReplayFrame&
    GetFrame(
        uint64_t Index
    ) const;

    uint64_t GetFrameCount() const;

private:

    std::vector<
        ReplayFrame
    > Frames;
};
