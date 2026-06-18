#pragma once

struct MemoryMetrics
{
    uint64_t TotalMemoryMB = 0;

    uint64_t UsedMemoryMB = 0;

    uint64_t CachedMemoryMB = 0;

    uint64_t TextureMemoryMB = 0;

    uint64_t MeshMemoryMB = 0;

    uint64_t AudioMemoryMB = 0;
};