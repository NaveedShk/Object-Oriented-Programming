#include <iostream>
using namespace std;

class GraphicsRenderer {
public:
    void render() {
        cout << "This is  Graphics Rendering Engine " << endl;
    }
};

class InputHandler {
public:
    void handle_input() {
        cout << "this is the  Input Handler" << endl;
    }
};

class PhysicsEngine {
public:
    void simulate() {
        cout << "This is the  Physics Engine" << endl;
    }
};

class GameEngine {
private:
    GraphicsRenderer renderer; // Composition
    InputHandler input_handler; 
   PhysicsEngine physics_engine; 

public:
    void start() {
        cout << "The tour of the Game Engine" << endl;
        renderer.render();
        input_handler.handle_input();
        physics_engine.simulate();
    }
};

int main() {
    cout << "Name: Sheikh Naveed Azeemi \nRoll no: 23K-0003\n\n" << endl;
    
    GameEngine game;
    game.start();

   
    // If  'game' object is deleted , we won't be able to access the other class objects and  they will be  automaticaaly  deleted.
}
