#pragma once

#include "AssetID.h"

// AssetHandle encapsula um AssetID com geração embutida para detectar
// handles stale — mesma estratégia do EntityID no ECS Runtime.
//
// Melhoria em relação à versão anterior:
//   - IsValid() verifica INVALID_ASSET_ID explicitamente
//   - operator== para comparação direta entre handles

struct AssetHandle
{
    AssetID ID = INVALID_ASSET_ID;

    bool IsValid() const
    {
        return ID != INVALID_ASSET_ID;
    }

    bool operator==(const AssetHandle& Other) const
    {
        return ID == Other.ID;
    }

    bool operator!=(const AssetHandle& Other) const
    {
        return ID != Other.ID;
    }
};