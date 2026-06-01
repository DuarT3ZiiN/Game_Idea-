#pragma once
 
#include <memory>
#include <vector>
#include <string>
 
#include "System.h"
 
// SystemScheduler executa os sistemas registrados em ordem.
//
// Melhorias em relação à versão anterior:
//   - Nome por sistema (facilita debug e profiling)
//   - Enable/Disable individual sem remover o sistema
//   - Ordem de execução explícita via priority (menor = primeiro)
 
struct SystemEntry
{
    std::string              Name;
    std::shared_ptr<ISystem> System;
    int32_t                  Priority = 0;
    bool                     bEnabled = true;
};
 
class SystemScheduler
{
public:
 
    // Registra sistema com nome e prioridade de execução
    void RegisterSystem(
        std::shared_ptr<ISystem> System,
        const std::string&       Name,
        int32_t                  Priority = 0
    );
 
    void EnableSystem(const std::string& Name);
    void DisableSystem(const std::string& Name);
 
    void Execute(
        ECSWorld&         World,
        ComponentStorage& Components,
        float             DeltaTime
    );
 
private:
 
    std::vector<SystemEntry> Systems;
    bool                     bSorted = false;
 
    void SortIfNeeded();
};