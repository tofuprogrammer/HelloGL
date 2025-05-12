#include "structures.hpp"
#include "cube.hpp"

cube::cube(mesh* mesh, float x, float y, float z)
{
	m_cube_mesh = mesh;
	m_cube_rotation = 0.0f;
	m_cube_position.x = x, m_cube_position.y = y, m_cube_position.z = z;
}

cube::~cube()
{
	// Empty destructor
}

void cube::cube_draw()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, m_cube_mesh->vertices);
	glColorPointer(3, GL_FLOAT, 0, m_cube_mesh->colours);

	glPushMatrix();
	glTranslatef(m_cube_position.x, m_cube_position.y, m_cube_position.z);
	glRotatef(m_cube_rotation, -1.0f, -1.0f, -1.0f);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, m_cube_mesh->indices);
	glPopMatrix();

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

void cube::cube_update()
{
	m_cube_rotation += 0.5f;
}
