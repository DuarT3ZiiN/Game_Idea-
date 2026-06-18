#pragma once

#include <vector>

class AIDebugManager
{
public:

    void SetMode(
        EAIDebugMode Mode
    );

    void Draw();

private:

    EAIDebugMode CurrentMode =
        EAIDebugMode::None;

    std::vector<
        AIDebugInfo
    > DebugEntities;
};