#include "LocalEventBus.h"

void LocalEventBus::RegisterRegion(
    uint32_t RegionID
)
{
    RegionalBuses.emplace(
        RegionID,
        EventBus()
    );
}

EventBus& LocalEventBus::GetRegionBus(
    uint32_t RegionID
)
{
    return RegionalBuses[RegionID];
}