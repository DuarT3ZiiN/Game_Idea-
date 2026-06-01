#include "SystemScheduler.h"
 
#include <algorithm>
 
void SystemScheduler::RegisterSystem(
    std::shared_ptr<ISystem> System,
    const std::string&       Name,
    int32_t                  Priority
)
{
    SystemEntry Entry;
    Entry.Name     = Name;
    Entry.System   = std::move(System);
    Entry.Priority = Priority;
    Entry.bEnabled = true;
 
    Systems.push_back(std::move(Entry));
    bSorted = false;
}
 
void SystemScheduler::EnableSystem(const std::string& Name)
{
    for (auto& Entry : Systems)
    {
        if (Entry.Name == Name)
        {
            Entry.bEnabled = true;
            return;
        }
    }
}
 
void SystemScheduler::DisableSystem(const std::string& Name)
{
    for (auto& Entry : Systems)
    {
        if (Entry.Name == Name)
        {
            Entry.bEnabled = false;
            return;
        }
    }
}
 
void SystemScheduler::Execute(
    ECSWorld&         World,
    ComponentStorage& Components,
    float             DeltaTime
)
{
    SortIfNeeded();
 
    for (auto& Entry : Systems)
    {
        if (!Entry.bEnabled)
            continue;
 
        Entry.System->Execute(World, Components, DeltaTime);
    }
}
 
void SystemScheduler::SortIfNeeded()
{
    if (bSorted)
        return;
 
    std::stable_sort(
        Systems.begin(),
        Systems.end(),
        [](const SystemEntry& A, const SystemEntry& B)
        {
            return A.Priority < B.Priority;
        }
    );
 
    bSorted = true;
}
 