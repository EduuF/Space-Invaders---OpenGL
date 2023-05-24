#include "Brick.h"
#include "Mat4.h"


Brick::Brick(float x, float y, float width, float height)
    : x(x), y(y), width(width), height(height), destroyed(false), visible(true) {
    setupMesh();
}


void Brick::setupMesh() {
    GLfloat vertices[] = {
        x, y,                  // Canto superior esquerdo
        x + width, y,          // Canto superior direito
        x + width, y - height, // Canto inferior direito
        x, y - height          // Canto inferior esquerdo
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
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Brick::draw(unsigned int shaderProgram) {
    glUseProgram(shaderProgram);

    // Adicionar a cor uniforme
    unsigned int colorLoc = glGetUniformLocation(shaderProgram, "uColor");
    glUniform4f(colorLoc, 0.0f, 0.8f, 0.3f, 1.0f);

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}



bool Brick::isVisible() const {
    return visible;
}

void Brick::setVisible(bool isVisible) {
    visible = isVisible;
}

bool Brick::intersects(const Ball& ball) {
    float brickLeft = x;
    float brickRight = x + width;
    float brickTop = y;
    float brickBottom = y - height;

    float ballLeft = ball.x - ball.radius;
    float ballRight = ball.x + ball.radius;
    float ballTop = ball.y + ball.radius;
    float ballBottom = ball.y - ball.radius;

    return !(brickLeft > ballRight || brickRight < ballLeft || brickTop < ballBottom || brickBottom > ballTop);
}

