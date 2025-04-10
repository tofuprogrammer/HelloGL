#pragma once

#include "Classes.hpp"

class Cube
{
private:
	Vector3 position;
	GLfloat cubeRotation;
	Mesh* _mesh;

public:
	Cube(Mesh* mesh, float x, float y, float z);
	~Cube();

	void Draw();
	void Update();
};

