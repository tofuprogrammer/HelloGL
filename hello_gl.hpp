#pragma once

#include "structures.hpp"
#include "cube.hpp"
#include "pyramid.hpp"

class hello_gl
{
    camera* m_camera;
    cube* m_cube[500];
    pyramid* m_pyramid[500];
    float m_rotation;

public:
    //Constructor definition
    hello_gl(int argc, char* argv[]);

    // Destructor definition
    ~hello_gl();

    void display();
    void initialise_objects();
    void initialise_gl(int argc, char* argv[]);
    void keyboard(unsigned char key, int x, int y);
    void update();
};
