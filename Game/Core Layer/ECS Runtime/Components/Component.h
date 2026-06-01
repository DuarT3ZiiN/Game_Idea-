#pragma once
 
#include <cstdint>
#include <atomic>
 
// Componentes são structs POD puras — sem herança, sem vtable.
// O ID de tipo é gerado automaticamente via template,
// garantindo IDs estáveis e únicos por tipo em runtime.
 
using ComponentTypeID = uint32_t;
 
namespace Internal
{
    inline ComponentTypeID NextComponentID()
    {
        static std::atomic<ComponentTypeID> Counter{ 1 };
        return Counter.fetch_add(1, std::memory_order_relaxed);
    }
}
 
template<typename T>
ComponentTypeID GetComponentTypeID()
{
    static const ComponentTypeID ID = Internal::NextComponentID();
    return ID;
}
 