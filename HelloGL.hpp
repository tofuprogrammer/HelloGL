#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"
#include "GLUTCallbacks.hpp"

#define REFRESHRATE 8

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

class HelloGL
{
    Camera* camera;
    float rotation;
    static Vertex vertices[];
	static Vertex indexedVertices[];

    static Colour colours[];
	static Colour indexedColours[];

	static GLushort indices[];

public:
    //Constructor definition
    HelloGL(int argc, char* argv[]);

    // Destructor definition
    ~HelloGL(void);

    void Display();
    void DrawPolygon();
    void DrawTorus();
    void DrawCube();
    void DrawCubeArray();
	void DrawIndexedCube();
    void Update();
    void Keyboard(unsigned char key, int x, int y);
};
