#pragma once

#include <deque>

#include "InputCommand.h"

// PredictionBuffer armazena inputs pendentes de confirmação pelo servidor.
//
// Melhorias em relação à versão anterior:
//   - GetCommandAtTick() — ReconciliationRuntime precisa achar o command
//     correspondente ao tick autoritativo para fazer o replay correto
//   - Clear() — limpa após reconciliação bem-sucedida
//   - Capacidade máxima: descarta inputs muito antigos (> MAX_BUFFERED_TICKS)
//     para evitar crescimento ilimitado em caso de lag prolongado

static constexpr uint32_t MAX_BUFFERED_TICKS = 256;

class PredictionBuffer
{
public:

    void Push(const InputCommand& Command);

    // Retorna nullptr se o tick não está no buffer
    const InputCommand* GetCommandAtTick(TickID Tick) const;

    // Remove todos os commands até e incluindo o tick confirmado
    void AcknowledgeUpTo(TickID ConfirmedTick);

    void Clear();

    const std::deque<InputCommand>& GetCommands() const;

    uint32_t Count() const;

private:

    std::deque<InputCommand> Commands;
};