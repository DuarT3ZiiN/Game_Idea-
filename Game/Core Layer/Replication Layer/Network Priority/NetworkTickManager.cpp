#include "NetworkTickManager.h"

void NetworkTickManager::Tick()
{
    CurrentTick++;
}

TickID
NetworkTickManager::GetCurrentTick() const
{
    return CurrentTick;
}