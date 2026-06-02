#include "DependencyGraph.h"

#include <algorithm>

void DependencyGraph::AddDependency(JobID Parent, JobID Child)
{
    Dependencies.push_back({ Parent, Child });
}

bool DependencyGraph::HasDependency(JobID Parent, JobID Child) const
{
    for (const auto& Dep : Dependencies)
    {
        if (Dep.ParentJob == Parent && Dep.ChildJob == Child)
            return true;
    }
    return false;
}

void DependencyGraph::MarkCompleted(JobID CompletedJob)
{
    CompletedJobs.insert(CompletedJob);
}

bool DependencyGraph::IsJobReady(JobID Job) const
{
    for (const auto& Dep : Dependencies)
    {
        if (Dep.ChildJob != Job)
            continue;

        // Se algum parent ainda não foi concluído, o job não está pronto
        if (CompletedJobs.count(Dep.ParentJob) == 0)
            return false;
    }

    return true;
}

std::vector<JobID> DependencyGraph::GetReadyJobs(
    const std::vector<JobID>& PendingJobs
) const
{
    std::vector<JobID> Ready;

    for (JobID ID : PendingJobs)
    {
        if (IsJobReady(ID))
            Ready.push_back(ID);
    }

    return Ready;
}

void DependencyGraph::Clear()
{
    Dependencies.clear();
    CompletedJobs.clear();
}