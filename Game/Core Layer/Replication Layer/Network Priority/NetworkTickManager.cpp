#include "NetworkTickManager.h"

NetworkTickManager::NetworkTickManager(uint32_t InTickRate)
    : TickRate(InTickRate)
{
}

uint32_t NetworkTickManager::Tick(double DeltaTime)
{
    TimeAccumulator += DeltaTime;

    const double Interval   = GetTickIntervalSeconds();
    uint32_t     TicksFired = 0;

    while (TimeAccumulator >= Interval)
    {
        TimeAccumulator -= Interval;
        ++CurrentTick;
        ++TicksFired;
    }

    return TicksFired;
}