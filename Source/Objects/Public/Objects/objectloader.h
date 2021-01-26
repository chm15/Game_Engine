//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Used to load .obj files.
//
//=============================================================================

#pragma once

#include <vector>
#include <Math/vec.h>


void loadObjFile(const char* filename, std::vector<Vec3>& vertexBuffer, std::vector<int>& indexBuffer);


