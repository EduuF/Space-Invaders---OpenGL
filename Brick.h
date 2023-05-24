#ifndef BRICK_H
#define BRICK_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Ball.h"

class Ball;


class Brick {
public:
    float x, y;
    float width, height;
    bool destroyed;
    bool visible;

    GLuint VAO, VBO, EBO;

    Brick(float x, float y, float width, float height);
    Brick() {};

    void draw(unsigned int shaderProgram);
    void setupMesh();
    bool intersects(const Ball& ball);
    bool isVisible() const;
    void setVisible(bool isVisible);
};

#endif // BRICK_H
