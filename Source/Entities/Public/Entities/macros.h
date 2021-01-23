//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Register an entity with the EntityRegistry. This associates
//      the classIDs of components with the classIDs of certain entities.
//
//=============================================================================

#pragma once

#include <ClassTable/macros.h>
#include <Coordinator/coordinator.h>

//#define IMPLEMENT_ENGINE_COMPONENT(ClassName) \
//    IMPLEMENT_ENGINE_CLASS_WITH_TYPE(ClassName, EngineComponent<ClassName>)


#define REGISTER_ENTITY(entity_classID, component_classIDs...) \
    namespace coordinator {     \
        extern g_Coordinator;   \
    }                           \
    coordinator::g_Coordinator.entityRegistry->registerEntity(entity_classID, std::vector(component_classIDs))


