#pragma once

struct StreamingStatistics
{
    uint64_t LoadedAssets = 0;

    uint64_t PendingLoads = 0;

    uint64_t ActiveDistricts = 0;

    uint64_t StreamedTextures = 0;

    uint64_t StreamedAudio = 0;

    uint64_t MemoryUsageMB = 0;
};
