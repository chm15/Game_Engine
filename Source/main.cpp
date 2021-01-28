//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Main. Won't be included in Engine library.
//
//=============================================================================

#include <iostream>
#include <OpenGL/graphics.h>



int main() {
    /*
    How I would like to interact with the engine:

    Engine engine;

    engine.registerComponent<Mesh>();
    engine.registerGameObject<Player>();

    engine.addGameObject<Player>();
    engine.addGameObject(Player::classID);
    */
    OpenGLGraphicsSystem gSystem();

    return 0;
}
