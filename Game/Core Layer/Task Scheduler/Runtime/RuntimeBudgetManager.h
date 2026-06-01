#pragma once

#include <unordered_map>
#include <string>

#include "RuntimeBudget.h"

class RuntimeBudgetManager
{
public:

    void RegisterBudget(
        const std::string& SystemName,
        double BudgetMS
    );

    bool CanExecute(
        const std::string& SystemName
    ) const;

    void Consume(
        const std::string& SystemName,
        double DeltaMS
    );

    void ResetFrame();

private:

    std::unordered_map<
        std::string,
        RuntimeBudget
    > Budgets;
};


