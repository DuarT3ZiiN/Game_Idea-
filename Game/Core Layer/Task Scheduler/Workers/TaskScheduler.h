#pragma once

#include <cstdint>
#include <thread>

#include "PriorityJobQueue.h"
#include "WorkerPool.h"
#include "RuntimeBudgetManager.h"
#include "DependencyGraph.h"
#include "PerformanceMonitor.h"

// TaskScheduler — ponto de entrada do Task Scheduler (seção 3.4).
//
// Melhorias em relação à versão anterior:
//   - Initialize detecta o número de hardware threads se WorkerCount == 0
//   - Shutdown() propaga SignalShutdown para acordar workers bloqueados
//   - SubmitBatch() submete múltiplos jobs de uma vez (lock único)
//   - EndFrame() chama BudgetManager.ResetFrame() e Monitor.ResetPeaks()
//   - GetPerformanceMonitor() expõe métricas para Debug Tools (3.13)

class TaskScheduler
{
public:

    // WorkerCount = 0 → usa std::thread::hardware_concurrency() - 1
    void Initialize(uint32_t WorkerCount = 0);

    void Shutdown();

    // Submete um único job
    bool Submit(const Job& InJob);

    // Submete múltiplos jobs em sequência
    void SubmitBatch(const Job* Jobs, uint32_t Count);

    // Deve ser chamado no fim de cada frame
    void EndFrame();

    // Acesso para integração com Debug Tools (3.13)
    PerformanceMonitor&       GetPerformanceMonitor();
    RuntimeBudgetManager&     GetBudgetManager();

private:

    PriorityJobQueue    Queue;
    WorkerPool          Workers;
    RuntimeBudgetManager BudgetManager;
    DependencyGraph     Dependencies;
    PerformanceMonitor  Profiler;

    bool bInitialized = false;
};