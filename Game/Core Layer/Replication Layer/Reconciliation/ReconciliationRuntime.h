#pragma once

#include "PredictionBuffer.h"

class ReconciliationRuntime
{
public:

    void ReceiveServerState(
        const AuthoritativeState& State
    );

private:

    PredictionBuffer Buffer;
};