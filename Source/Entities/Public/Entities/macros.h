//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Register an entity with the EntityRegistry. This associates
//      the classIDs of components with the classIDs of certain entities.
//
//=============================================================================

#pragma once

#include <Coordinator/coordinator.h>
#include <ClassTable/macros.h>
#include "entityregistry.h"
#include "engineentity.h"


// THIS ISN'T WORKING BECAUsE IT'S IN THE GLOBAL NAMESPACE!
#define IMPLEMENT_ENGINE_ENTITY(ClassName, component_classIDs...) \
    IMPLEMENT_ENGINE_CLASS_WITH_TYPE_AND_ARGS(ClassName, EngineEntity<ClassName>, component_classIDs) \


