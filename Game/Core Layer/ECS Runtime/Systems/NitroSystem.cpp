#include "NitroSystem.h"

#include "ComponentStorage.h"

void NitroSystem::Execute(
    ECSWorld& World,
    ComponentStorage& Components,
    float DeltaTime
)
{
    auto& Nitros =
        Components.NitroComponents.GetDense();

    for (auto& Nitro : Nitros)
    {
        if (!Nitro.bNitroActive)
            continue;

        Nitro.NitroAmount -= 20.f * DeltaTime;

        Nitro.NitroAmount =
            FMath::Max(0.f, Nitro.NitroAmount);

        if (Nitro.NitroAmount <= 0.f)
        {
            Nitro.bNitroActive = false;
        }
    }
}

