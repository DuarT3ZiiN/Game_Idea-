#include "PriorityJobQueue.h"

void PriorityJobQueue::Push(
    const Job& InJob
)
{
    switch (InJob.Priority)
    {
        case EJobPriority::Critical:
            CriticalQueue.Push(InJob);
            break;

        case EJobPriority::High:
            HighQueue.Push(InJob);
            break;

        case EJobPriority::Normal:
            NormalQueue.Push(InJob);
            break;

        case EJobPriority::Low:
            LowQueue.Push(InJob);
            break;
    }
}

bool PriorityJobQueue::Pop(
    Job& OutJob
)
{
    if (CriticalQueue.Pop(OutJob))
        return true;

    if (HighQueue.Pop(OutJob))
        return true;

    if (NormalQueue.Pop(OutJob))
        return true;

    if (LowQueue.Pop(OutJob))
        return true;

    return false;
}

