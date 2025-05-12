#pragma once

#include "structures.hpp"
#include "cube.hpp"

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
    void initialise_objects();
    void initialise_gl(int argc, char* argv[]);
    void keyboard(unsigned char key, int x, int y);
    void update();
};
