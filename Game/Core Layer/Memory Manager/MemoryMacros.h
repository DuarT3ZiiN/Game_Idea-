#pragma once

#define MEMORY_ALLOC(Size, Category) \
Memory::Get().Allocate(              \
    Size,                            \
    Category,                        \
    __FILE__,                        \
    __LINE__                         \
)

#define MEMORY_FREE(Address) \
Memory::Get().Free(Address)

