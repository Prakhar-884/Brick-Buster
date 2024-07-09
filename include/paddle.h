#ifndef PADDLE_H
#define PADDLE_H

#include <glm/glm.hpp>

class Paddle
{
public:
    glm::vec2 Position, Size;
    Paddle(float x, float y, float width, float height);
    void Draw();
};

#endif
