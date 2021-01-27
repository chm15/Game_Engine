//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: OpenGL backend.
//
//=============================================================================

#pragma once

#include <Systems/system.h>


class OpenGLGraphicsSystem : public System {
public:
    OpenGLGraphicsSystem();
    void update() override;

private:
    void draw();
    void init();
};
