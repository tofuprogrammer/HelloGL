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

class HelloGL
{
	Camera* camera;
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