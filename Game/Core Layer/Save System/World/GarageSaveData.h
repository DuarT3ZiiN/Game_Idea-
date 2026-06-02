#pragma once

#include <vector>

struct GarageVehicleData
{
    uint64_t VehicleID;

    uint32_t VehicleClass;

    float Mileage;

    float Damage;

    uint32_t PerformanceLevel;
};

struct GarageSaveData
{
    std::vector<
        GarageVehicleData
    > Vehicles;
};

