#pragma once

#include "structures.hpp"

class pyramid
{
private:
    vector3 m_pyramid_position;
    GLfloat m_pyramid_rotation;
    mesh* m_pyramid_mesh;

public:
    pyramid(mesh* mesh, float x, float y, float z);
    ~pyramid();

    void pyramid_draw();
    void pyramid_update();
};
