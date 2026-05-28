#pragma once

#include <functional>

#include "Event.h"

using EventCallback =
    std::function<void(const Event&)>;
