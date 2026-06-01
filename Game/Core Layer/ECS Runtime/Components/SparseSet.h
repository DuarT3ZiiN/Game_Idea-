#pragma once
 
#include <vector>
#include <cassert>
 
#include "Entity.h"
 
// SparseSet<T> armazena componentes com acesso O(1) por EntityID
// e iteração cache-friendly via array denso.
//
// Melhorias em relação à versão anterior:
//   - Remove() correto via swap-and-pop (mantém o denso contíguo)
//   - Proteção contra Insert duplo na mesma entidade
//   - GetDenseEntities() expõe o mapeamento índice→entidade
//   - Sparse usa UINT32_MAX como sentinela (mais robusto que INVALID_ENTITY=0)
 
static constexpr uint32_t SPARSE_INVALID = UINT32_MAX;
 
template<typename T>
class SparseSet
{
public:
 
    void Insert(EntityID Entity, const T& Component)
    {
        assert(!Has(Entity) && "Componente já existe para essa entidade");
 
        if (Entity >= static_cast<EntityID>(Sparse.size()))
        {
            Sparse.resize(Entity + 1, SPARSE_INVALID);
        }
 
        Sparse[Entity] = static_cast<uint32_t>(Dense.size());
 
        DenseEntities.push_back(Entity);
        Dense.push_back(Component);
    }
 
    void Remove(EntityID Entity)
    {
        if (!Has(Entity))
            return;
 
        const uint32_t RemovedIdx  = Sparse[Entity];
        const EntityID LastEntity  = DenseEntities.back();
 
        // Swap removido com o último e pop
        Dense[RemovedIdx]         = Dense.back();
        DenseEntities[RemovedIdx] = LastEntity;
 
        // Atualiza o sparse do elemento que foi movido
        Sparse[LastEntity] = RemovedIdx;
 
        Dense.pop_back();
        DenseEntities.pop_back();
 
        Sparse[Entity] = SPARSE_INVALID;
    }
 
    bool Has(EntityID Entity) const
    {
        return Entity < static_cast<EntityID>(Sparse.size())
            && Sparse[Entity] != SPARSE_INVALID;
    }
 
    T* Get(EntityID Entity)
    {
        if (!Has(Entity))
            return nullptr;
 
        return &Dense[Sparse[Entity]];
    }
 
    const T* Get(EntityID Entity) const
    {
        if (!Has(Entity))
            return nullptr;
 
        return &Dense[Sparse[Entity]];
    }
 
    // Iteração cache-friendly — use para sistemas que processam todos
    std::vector<T>& GetDense()
    {
        return Dense;
    }
 
    const std::vector<T>& GetDense() const
    {
        return Dense;
    }
 
    // Entidade correspondente ao índice i no array denso
    const std::vector<EntityID>& GetDenseEntities() const
    {
        return DenseEntities;
    }
 
    uint32_t Count() const
    {
        return static_cast<uint32_t>(Dense.size());
    }
 
    void Clear()
    {
        Dense.clear();
        DenseEntities.clear();
        Sparse.clear();
    }
 
private:
 
    // Sparse[EntityID] = índice no array denso (ou SPARSE_INVALID)
    std::vector<uint32_t> Sparse;
 
    // Dados dos componentes em memória contígua
    std::vector<T> Dense;
 
    // Dense[i] pertence a DenseEntities[i]
    std::vector<EntityID> DenseEntities;
};
 