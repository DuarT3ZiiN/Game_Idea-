#pragma once

class PhysicsDebugManager
{
public:

    void SetMode(
        EPhysicsDebugMode Mode
    );

    void Draw();

private:

    EPhysicsDebugMode CurrentMode =
        EPhysicsDebugMode::None;
};