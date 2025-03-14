#pragma once

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "GL/freeglut.h"
#include "GLUTCallbacks.hpp"

#define REFRESHRATE 8

class HelloGL
{
public:

	//Constructor definition
	HelloGL(int argc, char* argv[]);

	// Destructor definition
	~HelloGL(void);

	void Display();
	void DrawPolygon();
	void Update();

private:

	float rotation;
};