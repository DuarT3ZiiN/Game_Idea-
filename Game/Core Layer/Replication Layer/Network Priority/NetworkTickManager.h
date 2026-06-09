#pragma once

#include <cstdint>

#include "NetworkTypes.h"

// NetworkTickManager controla o tick de rede independente do frame rate.
//
// Melhorias em relação à versão anterior:
//   - TickRate configurável (padrão 60Hz)
//   - Tick(DeltaTime) acumula tempo e dispara ticks no intervalo correto
//     — a versão anterior incrementava 1 tick por chamada sem controle de tempo
//   - GetTickIntervalSeconds() para uso no ReplicationManager

class NetworkTickManager
{
public:

    explicit NetworkTickManager(uint32_t InTickRate = 60);

    // Deve ser chamado todo frame com o DeltaTime real
    // Retorna quantos ticks foram disparados neste frame (normalmente 0 ou 1)
    uint32_t Tick(double DeltaTime);

    TickID   GetCurrentTick()          const { return CurrentTick; }
    uint32_t GetTickRate()             const { return TickRate; }
    double   GetTickIntervalSeconds()  const { return 1.0 / static_cast<double>(TickRate); }

private:

    TickID   CurrentTick    = 0;
    uint32_t TickRate       = 60;
    double   TimeAccumulator = 0.0;
};