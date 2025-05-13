#include "pyramid.hpp"

#include <iostream>

#include "scene_object.hpp"
#include "structures.hpp"

pyramid::pyramid(mesh* object_mesh, float x, float y, float z) : scene_object(object_mesh, nullptr)
{
    m_pyramid_rotation = 0.0f;
    m_pyramid_position.x = x, m_pyramid_position.y = y, m_pyramid_position.z = z;
}

pyramid::~pyramid()
{
    // Empty destructor
}

void pyramid::pyramid_draw()
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, m_object_mesh->vertices);
    glColorPointer(3, GL_FLOAT, 0, m_object_mesh->colours);

    glPushMatrix();
    glTranslatef(m_pyramid_position.x, m_pyramid_position.y, m_pyramid_position.z);
    glRotatef(m_pyramid_rotation, -1.0f, -1.0f, -1.0f);
    glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_SHORT, m_object_mesh->indices);
    glPopMatrix();

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}

void pyramid::object_draw()
{
    pyramid_draw();
}

void pyramid::pyramid_update()
{
    m_pyramid_rotation += 0.5f;
}

void pyramid::object_update()
{
    pyramid_update();
}
