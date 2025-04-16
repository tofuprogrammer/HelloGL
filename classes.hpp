#pragma once

#include "gl/freeglut.h"

class vector3;
class camera;
class colour;
class mesh;
class vertex;

class vector3
{
public:
    float x, y, z;
};

class camera
{
public:
    vector3 eye;
    vector3 center;
    vector3 up;
};

class colour
{
public:
    GLfloat r, g, b;
};

class mesh
{
    public:
    vertex* vertices;
    colour* colours;
    GLushort* indices;

    int vertex_count, colour_count, index_count;
};

class vertex
{
public:
    GLfloat x, y, z;
};
