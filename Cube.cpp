#include "Classes.hpp"
#include "Cube.hpp"

Cube::Cube(Mesh* mesh, float x, float y, float z)
{
	m_mesh = mesh;
	m_cube_rotation = 0.0f;
	m_position.x = x, m_position.y = y, m_position.z = z;
}

void Cube::draw() {
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, m_mesh->vertices);
	glColorPointer(3, GL_FLOAT, 0, m_mesh->colours);

	glPushMatrix();
	glTranslatef(m_position.x, m_position.y, m_position.z);
	glRotatef(m_cube_rotation, -1.0f, -1.0f, -1.0f);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, m_mesh->indices);
	glPopMatrix();

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

void Cube::update() {
	m_cube_rotation += 0.5f;
}