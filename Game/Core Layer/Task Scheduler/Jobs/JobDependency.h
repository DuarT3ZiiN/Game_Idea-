#pragma once

#include "JobID.h"

struct JobDependency
{
     JobID ParentJob = INVALID_JOB;
    JobID ChildJob  = INVALID_JOB;
    
};
