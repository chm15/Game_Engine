//============= Copyright Connor McLaughlan, All rights reserved. =============
//
//  Purpose: Main. Won't be included in Engine library.
//
//=============================================================================

#include <iostream>
#include <Components/components.h>
#include <GameObject/gameobject.h>
#include <Engine/engine.h>
#include <OpenGL/graphics.h>


class Cube : public GameObject<Cube> {
public:
    Cube() : GameObject<Cube>{Mesh::classID} {}
    // Contains Mesh component
    void load(ComponentManager& cm, int entityID) override {}
};
    


int main() {
    /*
    How I would like to interact with the engine:


    engine.registerComponent<Mesh>();
    engine.registerGameObject<Player>();

    engine.addGameObject<Player>();
    engine.addGameObject(Player::classID);
    */

    Engine engine;

    engine.registerComponent<Mesh>();
    //engine.registerComponent<Transform>();
    engine.registerSystem<OpenGLGraphicsSystem>();
    engine.registerGameObject<Cube>();


    int x;
    std::cin >> x;

    return 0;
}
