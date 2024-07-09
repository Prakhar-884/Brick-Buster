#include "paddle.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

Paddle::Paddle(float x, float y, float width, float height)
    : Position(glm::vec2(x, y)), Size(glm::vec2(width, height)) {}

void Paddle::Draw()
{
    
    glBegin(GL_QUADS);
    glVertex2f(Position.x, Position.y);
    glVertex2f(Position.x + Size.x, Position.y);
    glVertex2f(Position.x + Size.x, Position.y + Size.y);
    glVertex2f(Position.x, Position.y + Size.y);
    glEnd();
}
