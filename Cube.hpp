#pragma once

#include "structures.hpp"

class cube
{
private:
	vector3 m_cube_position;
	GLfloat m_cube_rotation;
	mesh* m_cube_mesh;

public:
	cube(mesh* mesh, float x, float y, float z);
	~cube();

	void cube_draw();
	void cube_update();
};
