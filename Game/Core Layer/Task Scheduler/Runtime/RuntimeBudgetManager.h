#pragma once

#include <unordered_map>
#include <string>

#include "RuntimeBudget.h"

// RuntimeBudgetManager controla o budget de tempo por sistema (seção 3.4.3).
//
// Melhorias em relação à versão anterior:
//   - IsOverBudget() — consulta rápida para o TaskScheduler decidir
//     se deve executar jobs de baixa prioridade neste frame
//   - GetBudget() — acesso de leitura ao budget completo
//   - ResetFrame() atualiza bOverBudget e OverFrames

class RuntimeBudgetManager
{
public:

    void RegisterBudget(const std::string& SystemName, double BudgetMS);

    bool CanExecute    (const std::string& SystemName) const;
    bool IsOverBudget  (const std::string& SystemName) const;

    void Consume(const std::string& SystemName, double DeltaMS);

    const RuntimeBudget* GetBudget(const std::string& SystemName) const;

    // Deve ser chamado uma vez por frame antes de submeter novos jobs
    void ResetFrame();

private:

    std::unordered_map<std::string, RuntimeBudget> Budgets;
};