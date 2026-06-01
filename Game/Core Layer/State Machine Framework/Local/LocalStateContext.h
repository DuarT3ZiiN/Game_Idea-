
#pragma once

#include <unordered_set>

#include "LocalStates.h"

struct LocalStateContext
{
    std::unordered_set<ELocalState> ActiveStates;
};

