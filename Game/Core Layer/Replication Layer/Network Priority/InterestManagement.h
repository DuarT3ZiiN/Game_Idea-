#pragma once

#include <unordered_map>
#include <unordered_set>

#include "NetworkTypes.h"
#include "Entity.h"

// InterestManagement decide quais entidades devem ser replicadas para cada cliente.
// Implementa o padrão Area of Interest (AOI) descrito na seção 3.8 do README.
//
// Melhorias em relação à versão anterior:
//   - InterestRadius configurável por cliente (jogador próximo = raio menor = menos dados)
//   - RegisterClientPosition() / UpdateEntityPosition() — mantém posições para cálculo de distância
//   - GetInterestedEntities() — retorna o set de entidades relevantes para um cliente
//   - ShouldReplicate() permanece como helper rápido para o ReplicationChannel

class InterestManager
{
public:

    // Registra ou atualiza a posição de um cliente (para cálculo de AOI)
    void UpdateClientPosition(NetworkID Client, float X, float Y, float Z);

    // Registra ou atualiza a posição de uma entidade
    void UpdateEntityPosition(EntityID Entity, float X, float Y, float Z);

    // Define o raio de interesse de um cliente (padrão: 500 unidades)
    void SetInterestRadius(NetworkID Client, float Radius);

    // Verifica se uma entidade está no interesse de um cliente
    bool ShouldReplicate(EntityID Entity, NetworkID Client) const;

private:

    struct Position3D { float X = 0.f; float Y = 0.f; float Z = 0.f; };

    std::unordered_map<NetworkID, Position3D> ClientPositions;
    std::unordered_map<NetworkID, float>      ClientRadii;
    std::unordered_map<EntityID,  Position3D> EntityPositions;

    static constexpr float DEFAULT_INTEREST_RADIUS = 500.f;
};