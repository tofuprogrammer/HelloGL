#pragma once

#include "structures.hpp"

class cube
{
private:
	vector3 m_position;
	GLfloat m_cube_rotation;
	mesh* m_mesh;

public:
	cube(mesh* mesh, float x, float y, float z);
	~cube();

	void draw();
	void update();
};
