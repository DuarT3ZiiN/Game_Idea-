#pragma once

#include "AssetReference.h"

class ResourceLoader
{
public:

    void* Load(
        const AssetReference&
        Reference
    );

    void Unload(
        AssetID ID
    );
};
