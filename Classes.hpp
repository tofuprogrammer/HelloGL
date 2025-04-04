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