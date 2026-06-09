#pragma once

#include <cstdint>

enum class ENetworkPriority : uint8_t
{
    Critical,
    High,
    Normal,
    Low,
    Background
};