#pragma once
 
#include "Archetype.h"
 
class ECSWorld;
class ComponentStorage;
 
// ISystem define a interface de todos os sistemas ECS.
//
// GetRequiredMask() permite ao SystemScheduler futuramente
// filtrar quais archetypes precisam ser processados por cada sistema,
// evitando execução desnecessária em entidades sem os componentes certos.
 
class ISystem
{
public:
 
    virtual ~ISystem() = default;
 
    virtual void Execute(
        ECSWorld&         World,
        ComponentStorage& Components,
        float             DeltaTime
    ) = 0;
 
    // Retorna a máscara de componentes que esse sistema requer.
    // Padrão: máscara vazia (sistema processa tudo).
    virtual ComponentMask GetRequiredMask() const
    {
        return ComponentMask{};
    }
};