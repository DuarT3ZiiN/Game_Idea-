#pragma once

#include <deque>

class PredictionBuffer
{
public:

    void Push(
        const InputCommand& Command
    );

    const std::deque<
        InputCommand
    >& GetCommands() const;

private:

    std::deque<
        InputCommand
    > Commands;
};

