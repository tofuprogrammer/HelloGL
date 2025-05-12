#include "scene_object.hpp"

scene_object::scene_object(mesh* object_mesh, texture_2d* object_texture)
{
    m_object_mesh = object_mesh;
    m_object_texture = object_texture;
}

scene_object::~scene_object()
{

}

void scene_object::object_draw()
{

}

void scene_object::object_update()
{

}
