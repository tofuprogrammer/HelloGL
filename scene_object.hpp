#pragma once

#include "structures.hpp"

class scene_object
{
protected:
    mesh* m_object_mesh;

public:
    scene_object(mesh* object_mesh);
    virtual ~scene_object();

    virtual void object_draw() = 0;
    virtual void object_update() = 0;
};
