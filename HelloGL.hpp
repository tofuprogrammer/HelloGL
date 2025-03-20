#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"
#include "GLUTCallbacks.hpp"

#define REFRESHRATE 8

class HelloGL
{
	
	float rotation;

public:

	//Constructor definition
	HelloGL(int argc, char* argv[]);

	// Destructor definition
	~HelloGL(void);

	void Display();
	void DrawPolygon();
	void Update();
	void keyboard(unsigned char key, int x, int y);
};