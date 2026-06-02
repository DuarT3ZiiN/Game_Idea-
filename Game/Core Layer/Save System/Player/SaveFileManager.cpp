#include "SaveFileManager.h"

bool SaveFileManager::SaveToDisk(
    const SaveGame& Save,
    const std::string& Path
)
{
    std::ofstream File(
        Path,
        std::ios::binary
    );

    if (!File.is_open())
        return false;

    File.write(
        reinterpret_cast<
            const char*
        >(&Save),
        sizeof(SaveGame)
    );

    return true;
}

bool SaveFileManager::LoadFromDisk(
    SaveGame& Save,
    const std::string& Path
)
{
    std::ifstream File(
        Path,
        std::ios::binary
    );

    if (!File.is_open())
        return false;

    File.read(
        reinterpret_cast<
            char*
        >(&Save),
        sizeof(SaveGame)
    );

    return true;
}
