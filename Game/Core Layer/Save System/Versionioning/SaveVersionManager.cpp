#include "SaveVersionManager.h"

bool SaveVersionManager::IsCompatible(
    const SaveVersion& Version
)
{
    return Version.Major == 1;
}

SaveVersion
SaveVersionManager::GetCurrentVersion()
{
    SaveVersion Version;

    Version.Major = 1;
    Version.Minor = 0;
    Version.Build = 0;

    return Version;
}
