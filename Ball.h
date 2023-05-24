#ifndef BALL_H
#define BALL_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Paddle.h"
#include "Brick.h"

class Paddle;
class Brick;

class Ball {
public:
    float x, y;
    float radius;
    float velocityX, velocityY;

    Ball(float x, float y, float radius, float velocityX, float velocityY);
    Ball() {};

    void update(float deltaTime);
    void draw(unsigned int shaderProgram);
    bool intersects(const Brick& brick) const;
    bool intersects(const Paddle& paddle) const;


private:
    unsigned int VAO, VBO, EBO;
    void setupMesh();
};

#endif // BALL_H
