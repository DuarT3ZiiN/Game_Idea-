#pragma once

#include <cstdint>
#include <vector>

struct DistrictState
{
    uint32_t DistrictID;

    bool IsUnlocked;
};

struct WorldSaveData
{
    uint64_t WorldSeed = 0;

    uint64_t CurrentTime = 0;

    std::vector<DistrictState>
        Districts;
};
