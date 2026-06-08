#pragma once

#include <cstdint>

using SaveSlotID = uint32_t;

static constexpr SaveSlotID INVALID_SAVE_SLOT = UINT32_MAX;
static constexpr uint32_t   MAX_SAVE_SLOTS    = 10;