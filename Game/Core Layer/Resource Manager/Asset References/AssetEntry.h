#pragma once

#include "AssetReference.h"
#include "AssetMetadata.h"

struct AssetEntry
{
    AssetReference Reference;

    AssetMetadata Metadata;

    void* RuntimeData = nullptr;
};
