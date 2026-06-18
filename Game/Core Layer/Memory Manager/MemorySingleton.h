#pragma once

class Memory
{
public:

    static GlobalAllocator&
    Get()
    {
        static GlobalAllocator
            Instance;

        return Instance;
    }
};
