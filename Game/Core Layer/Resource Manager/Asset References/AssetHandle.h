#pragma once

#include "AssetID.h"

struct AssetHandle
{
    AssetID ID = 0;

    bool IsValid() const
    {
        return ID != 0;
    }
};
