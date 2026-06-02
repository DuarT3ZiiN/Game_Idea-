#pragma once

#include <string>

#include "SaveGame.h"

class SaveFileManager
{
public:

    bool SaveToDisk(
        const SaveGame& Save,
        const std::string& Path
    );

    bool LoadFromDisk(
        SaveGame& Save,
        const std::string& Path
    );
};
