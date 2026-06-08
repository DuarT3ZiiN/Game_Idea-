#pragma once

#include "StateReplicationSystem.h"
#include "ClientPrediction.h"
#include "ReconciliationRuntime.h"
#include "NetworkTickManager.h"

class ReplicationManager
{
public:

    void Initialize();

    void Tick();

private:

    StateReplicationSystem
        StateReplication;

    ClientPrediction
        Prediction;

    ReconciliationRuntime
        Reconciliation;

    NetworkTickManager
        TickManager;
};
