#pragma once

#include <vector>

#include "JobDependency.h"

class DependencyGraph
{
public:

    void AddDependency(
        JobID Parent,
        JobID Child
    );

    bool HasDependency(
        JobID Parent,
        JobID Child
    ) const;

private:

    std::vector<JobDependency>
        Dependencies;
};

