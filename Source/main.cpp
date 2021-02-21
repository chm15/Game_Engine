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
#include <Math/quat.h>


class Cube : public GameObject<Cube> {
public:
    Cube() : GameObject<Cube>{Mesh::classID, Transform::classID} {}
    // Contains Mesh component
    void load(ComponentManager& cm, int entityID) override {
        Mesh mesh("Assets/Textured_Triangle_2/");
        mesh.entityID = entityID;  // THIS IS SUPER IMPORTANT FOR LINKING THE COMPONENT WITH THIS ENTITY.
        cm.addComponent<Mesh>(mesh);

        Transform transform;
        cm.addComponent<Transform>(transform);
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
    engine.registerComponent<Transform>();
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
