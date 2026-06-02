#pragma once

#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "JobDependency.h"

// DependencyGraph rastreia dependências entre Jobs.
//
// Melhorias em relação à versão anterior:
//   - IsJobReady(ID) — verifica se todas as dependências de um job foram satisfeitas
//   - MarkCompleted(ID) — registra que um job foi concluído
//   - GetReadyJobs() — retorna jobs cujas dependências foram todas satisfeitas
//   - Clear() — reseta para novo frame/fase

class DependencyGraph
{
public:

    void AddDependency(JobID Parent, JobID Child);

    bool HasDependency(JobID Parent, JobID Child) const;

    // Marca um job como concluído — desbloqueia seus filhos
    void MarkCompleted(JobID CompletedJob);

    // Retorna true se todas as dependências do job foram concluídas
    bool IsJobReady(JobID Job) const;

    // Retorna todos os jobs que estão prontos (sem dependências pendentes)
    std::vector<JobID> GetReadyJobs(const std::vector<JobID>& PendingJobs) const;

    void Clear();

private:

    std::vector<JobDependency>           Dependencies;

    // Jobs que já foram concluídos neste ciclo
    std::unordered_set<JobID>            CompletedJobs;
};