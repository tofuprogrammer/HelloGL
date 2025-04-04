#pragma once

#include "Classes.hpp"

class Cube
{
private:
	Vector3 position;
	GLfloat cubeRotation;
	static int numVertices, numColours, numIndices;
	static Vertex vertices[];
	static Colour colours[];
	static Vertex* indexedVertices;
	static Colour* indexedColours;
	static GLushort* indices;

public:
	Cube(float x, float y, float z);
	~Cube();

	void Draw();
	void Update();
	static bool Load(char* path);
};

