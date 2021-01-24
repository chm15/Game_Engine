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


// ClassName should be the Entity Class.
// The variadic argument should be int classIDs (the components to register).
#define IMPLEMENT_ENGINE_ENTITY(ClassName, ...) \
    IMPLEMENT_ENGINE_CLASS_WITH_TYPE_AND_ARGS(ClassName, EngineEntity<ClassName>, {__VA_ARGS__})


