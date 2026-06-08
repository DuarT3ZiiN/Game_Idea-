#pragma once

struct ReplayHeader
{
    uint32_t Version = 1;

    uint64_t FrameCount = 0;

    uint64_t DurationMS = 0;
};