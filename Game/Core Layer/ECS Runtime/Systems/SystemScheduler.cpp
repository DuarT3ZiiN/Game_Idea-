#include "SystemScheduler.h"

void SystemScheduler::RegisterSystem(
    std::shared_ptr<ISystem> System
)
{
    Systems.push_back(System);
}

void SystemScheduler::Execute(
    ECSWorld& World,
    ComponentStorage& Components,
    float DeltaTime
)
{
    for (auto& System : Systems)
    {
        System->Execute(
            World,
            Components,
            DeltaTime
        );
    }
}
