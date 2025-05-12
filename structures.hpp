#pragma once

#include "gl/freeglut.h"

struct vertex;

struct vector3
{
    float x, y, z;
};

struct camera
{
    vector3 eye;
    vector3 center;
    vector3 up;
};

struct colour
{
    GLfloat r, g, b;
};

struct mesh
{
    vertex* vertices;
    colour* colours;
    GLushort* indices;

    int vertex_count, colour_count, index_count;
};

struct vertex
{
    GLfloat x, y, z;
};
