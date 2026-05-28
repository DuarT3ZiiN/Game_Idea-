#include "VehicleMovementSystem.h"

#include "ComponentStorage.h"

void VehicleMovementSystem::Execute(
    ECSWorld& World,
    ComponentStorage& Components,
    float DeltaTime
)
{
    auto& Transforms =
        Components.TransformComponents.GetDense();

    auto& Velocities =
        Components.VelocityComponents.GetDense();

    const int32 Count =
        FMath::Min(
            Transforms.size(),
            Velocities.size()
        );

    for (int32 i = 0; i < Count; ++i)
    {
        Transforms[i].Position +=
            Velocities[i].LinearVelocity * DeltaTime;
    }
}

