#pragma once

class NetworkTickManager
{
public:

    void Tick();

    TickID GetCurrentTick() const;

private:

    TickID CurrentTick = 0;
};

