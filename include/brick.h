#ifndef BRICK_H
#define BRICK_H

#include <glm/glm.hpp>

class Brick
{
public:
    glm::vec2 Position, Size;
    bool Destroyed;
    Brick(float x, float y, float width, float height);
    void Draw();
};

#endif
