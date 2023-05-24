#include "Paddle.h"
#include "Mat4.h"


Paddle::Paddle(float x, float y, float width, float height, float velocityX)
    : x(x), y(y), width(width), height(height), velocityX(velocityX) {
    setupMesh();
}

void Paddle::setupMesh() {
    GLfloat vertices[] = {
        // Posição          // Cores
        x, y,                1.0f, 0.0f, 0.0f, // Canto superior esquerdo
        x + width, y,        0.0f, 1.0f, 0.0f, // Canto superior direito
        x + width, y - height, 0.0f, 0.0f, 1.0f, // Canto inferior direito
        x, y - height,       1.0f, 1.0f, 0.0f  // Canto inferior esquerdo
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

    // Posição dos vértices
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // Cores dos vértices
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(2 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}

void Paddle::update(float deltaTime) {
    x += velocityX * deltaTime;
}

void Paddle::draw(unsigned int shaderProgram) {
    Mat4 transform = Mat4::translation(x, y, 0.0f);

    glUseProgram(shaderProgram);
    unsigned int transformLoc = glGetUniformLocation(shaderProgram, "transform");
    glUniformMatrix4fv(transformLoc, 1, GL_FALSE, transform.data.data());

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}


