#pragma once

#include "Classes.hpp"
#include "Cube.hpp"

class HelloGL
{
    Camera* camera;
    Cube* cube[200];
    float rotation;

public:
    //Constructor definition
    HelloGL(int argc, char* argv[]);

    // Destructor definition
    ~HelloGL(void);

    void Display();
    void InitObjects();
    void InitGL(int argc, char* argv[]);
    void Keyboard(unsigned char key, int x, int y);
    void Update();
};
