#pragma once
 
// Typo corrigido: era VehicleImputComponent.h
// Renomeado para VehicleInputComponent.h
 
struct VehicleInputComponent
{
    float Throttle   = 0.f;
    float Brake      = 0.f;
    float Steering   = 0.f;
    bool  bHandbrake = false;
};
 