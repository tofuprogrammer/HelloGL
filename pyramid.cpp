#include "pyramid.hpp"
#include "structures.hpp"

pyramid::pyramid(mesh* mesh, float x, float y, float z)
{
    m_pyramid_mesh = mesh;
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
    glVertexPointer(3, GL_FLOAT, 0, m_pyramid_mesh->vertices);
    glColorPointer(3, GL_FLOAT, 0, m_pyramid_mesh->colours);

    glPushMatrix();
    glTranslatef(m_pyramid_position.x, m_pyramid_position.y, m_pyramid_position.z);
    glRotatef(m_pyramid_rotation, -1.0f, -1.0f, -1.0f);
    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, m_pyramid_mesh->indices);
    glPopMatrix();

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}

void pyramid::pyramid_update()
{
    m_pyramid_rotation += 0.5f;
}
