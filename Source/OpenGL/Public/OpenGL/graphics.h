//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: OpenGL backend.
//
//=============================================================================

#pragma once

#include <Systems/system.h>


class OpeGLGraphicsSystem : public System {
public:
    void update() override {
        // Obtain all GameObjects with mesh components
        return;
    }

private:
    void draw();

    void init() {
        // Initializes OpenGL stuff.
        return;
    }
};
