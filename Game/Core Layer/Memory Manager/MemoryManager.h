#pragma once

class MemoryManager
{
public:

    void Initialize();

    void Shutdown();

    void Update();

private:

    PoolManager Pools;

    StreamingMemoryManager
        StreamingMemory;
};
