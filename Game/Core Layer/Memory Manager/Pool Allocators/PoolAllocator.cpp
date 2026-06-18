#include "PoolAllocator.h"

PoolAllocator::PoolAllocator(
    size_t InElementSize,
    size_t InCapacity
)
{
    ElementSize = InElementSize;
    Capacity = InCapacity;

    MemoryBlock =
        new uint8_t[
            ElementSize * Capacity
        ];

    for (
        size_t i = 0;
        i < Capacity;
        ++i
    )
    {
        FreeList.push_back(
            MemoryBlock +
            (i * ElementSize)
        );
    }
}

PoolAllocator::~PoolAllocator()
{
    delete[] MemoryBlock;
}

void* PoolAllocator::Allocate()
{
    if (FreeList.empty())
    {
        return nullptr;
    }

    void* Result =
        FreeList.back();

    FreeList.pop_back();

    return Result;
}

void PoolAllocator::Free(
    void* Ptr
)
{
    FreeList.push_back(
        Ptr
    );
}

