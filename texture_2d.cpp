#include <fstream>

#include "texture_2d.hpp"

#include <iostream>

texture_2d::texture_2d()
{

}

texture_2d::~texture_2d()
{
    glDeleteTextures(1, &m_texture_id);
}

bool texture_2d::load_texture(char* path, int width, int height)
{
    char* texture_data;
    int file_size;
    std::ifstream input_file;

    m_width = width;
    m_height = height;

    input_file.open(path, std::ios::binary);
    if (!input_file.good())
    {
        std::cerr << "Can't open texture file " << path << '\n';
        return false;
    }
    input_file.seekg(0, std::ios::end);
    file_size = (int)input_file.tellg();
    texture_data = new char[file_size];
    input_file.seekg(0, std::ios::beg);
    input_file.read(texture_data, file_size);
    input_file.close();

    std::cout << path << " successfully loaded.\n";
    std::cout << "Texture file size: " << file_size << '\n';

    glGenTextures(1, &m_texture_id);
    glBindTexture(GL_TEXTURE_2D, m_texture_id);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, texture_data);

    delete[] texture_data;
    return true;
}
