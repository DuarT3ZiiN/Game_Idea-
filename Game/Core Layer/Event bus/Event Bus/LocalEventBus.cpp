#include "LocalEventBus.h"
 
#include <cassert>
 
void LocalEventBus::RegisterRegion(uint32_t RegionID)
{
    RegionalBuses.emplace(RegionID, EventBus());
}
 
void LocalEventBus::UnregisterRegion(uint32_t RegionID)
{
    RegionalBuses.erase(RegionID);
}
 
bool LocalEventBus::HasRegion(uint32_t RegionID) const
{
    return RegionalBuses.count(RegionID) > 0;
}
 
EventBus& LocalEventBus::GetRegionBus(uint32_t RegionID)
{
    assert(HasRegion(RegionID) && "Região não registrada");
    return RegionalBuses.at(RegionID);
}
 
void LocalEventBus::ProcessAll()
{
    for (auto& [RegionID, Bus] : RegionalBuses)
    {
        Bus.ProcessEvents();
    }
}
 