#pragma once

#include "System.h"

class NitroSystem : public ISystem
{
public:

    virtual void Execute(
        ECSWorld& World,
        ComponentStorage& Components,
        float DeltaTime
    ) override;
};
