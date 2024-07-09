# Brick-Buster
# Breakout Game in C++ with OpenGL

![Gameplay Screenshot](screenshot.png)

## Description
This project is an implementation of the classic Breakout arcade game using C++ and OpenGL. It features paddle-ball mechanics, brick destruction, collision detection, and basic game physics. Developed as a learning exercise in object-oriented programming and OpenGL integration.

## Technologies Used
- C++
- OpenGL
- GLFW

## Features
- Player-controlled paddle movement.
- Ball bouncing and collision with bricks and paddle.
- Brick destruction upon ball impact.
- Simple game physics for ball movement.

## Getting Started
To run this project locally, follow these steps:

### Prerequisites
- Ensure you have GLFW and OpenGL installed.

### Installation
1. **Clone the repository:**
   ```bash
   git clone https://github.com/Prakhar-884/breakout-game.git
   cd breakout-game
## Build the project
g++ -o main main.cpp game.cpp paddle.cpp ball.cpp brick.cpp shader.cpp -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl
## Run the game
./main
## Usage
Use the left and right arrow keys to move the paddle.
Keep the ball bouncing to break all the bricks and win the game.

## Credits
This project uses GLFW for window and input handling.
Textures and shaders adapted from LearnOpenGL tutorials.
