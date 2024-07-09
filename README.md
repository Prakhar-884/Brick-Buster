# Brick-Buster
Breakout Game in C++ with OpenGL

Description
This project is an implementation of the classic Breakout arcade game using C++ and OpenGL. It features paddle-ball mechanics, brick destruction, collision detection, and basic game physics. Developed as a learning exercise in object-oriented programming and OpenGL integration.

Technologies Used
C++
OpenGL
GLFW
Features
Player-controlled paddle movement.
Ball bouncing and collision with bricks and paddle.
Brick destruction upon ball impact.
Simple game physics for ball movement.
Getting Started
To run this project locally, follow these steps:

Clone the repository:

bash
Copy code
git clone https://github.com/your-username/breakout-game.git
cd breakout-game
Build and run the game:

Ensure you have GLFW and OpenGL installed.
Compile the source code (example using g++):
bash
Copy code
g++ -o main main.cpp game.cpp paddle.cpp ball.cpp brick.cpp shader.cpp -lglfw -lGL -lX11 -lpthread -lXrandr -lXi -ldl
Run the compiled executable:
bash
Copy code
./main
Usage
Use the left and right arrow keys to move the paddle.
Keep the ball bouncing to break all the bricks and win the game.
Contributing
Contributions are welcome! If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.

Credits
This project uses GLFW for window and input handling.
Textures and shaders adapted from LearnOpenGL tutorials.
License
This project is licensed under the MIT License - see the LICENSE file for details.
