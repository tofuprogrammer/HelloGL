#pragma once

#include "Classes.hpp"

class Cube
{
private:
	Vector3 m_position;
	GLfloat m_cube_rotation;
	Mesh* m_mesh;

public:
	Cube(Mesh* mesh, float x, float y, float z);
	~Cube() = default;

	void draw();
	void update();
};