#include "RuntimeBudgetManager.h"

void RuntimeBudgetManager::RegisterBudget(
    const std::string& SystemName,
    double BudgetMS
)
{
    Budgets[SystemName].AllocatedMS =
        BudgetMS;
}

bool RuntimeBudgetManager::CanExecute(
    const std::string& SystemName
) const
{
    auto It = Budgets.find(SystemName);

    if (It == Budgets.end())
        return true;

    return
        It->second.ConsumedMS
        <
        It->second.AllocatedMS;
}

void RuntimeBudgetManager::Consume(
    const std::string& SystemName,
    double DeltaMS
)
{
    Budgets[SystemName]
        .ConsumedMS += DeltaMS;
}

void RuntimeBudgetManager::ResetFrame()
{
    for (auto& Pair : Budgets)
    {
        Pair.second.ConsumedMS = 0.0;
    }
}

