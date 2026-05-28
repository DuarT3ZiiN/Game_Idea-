#pragma once

#include "SparseSet.h"

#include "TransformComponent.h"
#include "VelocityComponent.h"
#include "VehicleInputComponent.h"
#include "NitroComponent.h"
#include "DamageComponent.h"

class ComponentStorage
{
public:

    SparseSet<TransformComponent> TransformComponents;

    SparseSet<VelocityComponent> VelocityComponents;

    SparseSet<VehicleInputComponent> InputComponents;

    SparseSet<NitroComponent> NitroComponents;

    SparseSet<DamageComponent> DamageComponents;
};

