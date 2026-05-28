#pragma once

#include <vector>

#include "Entity.h"

template<typename T>
class SparseSet
{
public:

    void Insert(EntityID Entity, const T& Component)
    {
        if (Entity >= Sparse.size())
        {
            Sparse.resize(Entity + 1, INVALID_ENTITY);
        }

        Sparse[Entity] = Dense.size();

        DenseEntities.push_back(Entity);
        Dense.push_back(Component);
    }

    bool Has(EntityID Entity) const
    {
        return Entity < Sparse.size()
            && Sparse[Entity] != INVALID_ENTITY;
    }

    T* Get(EntityID Entity)
    {
        if (!Has(Entity))
            return nullptr;

        return &Dense[Sparse[Entity]];
    }

    std::vector<T>& GetDense()
    {
        return Dense;
    }

private:

    std::vector<EntityID> Sparse;

    std::vector<EntityID> DenseEntities;

    std::vector<T> Dense;
};
