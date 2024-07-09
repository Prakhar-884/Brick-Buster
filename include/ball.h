#ifndef BALL_H
#define BALL_H

#include <glm/glm.hpp>

class Ball
{
public:
    glm::vec2 Position, Velocity;
    float Radius;
    Ball(float x, float y, float radius, glm::vec2 velocity);
    void Move(float dt, unsigned int window_width);
    void Draw();
};

#endif
