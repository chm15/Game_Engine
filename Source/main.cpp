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
    void load(ComponentManager& cm, int entityID) override {
        Mesh mesh("Assets/calibration_cube_1.obj");
        cm.addComponent<Mesh>(mesh);
    }
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

    //===== Register Components =====
    engine.registerComponent<Mesh>();
    //engine.registerComponent<Transform>();
    
    //===== Register GameObjects =====
    engine.registerGameObject<Cube>();  // TODO: Provide variadic where GameObject args can be passed through
    
    //===== Register Systems =====
    engine.registerSystem<OpenGLGraphicsSystem>();


    //===== (Optional) Add game objects =====
    engine.loadGameObject(Cube::classID); 


    engine.run();


    int x;
    std::cin >> x;

    return 0;
}
