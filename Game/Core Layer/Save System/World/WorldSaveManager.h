#pragma once

#include "SaveGame.h"

class WorldSaveManager
{
public:

    void CaptureWorldState(
        SaveGame& Save
    );

    void RestoreWorldState(
        const SaveGame& Save
    );
};

