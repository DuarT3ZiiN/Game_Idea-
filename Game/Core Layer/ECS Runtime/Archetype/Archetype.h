#pragma once

#include <bitset>

static constexpr uint32 MAX_COMPONENTS = 64;

using ComponentMask =
    std::bitset<MAX_COMPONENTS>;

struct Archetype
{
    ComponentMask Mask;
};