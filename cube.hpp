#pragma once

#include "classes.hpp"

class cube
{
private:
	vector3 m_position;
	GLfloat m_cube_rotation;
	mesh* m_mesh;

public:
	cube(mesh* mesh, float x, float y, float z);
	~cube() = default;

	void draw();
	void update();
};
