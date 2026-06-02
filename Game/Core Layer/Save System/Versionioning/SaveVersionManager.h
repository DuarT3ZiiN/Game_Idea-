#pragma once

#include "SaveVersion.h"

class SaveVersionManager
{
public:

    static bool IsCompatible(
        const SaveVersion& Version
    );

    static SaveVersion
    GetCurrentVersion();
};
