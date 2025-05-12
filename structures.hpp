#pragma once

#include "gl/freeglut.h"

struct vertex;
struct colour;
struct mesh;
struct texture_coordinate;

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
    texture_coordinate* texture_coordinates;

    int vertex_count, colour_count, index_count, texture_coordinate_count;
};

struct vertex
{
    GLfloat x, y, z;
};

struct texture_coordinate
{
    GLfloat u, v;
};
