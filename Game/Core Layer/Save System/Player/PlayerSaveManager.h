
#pragma once

#include "SaveGame.h"

class PlayerSaveManager
{
public:

    void CapturePlayerState(
        SaveGame& Save
    );

    void RestorePlayerState(
        const SaveGame& Save
    );
};