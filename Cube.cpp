#include "Classes.hpp"
#include "Cube.hpp"

Cube::Cube(Mesh* mesh, float x, float y, float z)
{
	_mesh = mesh;
	cubeRotation = 0.0f;
	position.x = x, position.y = y, position.z = z;
}

Cube::~Cube()
{
	// Empty destructor
}

void Cube::Draw() {
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, _mesh->vertices);
	glColorPointer(3, GL_FLOAT, 0, _mesh->colours);

	glPushMatrix();
	glTranslatef(position.x, position.y, position.z);
	glRotatef(cubeRotation, -1.0f, -1.0f, -1.0f);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, _mesh->indices);
	glPopMatrix();

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

void Cube::Update() {
	cubeRotation += 0.5f;
}
