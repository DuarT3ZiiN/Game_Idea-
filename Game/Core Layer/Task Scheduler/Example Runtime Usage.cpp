TaskScheduler Scheduler;

Scheduler.Initialize(6);

Job VehiclePhysics;

VehiclePhysics.ID = 1;

VehiclePhysics.Priority =
    EJobPriority::Critical;

VehiclePhysics.DebugName =
    "VehiclePhysics";

VehiclePhysics.Execute =
[]()
{
    // Vehicle Physics Update
};

Scheduler.Submit(
    VehiclePhysics
);