//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Maintsins a list of all classes that are registered. Useful for
//      networking functions and initializing component arrays automatically.
//
//=============================================================================

#include "classtable.h"

namespace classtable 
{
    // Global ClassTable used to register GameEngineClass' (using macros).
    ClassTable g_ClassTable;
}

