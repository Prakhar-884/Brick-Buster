#include "game.h"
#include "shader.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/compatibility.hpp>
#include <algorithm>

Shader *shader;

Game::Game(unsigned int width, unsigned int height)
    : Width(width), Height(height)
{
    playerPaddle = new Paddle(width / 2.0f - 50.0f, height - 30.0f, 100.0f, 20.0f);
    ball = new Ball(width / 2.0f, height / 2.0f, 10.0f, glm::vec2(100.0f, -150.0f));
    InitializeBricks();
    shader = new Shader("shaders/vertex_shader.glsl", "shaders/fragment_shader.glsl");
}

void Game::Update()
{
    float deltaTime = 0.016f;
    ball->Move(deltaTime, this->Width);
    playerPaddle->Position.x = std::clamp(playerPaddle->Position.x, 0.0f, static_cast<float>(this->Width - playerPaddle->Size.x));
    if (ball->Position.y + ball->Radius >= playerPaddle->Position.y &&
        ball->Position.x + ball->Radius >= playerPaddle->Position.x &&
        ball->Position.x - ball->Radius <= playerPaddle->Position.x + playerPaddle->Size.x)
    {
        ball->Velocity.y = -ball->Velocity.y;
    }
    for (Brick &brick : bricks)
    {
        if (!brick.Destroyed)
        {
            if (ball->Position.x + ball->Radius >= brick.Position.x &&
                ball->Position.x - ball->Radius <= brick.Position.x + brick.Size.x &&
                ball->Position.y + ball->Radius >= brick.Position.y &&
                ball->Position.y - ball->Radius <= brick.Position.y + brick.Size.y)
            {
                brick.Destroyed = true;
                ball->Velocity.y = -ball->Velocity.y;
            }
        }
    }
    if (ball->Position.y - ball->Radius > this->Height)
    {
        Reset();
    }
}

void Game::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    shader->use();
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(Width), static_cast<float>(Height), 0.0f, -1.0f, 1.0f);
    shader->setMat4("projection", projection);
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(playerPaddle->Position, 0.0f));
    model = glm::scale(model, glm::vec3(playerPaddle->Size, 1.0f));
    shader->setMat4("model", model);
    shader->setVec3("objectColor", glm::vec3(0.8f, 0.2f, 0.2f));
    playerPaddle->Draw();
    model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(ball->Position, 0.0f));
    shader->setMat4("model", model);
    shader->setVec3("objectColor", glm::vec3(0.2f, 0.8f, 0.2f));
    ball->Draw();
    for (Brick &brick : bricks)
    {
        if (!brick.Destroyed)
        {
            model = glm::mat4(1.0f);
            model = glm::translate(model, glm::vec3(brick.Position, 0.0f));
            model = glm::scale(model, glm::vec3(brick.Size, 1.0f));
            shader->setMat4("model", model);
            shader->setVec3("objectColor", glm::vec3(0.2f, 0.2f, 0.8f));
            brick.Draw();
        }
    }
}

void Game::Reset()
{
    playerPaddle->Position = glm::vec2(this->Width / 2.0f - 50.0f, this->Height - 30.0f);
    ball->Position = glm::vec2(this->Width / 2.0f, this->Height / 2.0f);
    ball->Velocity = glm::vec2(100.0f, -150.0f);
    InitializeBricks();
}

void Game::InitializeBricks()
{
    bricks.clear();
    unsigned int rowCount = 5;
    unsigned int colCount = 11;
    float brickWidth = this->Width / colCount;
    float brickHeight = 20.0f;
    for (unsigned int y = 0; y < rowCount; ++y)
    {
        for (unsigned int x = 0; x < colCount; ++x)
        {
            float xpos = x * brickWidth;
            float ypos = y * brickHeight;
            bricks.push_back(Brick(xpos, ypos, brickWidth, brickHeight));
        }
    }
}
