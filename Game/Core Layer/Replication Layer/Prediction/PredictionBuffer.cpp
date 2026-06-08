#include "PredictionBuffer.h"

void PredictionBuffer::Push(
    const InputCommand& Command
)
{
    Commands.push_back(Command);
}

const std::deque<
    InputCommand
>&
PredictionBuffer::GetCommands() const
{
    return Commands;
}
