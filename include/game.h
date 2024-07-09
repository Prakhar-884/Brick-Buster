#ifndef GAME_H
#define GAME_H

#include "paddle.h"
#include "ball.h"
#include "brick.h"
#include <vector>

class Game
{
public:
    Game(unsigned int width, unsigned int height);
    void Update();
    void Render();
    Paddle *playerPaddle;
private:
    unsigned int Width, Height;
    Ball *ball;
    std::vector<Brick> bricks;
    void Reset();
    void InitializeBricks();
};

#endif
