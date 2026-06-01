#pragma once
 
#include <vector>
#include <queue>
 
#include "EntityRecord.h"
#include "ComponentStorage.h"
 
// ECSWorld gerencia o ciclo de vida das entidades.
//
// Melhorias em relação à versão anterior:
//   - DestroyEntity remove componentes via ComponentStorage::RemoveAll
//   - Geração incrementada no reuso, detectando handles stale
//   - IsEntityValid verifica geração além de flags
 
class ECSWorld
{
public:
 
    ECSWorld();
 
    // Cria uma entidade e retorna seu ID com geração embutida
    EntityID CreateEntity();
 
    // Destrói entidade e remove todos os seus componentes
    void DestroyEntity(EntityID Entity, ComponentStorage& Components);
 
    // Verifica se o ID ainda aponta para a entidade correta (geração ok)
    bool IsEntityValid(EntityID Entity) const;
 
    EntityRecord* GetRecord(EntityID Entity);
 
    const EntityRecord* GetRecord(EntityID Entity) const;
 
private:
 
    EntityID NextIndex;
 
    // Indexado por GetEntityIndex(ID)
    std::vector<EntityRecord> EntityRecords;
 
    // Índices disponíveis para reuso
    std::queue<uint32_t> FreeIndices;
};