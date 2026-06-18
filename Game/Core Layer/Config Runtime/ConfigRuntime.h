#pragma once

class ConfigRuntime
{
public:

    void Initialize();

    void Reload();

public:

    GameplayConfig Gameplay;

    DriftConfig Drift;

    DragConfig Drag;

    PoliceConfig Police;

    AIRacerConfig RacerAI;

    CrewAIConfig CrewAI;

    PoliceAIConfig PoliceAI;

    TrafficAIConfig TrafficAI;

    EconomyConfig Economy;

    VehicleEconomyConfig VehicleEconomy;

    CareerEconomyConfig CareerEconomy;
};
