#pragma once

#include <vector>

struct ReplayFrame
{
    ReplayFrameID FrameID = 0;

    double Timestamp = 0.0;

    InputSnapshot Input;

    std::vector<
        VehicleStateSnapshot
    > VehicleStates;
};
