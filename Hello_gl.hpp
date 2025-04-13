#pragma once

#include "Classes.hpp"
#include "Cube.hpp"

class Hello_gl
{
    Camera* m_camera;
    Cube* m_cube[200];
    float m_rotation;

public:
    //Constructor definition
    Hello_gl(int argc, char* argv[]);

    // Destructor definition
    ~Hello_gl(void);

    void display();
    void init_objects();
    void init_gl(int argc, char* argv[]);
    void keyboard(unsigned char key, int x, int y);
    void update();
};