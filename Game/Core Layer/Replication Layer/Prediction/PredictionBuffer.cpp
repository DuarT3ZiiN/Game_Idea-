#include "PredictionBuffer.h"

void PredictionBuffer::Push(const InputCommand& Command)
{
    Commands.push_back(Command);

    // Descarta inputs muito antigos para evitar crescimento ilimitado
    while (Commands.size() > MAX_BUFFERED_TICKS)
        Commands.pop_front();
}

const InputCommand* PredictionBuffer::GetCommandAtTick(TickID Tick) const
{
    for (const auto& Cmd : Commands)
    {
        if (Cmd.Tick == Tick)
            return &Cmd;
    }
    return nullptr;
}

void PredictionBuffer::AcknowledgeUpTo(TickID ConfirmedTick)
{
    while (!Commands.empty() && Commands.front().Tick <= ConfirmedTick)
        Commands.pop_front();
}

void PredictionBuffer::Clear()
{
    Commands.clear();
}

const std::deque<InputCommand>& PredictionBuffer::GetCommands() const
{
    return Commands;
}

uint32_t PredictionBuffer::Count() const
{
    return static_cast<uint32_t>(Commands.size());
}