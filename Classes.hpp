#pragma once

#include "GL/freeglut.h"
#include "GL/gl.h"
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