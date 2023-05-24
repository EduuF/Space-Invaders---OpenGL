#ifndef PADDLE_H
#define PADDLE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Paddle {
public:
    float x, y;
    float width, height;
    float velocityX;

    GLuint VAO, VBO, EBO;

    Paddle(float x, float y, float width, float height, float velocityX);
    Paddle() {};

    void update(float deltaTime);
    void draw(unsigned int shaderProgram);
    void setupMesh();
};

#endif // PADDLE_H
