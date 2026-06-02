
#pragma once

#include <cstdint>

enum class EAsyncJobState : uint8_t
{
    Pending,
    Queued,
    Running,
    Completed,
    Failed,
    Cancelled
};
