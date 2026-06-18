#pragma once

#include <vector>

class PoolAllocator
{
public:

    PoolAllocator(
        size_t ElementSize,
        size_t Capacity
    );

    ~PoolAllocator();

    void* Allocate();

    void Free(
        void* Ptr
    );

private:

    size_t ElementSize;

    size_t Capacity;

    uint8_t* MemoryBlock;

    std::vector<void*> FreeList;
};
