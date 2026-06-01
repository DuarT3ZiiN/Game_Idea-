#include "DependencyGraph.h"

void DependencyGraph::AddDependency(
    JobID Parent,
    JobID Child
)
{
    Dependencies.push_back(
        { Parent, Child }
    );
}

bool DependencyGraph::HasDependency(
    JobID Parent,
    JobID Child
) const
{
    for (const auto& Dependency :
         Dependencies)
    {
        if (
            Dependency.ParentJob
            == Parent
            &&
            Dependency.ChildJob
            == Child
        )
        {
            return true;
        }
    }

    return false;
}

