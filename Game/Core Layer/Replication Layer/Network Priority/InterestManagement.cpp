#include "InterestManagement.h"

#include <cmath>

void InterestManager::UpdateClientPosition(
    NetworkID Client, float X, float Y, float Z
)
{
    ClientPositions[Client] = { X, Y, Z };
}

void InterestManager::UpdateEntityPosition(
    EntityID Entity, float X, float Y, float Z
)
{
    EntityPositions[Entity] = { X, Y, Z };
}

void InterestManager::SetInterestRadius(NetworkID Client, float Radius)
{
    ClientRadii[Client] = Radius;
}

bool InterestManager::ShouldReplicate(
    EntityID  Entity,
    NetworkID Client
) const
{
    auto ClientIt = ClientPositions.find(Client);
    auto EntityIt = EntityPositions.find(Entity);

    // Se não temos posição registrada, replica por precaução
    if (ClientIt == ClientPositions.end() || EntityIt == EntityPositions.end())
        return true;

    const Position3D& CP = ClientIt->second;
    const Position3D& EP = EntityIt->second;

    const float DX = CP.X - EP.X;
    const float DY = CP.Y - EP.Y;
    const float DZ = CP.Z - EP.Z;

    const float DistSq = DX * DX + DY * DY + DZ * DZ;

    auto RadiusIt    = ClientRadii.find(Client);
    const float R    = (RadiusIt != ClientRadii.end())
                        ? RadiusIt->second
                        : DEFAULT_INTEREST_RADIUS;

    return DistSq <= (R * R);
}