#pragma once

#include <memory>
#include <vector>

#include "System.h"

class SystemScheduler
{
public:

    void RegisterSystem(std::shared_ptr<ISystem> System);

    void Execute(
        ECSWorld& World,
        ComponentStorage& Components,
        float DeltaTime
    );

private:

    std::vector<std::shared_ptr<ISystem>> Systems;
};
