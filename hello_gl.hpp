#pragma once

#include "classes.hpp"
#include "Cube.hpp"

class hello_gl
{
    camera* m_camera;
    cube* m_cube[200];
    float m_rotation;

public:
    //Constructor definition
    hello_gl(int argc, char* argv[]);

    // Destructor definition
    ~hello_gl(void);

    void display();
    void init_objects();
    void init_gl(int argc, char* argv[]);
    void keyboard(unsigned char key, int x, int y);
    void update();
};
