#pragma once
 
#include <functional>
#include <atomic>
 
#include "JobID.h"
#include "JobPriority.h"
 
// Job representa uma unidade de trabalho do Task Scheduler.
//
// Melhorias em relação à versão anterior:
//   - ID gerado automaticamente se não fornecido (evita colisões manuais)
//   - OnComplete callback — chamado pela WorkerThread após Execute()
//     (usado para notificar sistemas dependentes sem usar DependencyGraph)
//   - bCompleted flag atômica — permite polling de conclusão no main thread
 
struct Job
{
    JobID        ID        = GenerateJobID();
    EJobPriority Priority  = EJobPriority::Normal;
    const char*  DebugName = "";
 
    std::function<void()> Execute;
 
    // Chamado na WorkerThread após Execute — use para encadear jobs
    // ou notificar sistemas. Deve ser thread-safe.
    std::function<void(JobID)> OnComplete;
 
    // Lido pelo main thread para verificar conclusão sem bloquear
    std::shared_ptr<std::atomic<bool>> bCompleted =
        std::make_shared<std::atomic<bool>>(false);
};
 