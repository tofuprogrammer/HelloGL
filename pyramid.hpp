#pragma once

#include "scene_object.hpp"
#include "structures.hpp"

class pyramid : public scene_object
{
private:
    vector3 m_pyramid_position;
    GLfloat m_pyramid_rotation;
public:
    pyramid(mesh* object_mesh, float x, float y, float z);
    ~pyramid() override;

    void pyramid_draw();
    void object_draw() override;
    void pyramid_update();
    void object_update() override;
};
