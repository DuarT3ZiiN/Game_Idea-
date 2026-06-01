#pragma once

#include <cstdint>

enum class EJobPriority : uint8_t
{
    Critical,
    High,
    Normal,
    Low
};