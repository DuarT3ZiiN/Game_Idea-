#pragma once

#include "VehicleStateSnapshot.h"

class ECSWorld;
class ComponentStorage;
struct ReplayFrame;

// StateRecorder captura estado de todos os veículos ativos no ECS.
//
// Melhoria em relação à versão anterior:
//   - CaptureVehicles recebe ECSWorld e ComponentStorage para fazer
//     a query real — a versão anterior tinha apenas comentários vazios

class StateRecorder
{
public:

    void CaptureVehicles(
        ReplayFrame&      Frame,
        ECSWorld&         World,
        ComponentStorage& Components
    );
};