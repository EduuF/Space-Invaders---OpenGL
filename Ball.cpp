#include "Ball.h"
#include "Mat4.h"


Ball::Ball(float x, float y, float radius, float velocityX, float velocityY)
    : x(x), y(y), radius(radius), velocityX(velocityX), velocityY(velocityY) {
    setupMesh();
}

void Ball::setupMesh() {
    GLfloat half_side = radius * 0.5f;
    GLfloat vertices[] = {
        // Posição          // Cores
        x - half_side, y + half_side, 1.0f, 0.0f, 0.0f, // Canto superior esquerdo
        x + half_side, y + half_side, 0.0f, 1.0f, 0.0f, // Canto superior direito
        x + half_side, y - half_side, 0.0f, 0.0f, 1.0f, // Canto inferior direito
        x - half_side, y - half_side, 1.0f, 1.0f, 0.0f  // Canto inferior esquerdo
    };

    GLuint indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Posição
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // Cores
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}


void Ball::update(float deltaTime) {
    x += velocityX * deltaTime;
    y += velocityY * deltaTime;
}

void Ball::draw(unsigned int shaderProgram) {
    Mat4 transform = Mat4::translation(x, y, 0.0f);

    glUseProgram(shaderProgram);
    unsigned int transformLoc = glGetUniformLocation(shaderProgram, "transform");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, transform.data.data());

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}



bool Ball::intersects(const Brick& brick) const {
    // Verificar se a bola intersecta o tijolo
    float ballLeft = x - radius / 2.0f;
    float ballRight = x + radius / 2.0f;
    float ballTop = y + radius / 2.0f;
    float ballBottom = y - radius / 2.0f;
    float brickLeft = brick.x;
    float brickRight = brick.x + brick.width;
    float brickTop = brick.y;
    float brickBottom = brick.y - brick.height;

    if (ballLeft > brickRight || ballRight < brickLeft || ballTop < brickBottom || ballBottom > brickTop) {
        return false;
    }

    return true;
}

bool Ball::intersects(const Paddle& paddle) const {
    float ballLeft = x - radius / 2.0f;
    float ballRight = x + radius / 2.0f;
    float ballTop = y + radius / 2.0f;
    float ballBottom = y - radius / 2.0f;
    float paddleLeft = paddle.x - paddle.width / 2.0f;
    float paddleRight = paddle.x + paddle.width / 2.0f;
    float paddleTop = paddle.y + paddle.height / 2.0f;
    float paddleBottom = paddle.y - paddle.height / 2.0f;

    if (ballLeft > paddleRight || ballRight < paddleLeft || ballTop < paddleBottom || ballBottom > paddleTop) {
        return false;
    }

    return true;
}



