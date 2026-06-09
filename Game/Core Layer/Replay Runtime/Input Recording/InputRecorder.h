#pragma once

// Correção: arquivo era "ImputRecorder.h" — typo corrigido para "InputRecorder.h"

#include "InputSnapshot.h"

class ECSWorld;
class ComponentStorage;

// InputRecorder captura o estado de input de uma entidade num dado frame.
//
// Melhorias em relação à versão anterior:
//   - Capture(EntityID, Timestamp) — associa o snapshot a uma entidade e
//     ao timestamp do frame atual (essencial para replay determinístico)
//   - CaptureFromComponents() — lê VehicleInputComponent diretamente do ECS
//     em vez de retornar um snapshot vazio

class InputRecorder
{
public:

    // Captura input da entidade pelo VehicleInputComponent no ECS
    InputSnapshot CaptureFromComponents(
        EntityID           Entity,
        ComponentStorage&  Components,
        ReplayFrameID      FrameID,
        double             Timestamp
    );

    // Captura manual (para testes ou input sintético)
    InputSnapshot Capture(
        ReplayFrameID FrameID,
        double        Timestamp
    );
};