#pragma once
 
#include "SparseSet.h"
#include "TransformComponent.h"
#include "VelocityComponent.h"
#include "VehicleInputComponent.h"
#include "NitroComponent.h"
#include "DamageComponent.h"
 
// ComponentStorage centraliza todos os SparseSets do jogo.
// Novos tipos de componente: adicione um SparseSet aqui.
//
// RemoveAll() deve ser chamado por ECSWorld::DestroyEntity
// para garantir que nenhuma entidade destruída deixe dados órfãos.
 
class ComponentStorage
{
public:
 
    SparseSet<TransformComponent>    TransformComponents;
    SparseSet<VelocityComponent>     VelocityComponents;
    SparseSet<VehicleInputComponent> InputComponents;
    SparseSet<NitroComponent>        NitroComponents;
    SparseSet<DamageComponent>       DamageComponents;
 
    // Remove todos os componentes associados a uma entidade.
    // Chame sempre que ECSWorld::DestroyEntity for invocado.
    void RemoveAll(EntityID Entity)
    {
        TransformComponents.Remove(Entity);
        VelocityComponents.Remove(Entity);
        InputComponents.Remove(Entity);
        NitroComponents.Remove(Entity);
        DamageComponents.Remove(Entity);
    }
};