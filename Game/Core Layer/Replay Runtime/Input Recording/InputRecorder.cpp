#include "InputRecorder.h"

#include "ComponentStorage.h"

InputSnapshot InputRecorder::CaptureFromComponents(
    EntityID          Entity,
    ComponentStorage& Components,
    ReplayFrameID     FrameID,
    double            Timestamp
)
{
    InputSnapshot Snapshot;
    Snapshot.FrameID   = FrameID;
    Snapshot.Timestamp = Timestamp;

    const VehicleInputComponent* Input =
        Components.InputComponents.Get(Entity);

    if (Input)
    {
        Snapshot.Steering   = Input->Steering;
        Snapshot.Throttle   = Input->Throttle;
        Snapshot.Brake      = Input->Brake;
        Snapshot.bHandbrake = Input->bHandbrake;
    }

    return Snapshot;
}

InputSnapshot InputRecorder::Capture(
    ReplayFrameID FrameID,
    double        Timestamp
)
{
    InputSnapshot Snapshot;
    Snapshot.FrameID   = FrameID;
    Snapshot.Timestamp = Timestamp;
    return Snapshot;
}