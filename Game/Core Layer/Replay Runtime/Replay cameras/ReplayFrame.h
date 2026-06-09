#pragma once

#include <vector>

#include "ReplayFrameID.h"
#include "InputSnapshot.h"
#include "VehicleStateSnapshot.h"

struct ReplayFrame
{
    ReplayFrameID FrameID   = 0;
    double        Timestamp = 0.0;

    InputSnapshot                     Input;
    std::vector<VehicleStateSnapshot> VehicleStates;
};