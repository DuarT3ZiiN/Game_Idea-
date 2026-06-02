#pragma once

// RuntimeBudget descreve o orçamento de tempo de um sistema por frame.
//
// Melhoria em relação à versão anterior:
//   - bOverBudget flag — permite que o TaskScheduler priorize
//     jobs críticos quando um sistema excede seu budget
//   - FrameCount — conta quantos frames consecutivos o sistema excedeu

struct RuntimeBudget
{
    double   AllocatedMS  = 0.0;
    double   ConsumedMS   = 0.0;
    bool     bOverBudget  = false;
    uint32_t OverFrames   = 0;    // frames consecutivos acima do budget

    double RemainingMS() const
    {
        return AllocatedMS - ConsumedMS;
    }
};