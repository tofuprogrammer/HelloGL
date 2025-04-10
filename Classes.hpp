#pragma once

#include "gl/freeglut.h"

class Vector3;
class Camera;
class Colour;
class Mesh;
class Vertex;

class Vector3
{
public:
    float x, y, z;
};

class Camera
{
public:
    Vector3 eye;
    Vector3 center;
    Vector3 up;
};

class Colour
{
public:
    GLfloat r, g, b;
};

class Mesh
{
    public:
    Vertex* vertices;
    Colour* colours;
    GLushort* indices;

    int vertexCount, colourCount, indexCount;
};

class Vertex
{
public:
    GLfloat x, y, z;
};
