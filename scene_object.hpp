#pragma once

#include "structures.hpp"
#include "texture_2d.hpp"

class scene_object
{
protected:
    mesh* m_object_mesh;
    texture_2d* m_object_texture;

public:
    scene_object(mesh* object_mesh, texture_2d* object_texture);
    virtual ~scene_object();

    virtual void object_draw() = 0;
    virtual void object_update() = 0;
};
