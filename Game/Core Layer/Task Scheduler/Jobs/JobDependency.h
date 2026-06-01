#pragma once

#include "JobID.h"

struct JobDependency
{
    JobID ParentJob = 0;

    JobID ChildJob = 0;
};
