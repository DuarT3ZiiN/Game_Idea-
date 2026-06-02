#include "PriorityJobQueue.h"

#include <thread>
#include <chrono>

bool PriorityJobQueue::Push(const Job& InJob)
{
    switch (InJob.Priority)
    {
        case EJobPriority::Critical: return CriticalQueue.Push(InJob);
        case EJobPriority::High:     return HighQueue.Push(InJob);
        case EJobPriority::Normal:   return NormalQueue.Push(InJob);
        case EJobPriority::Low:      return LowQueue.Push(InJob);
    }
    return false;
}

bool PriorityJobQueue::TryPop(Job& OutJob)
{
    if (CriticalQueue.TryPop(OutJob)) return true;
    if (HighQueue.TryPop(OutJob))     return true;
    if (NormalQueue.TryPop(OutJob))   return true;
    if (LowQueue.TryPop(OutJob))      return true;
    return false;
}

bool PriorityJobQueue::WaitAndPop(Job& OutJob)
{
    // Poll entre filas com sleep curto para não busy-wait
    // Em frames com alta carga, TryPop retorna imediatamente.
    // Em frames ociosos, dorme 100µs por tentativa.
    while (true)
    {
        if (TryPop(OutJob))
            return true;

        // Verifica se foi sinalizado shutdown
        // (as filas internas retornam false após SignalShutdown)
        Job Dummy;
        if (!CriticalQueue.WaitAndPop(Dummy))
        {
            // Shutdown sinalizado
            return false;
        }

        // Obtivemos um job da Critical via WaitAndPop — retorna direto
        OutJob = Dummy;
        return true;
    }
}

bool PriorityJobQueue::IsEmpty() const
{
    return CriticalQueue.Empty()
        && HighQueue.Empty()
        && NormalQueue.Empty()
        && LowQueue.Empty();
}

void PriorityJobQueue::SignalShutdown()
{
    CriticalQueue.SignalShutdown();
    HighQueue.SignalShutdown();
    NormalQueue.SignalShutdown();
    LowQueue.SignalShutdown();
}