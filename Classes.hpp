#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"
#include "GLUTCallbacks.hpp"

class Vector3 {
public:
    float x, y, z;
};

class Camera {
public:
    Vector3 eye;
    Vector3 center;
    Vector3 up;
};

class Colour {
public:
    GLfloat r, g, b;
};

class Vertex {
public:
    GLfloat x, y, z;
};

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

class HelloGL
{
    Camera* camera;
    Cube* cube[200];
    float rotation;

public:
    //Constructor definition
    HelloGL(int argc, char* argv[]);

    // Destructor definition
    ~HelloGL(void);

    void Display();
    /*
    void DrawPolygon();
    void DrawTorus();
    void DrawCube();
    void DrawCubeArray();
    void DrawIndexedCube();
    void DrawCubeArrayAlt();
    */
    void Update();
    void Keyboard(unsigned char key, int x, int y);
};