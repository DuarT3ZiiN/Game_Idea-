#pragma once

#include <cstdint>

enum class EWorldAssetType : uint8_t
{
    District,       // bloco de cidade (streaming por região)
    Road,           // malha de estrada
    Prop,           // objeto de cenário (poste, lixo, etc.)
    Building,       // edifício
    Vegetation,     // árvores, arbustos
    TrafficSpline,  // spline de tráfego
    PoliceZone,     // zona de patrulha policial (seção 1.2.1)
    RaceRoute,      // rota de corrida genérica
    Checkpoint,     // ponto de checkpoint (seção 1.1.2.2 Circuit Rules)
    StartLine,      // linha de largada
    NavMesh         // navmesh de IA (seção 2.2 AI Simulation)
};