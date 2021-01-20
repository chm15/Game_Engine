//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Register a component with the global Coordinator and with
//      the global classtable.
//
//=============================================================================

#pragma once

#include <ClassTable/macros.h>
#include <Coordinator/coordinator.h>
#include "enginecomponent.h"

#define IMPLEMENT_ENGINE_COMPONENT(ClassName) \
    IMPLEMENT_ENGINE_CLASS_WITH_TYPE(ClassName, EngineComponent<ClassName>)

