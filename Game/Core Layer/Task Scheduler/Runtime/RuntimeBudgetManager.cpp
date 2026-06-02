#include "RuntimeBudgetManager.h"

void RuntimeBudgetManager::RegisterBudget(
    const std::string& SystemName,
    double             BudgetMS
)
{
    Budgets[SystemName].AllocatedMS = BudgetMS;
}

bool RuntimeBudgetManager::CanExecute(
    const std::string& SystemName
) const
{
    auto It = Budgets.find(SystemName);

    if (It == Budgets.end())
        return true; // sistema sem budget registrado sempre pode executar

    return It->second.ConsumedMS < It->second.AllocatedMS;
}

bool RuntimeBudgetManager::IsOverBudget(
    const std::string& SystemName
) const
{
    auto It = Budgets.find(SystemName);

    if (It == Budgets.end())
        return false;

    return It->second.bOverBudget;
}

void RuntimeBudgetManager::Consume(
    const std::string& SystemName,
    double             DeltaMS
)
{
    Budgets[SystemName].ConsumedMS += DeltaMS;
}

const RuntimeBudget* RuntimeBudgetManager::GetBudget(
    const std::string& SystemName
) const
{
    auto It = Budgets.find(SystemName);

    if (It == Budgets.end())
        return nullptr;

    return &It->second;
}

void RuntimeBudgetManager::ResetFrame()
{
    for (auto& [Name, Budget] : Budgets)
    {
        Budget.bOverBudget = Budget.ConsumedMS > Budget.AllocatedMS;

        if (Budget.bOverBudget)
            ++Budget.OverFrames;
        else
            Budget.OverFrames = 0;

        Budget.ConsumedMS = 0.0;
    }
}