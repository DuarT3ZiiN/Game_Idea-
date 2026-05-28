#pragma once

#include "EventBus.h"

class LocalEventBus
{
public:

    void RegisterRegion(
        uint32_t RegionID
    );

    EventBus& GetRegionBus(
        uint32_t RegionID
    );

private:

    std::unordered_map<
        uint32_t,
        EventBus
    > RegionalBuses;
};

