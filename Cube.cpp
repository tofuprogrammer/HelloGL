#include <fstream>
#include <iostream>

#include "Classes.hpp"
#include "Cube.hpp"

int Cube::numVertices = 0;
int Cube::numColours = 0;
int Cube::numIndices = 0;

Colour* Cube::indexedColours = nullptr;
Vertex* Cube::indexedVertices = nullptr;
GLushort* Cube::indices = nullptr;

Cube::Cube(float x, float y, float z) {
	cubeRotation = 0.0f;
	position.x = x, position.y = y, position.z = z;
}

Cube::~Cube() {
}

bool Cube::Load(char* path)
{
	using namespace std;
	ifstream inputFile;
	inputFile.open(path);
	if (!inputFile.good())
	{
		cerr << "Can't open texture file " << path << endl;
		return false;
	}

	inputFile >> numVertices;
	indexedVertices = new Vertex[numVertices];
	for (int iteration = 0; iteration < numVertices; iteration++)
	{
		inputFile >> indexedVertices[iteration].x;
		inputFile >> indexedVertices[iteration].y;
		inputFile >> indexedVertices[iteration].z;
	}

	inputFile >> numColours;
	indexedColours = new Colour[numColours];
	for (int iteration = 0; iteration < numColours; iteration++)
	{
		inputFile >> indexedColours[iteration].r;
		inputFile >> indexedColours[iteration].g;
		inputFile >> indexedColours[iteration].b;
	}

	inputFile >> numIndices;
	indices = new GLushort[numIndices];
	for (int iteration = 0; iteration < numIndices; iteration++)
	{
		inputFile >> indices[iteration];
	}

	inputFile.close();
	return true;
}

void Cube::Draw() {
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, _mesh->vertices);
	glColorPointer(3, GL_FLOAT, 0, _mesh->colours);

	glPushMatrix();
	glTranslatef(position.x, position.y, position.z);
	glRotatef(cubeRotation, -1.0f, -1.0f, -1.0f);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_SHORT, indices);
	glPopMatrix();

	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

void Cube::Update() {
	cubeRotation += 0.5f;
}
