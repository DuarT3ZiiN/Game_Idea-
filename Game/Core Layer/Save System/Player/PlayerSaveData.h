#pragma once

#include <cstdint>
#include <string>
#include <vector>

struct PlayerSaveData
{
    std::string PlayerName;

    uint64_t Money = 0;

    uint32_t Reputation = 0;

    uint32_t Level = 1;

    uint32_t HeatLevel = 0;

    std::vector<uint64_t> OwnedCars;

    std::vector<uint64_t> UnlockedEvents;

    std::vector<uint64_t> CompletedEvents;
};
