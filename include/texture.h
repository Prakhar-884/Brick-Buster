#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>
#include <string>
#include <iostream>

class Texture2D
{
public:
    unsigned int ID;
    int Width, Height;
    unsigned int Internal_Format;
    unsigned int Image_Format;

    Texture2D();
    void Generate(unsigned int width, unsigned int height, unsigned char* data);
    void Bind() const;
};

#endif
