#include <bitset>
#include <cstdint>
 
static constexpr uint32_t MAX_COMPONENTS = 64;
 
using ComponentMask = std::bitset<MAX_COMPONENTS>;
 
// Archetype descreve um conjunto único de tipos de componente.
// Entidades com os mesmos componentes pertencem ao mesmo archetype,
// permitindo iterar só sobre as entidades relevantes por sistema.
 
struct Archetype
{
    uint32_t      ID   = 0;
    ComponentMask Mask;
 
    bool operator==(const Archetype& Other) const
    {
        return Mask == Other.Mask;
    }
 
    bool Matches(const ComponentMask& RequiredMask) const
    {
        return (Mask & RequiredMask) == RequiredMask;
    }
};