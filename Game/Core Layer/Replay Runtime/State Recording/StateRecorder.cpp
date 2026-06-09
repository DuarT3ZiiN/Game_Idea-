#include "StateRecorder.h"

#include "ECSWorld.h"
#include "ComponentStorage.h"
#include "ReplayFrame.h"

void StateRecorder::CaptureVehicles(
    ReplayFrame&      Frame,
    ECSWorld&         World,
    ComponentStorage& Components
)
{
    auto& TransformSet = Components.TransformComponents;
    auto& VelocitySet  = Components.VelocityComponents;
    auto& NitroSet     = Components.NitroComponents;

    const auto& Entities = TransformSet.GetDenseEntities();

    Frame.VehicleStates.reserve(Entities.size());

    for (uint32_t i = 0; i < TransformSet.Count(); ++i)
    {
        const EntityID Entity = Entities[i];

        if (!World.IsEntityValid(Entity))
            continue;

        VehicleStateSnapshot Snapshot;
        Snapshot.FrameID   = Frame.FrameID;
        Snapshot.VehicleID = Entity;

        // Transform
        const TransformComponent& T = TransformSet.GetDense()[i];
        Snapshot.Transform.Position = { T.Position.X, T.Position.Y, T.Position.Z };

        // Velocity → Speed
        const VelocityComponent* Vel = VelocitySet.Get(Entity);
        if (Vel)
        {
            const float VX = Vel->LinearVelocity.X;
            const float VY = Vel->LinearVelocity.Y;
            const float VZ = Vel->LinearVelocity.Z;
            Snapshot.Speed = sqrtf(VX * VX + VY * VY + VZ * VZ);
        }

        // Nitro
        const NitroComponent* Nitro = NitroSet.Get(Entity);
        if (Nitro)
            Snapshot.NitroAmount = Nitro->NitroAmount;

        Frame.VehicleStates.push_back(Snapshot);
    }
}