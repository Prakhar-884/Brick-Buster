#include "ball.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <cmath>

Ball::Ball(float x, float y, float radius, glm::vec2 velocity)
    : Position(glm::vec2(x, y)), Velocity(velocity), Radius(radius) {}

void Ball::Move(float dt, unsigned int window_width)
{
    Position += Velocity * dt;

    
    if (Position.x <= 0.0f)
    {
        Position.x = 0.0f;
        Velocity.x = -Velocity.x;
    }
    if (Position.x + Radius * 2 >= window_width)
    {
        Position.x = window_width - Radius * 2;
        Velocity.x = -Velocity.x;
    }
    if (Position.y <= 0.0f)
    {
        Position.y = 0.0f;
        Velocity.y = -Velocity.y;
    }
}

void Ball::Draw()
{
    
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(Position.x + Radius, Position.y + Radius);
    for (int i = 0; i <= 360; i += 10)
    {
        float theta = i * 3.1415926 / 180;
        float x = Radius * cosf(theta);
        float y = Radius * sinf(theta);
        glVertex2f(Position.x + Radius + x, Position.y + Radius + y);
    }
    glEnd();
}
