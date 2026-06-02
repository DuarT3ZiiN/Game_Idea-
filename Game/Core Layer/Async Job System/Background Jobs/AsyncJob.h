
#pragma once

#include <functional>

#include "AsyncJobTypes.h"
#include "AsyncJobState.h"

struct AsyncJob
{
    AsyncJobID ID = 0;

    EAsyncJobType Type =
        EAsyncJobType::Background;

    EAsyncJobState State =
        EAsyncJobState::Pending;

    const char* DebugName = "";

    std::function<void()> Execute;
};

