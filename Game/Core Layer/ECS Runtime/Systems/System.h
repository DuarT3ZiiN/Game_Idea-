#pragma once

class ECSWorld;
class ComponentStorage;

class ISystem
{
public:

    virtual ~ISystem() = default;

    virtual void Execute(
        ECSWorld& World,
        ComponentStorage& Components,
        float DeltaTime
    ) = 0;
};
