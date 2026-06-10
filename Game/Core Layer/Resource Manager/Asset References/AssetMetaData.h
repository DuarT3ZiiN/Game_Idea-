#pragma once

#include <string>

struct AssetMetadata
{
    uint64_t FileSize = 0;

    uint64_t MemoryUsage = 0;

    std::string ImportDate;

    uint32_t Version = 1;
};
