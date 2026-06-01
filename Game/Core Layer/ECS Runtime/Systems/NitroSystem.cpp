#include "NitroSystem.h"
#include "ComponentStorage.h"
 
void NitroSystem::Execute(
    ECSWorld&         World,
    ComponentStorage& Components,
    float             DeltaTime
)
{
    auto& NitroSet = Components.NitroComponents;
    auto& Nitros   = NitroSet.GetDense();
 
    for (auto& Nitro : Nitros)
    {
        if (!Nitro.bNitroActive)
            continue;
 
        Nitro.NitroAmount -= 20.f * DeltaTime;
 
        if (Nitro.NitroAmount <= 0.f)
        {
            Nitro.NitroAmount  = 0.f;
            Nitro.bNitroActive = false;
        }
    }
}
 