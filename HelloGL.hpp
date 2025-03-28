#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"
#include "GLUTCallbacks.hpp"
#include "Classes.hpp"

#define REFRESHRATE 8

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
    void DrawCubeArrayAlt();
	void DrawIndexedCubeAlt();
    void Update();
    void Keyboard(unsigned char key, int x, int y);
};
