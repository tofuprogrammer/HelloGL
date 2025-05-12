#pragma once

#include "gl/freeglut.h"

class texture_2d
{
private:
    GLuint m_texture_id;
    int m_width, m_height;

public:
    texture_2d();
    ~texture_2d();

    bool load_texture(char* path, int width, int height);

    GLuint get_texture_id() const
    {
        return m_texture_id;
    }
    int get_width() const
    {
        return m_width;
    }
    int get_height() const
    {
        return m_height;
    }
};
