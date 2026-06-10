#pragma once

#include <cstdint>

enum class EAssetType : uint8_t
{
    Unknown,

    Texture,
    Material,
    Mesh,
    Skeleton,
    Animation,

    Sound,
    Music,

    Vehicle,

    VFX,

    UI,

    District,

    Replay,

    Script
};
