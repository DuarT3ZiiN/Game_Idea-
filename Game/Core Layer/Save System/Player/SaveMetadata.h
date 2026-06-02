#pragma once

#include <string>

#include "SaveVersion.h"

struct SaveMetadata
{
    SaveSlotID SlotID = 0;

    std::string SaveName;

    std::string Timestamp;

    SaveVersion Version;

    uint64_t PlayTimeSeconds = 0;
};
