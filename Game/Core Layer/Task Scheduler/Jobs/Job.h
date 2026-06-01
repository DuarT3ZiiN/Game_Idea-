#pragma once

#include <functional>

#include "JobPriority.h"

struct Job
{
    JobID ID = 0;

    EJobPriority Priority =
        EJobPriority::Normal;

    const char* DebugName = "";

    std::function<void()> Execute;
};