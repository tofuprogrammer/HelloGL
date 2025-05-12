#include "structures.hpp"
#include "cube.hpp"

cube::cube(mesh* object_mesh, texture_2d* object_texture, float x, float y, float z) : scene_object(object_mesh, object_texture)
{
	m_cube_rotation = 0.0f;
	m_cube_position.x = x, m_cube_position.y = y, m_cube_position.z = z;
}

cube::~cube()
{
	// Empty destructor
}

void cube::cube_draw()
{
	glBindTexture(GL_TEXTURE_2D, m_object_texture->get_texture_id());
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, m_object_mesh->vertices);
	glColorPointer(3, GL_FLOAT, 0, m_object_mesh->colours);
	glTexCoordPointer(2, GL_FLOAT, 0, m_object_mesh->texture_coordinates);

	glPushMatrix();
	glTranslatef(m_cube_position.x, m_cube_position.y, m_cube_position.z);
	glRotatef(m_cube_rotation, -1.0f, -1.0f, -1.0f);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, m_object_mesh->indices);
	glPopMatrix();

	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

void cube::object_draw()
{
	cube_draw();
}

void cube::cube_update()
{
	m_cube_rotation += 0.5f;
}

void cube::object_update()
{
	cube_update();
}
