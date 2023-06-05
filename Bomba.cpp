#include "Bomba.h"
#include "Triangle.h"
#include <array>

Bomba::Bomba() {};

Bomba::~Bomba() {};

Bomba::Bomba(glm::vec4 Centro) {
    this->Model = this->getModel();
    this->Up = glm::vec4{ 0.0f, 1.0f, 0.0f, 0.0f };
    this->Right = glm::vec4{ 1.0f, 0.0f, 0.0f, 0.0f };
    this->Centro = Centro;
}


void Bomba::translada(glm::vec3 fatorDeTranslacao) {
    TranslationMatrixBomba(this->Model, this->Centro, fatorDeTranslacao);
}

void Bomba::rotaciona(float graus) {
    RotationMatrixBomba(this->Model, graus, this->Centro, this->Up, this->Right); // Rotaciona o triangulo em rela��o ao centro do OBJ
}

std::array<std::array<Vertex, 3>, 6> Bomba::getModel() {

    // Modela a nave
    glm::vec4 A{ -0.04f, 0.00f,  0.0f, 1.0f };
    glm::vec4 B{ -0.04f,   0.04f,  0.0f, 1.0f };
    glm::vec4 C{ 0.02f, 0.0f,  0.0f, 1.0f };
    glm::vec4 D{ -0.02f, 0.0f,  0.0f, 1.0f };
    glm::vec4 E{ 0.04f, 0.04f,  0.0f, 1.0f };
    glm::vec4 F{ 0.04f,  0.0f,   0.0f, 1.0f };
    glm::vec4 G{ 0.0f,  -0.1f,   0.0f, 1.0f };
    glm::vec4 H{ -0.04f, -0.06f,  0.0f, 1.0f };
    glm::vec4 I{ 0.0f, 0.0f,  0.0f, 1.0f };
    glm::vec4 J{ 0.04f, -0.06f,  0.0f, 1.0f };

    // Bouding Box 

    glm::vec4 BoundingBoxA{ -0.04f, -0.1f,  0.0f, 1.0f };
    glm::vec4 BoundingBoxB{ -0.04f,   0.04f,  0.0f, 1.0f };
    glm::vec4 BoundingBoxC{ 0.04f,   0.04f,  0.0f, 1.0f };
    glm::vec4 BoundingBoxD{ 0.04f, -0.1f,  0.0f, 1.0f };

    // Cores
    glm::vec4 Vermelho{ 1.0f, 0.0f, 0.0f, 1.0f };
    glm::vec4 Verde{ 0.0f, 1.0f, 0.0f, 1.0f };
    glm::vec4 Azul{ 0.0f, 0.0f, 1.0f, 1.0f };
    glm::vec4 AntiVermelho{ 0.0f, 1.0f, 1.0f, 1.0f };
    glm::vec4 AntiVerde{ 1.0f, 0.0f, 1.0f, 1.0f };
    glm::vec4 AntiAzul{ 1.0f, 1.0f, 0.0f, 1.0f };

    glm::vec4 CorCorpo{ 0.45f, 0.56f, 0.67f, 1.0f };
    glm::vec4 CorCanhaoDireito{ 0.1f, 0.0f, 1.0f, 1.0f };
    glm::vec4 CorCanhaoEsquerdo{ 0.1f, 0.0f, 1.0f, 1.0f };
    glm::vec4 CorMotorDireito{ 1.0f, 0.0f, 0.0f, 1.0f };
    glm::vec4 CorMotorEsquerdo{ 1.0f, 0.0f, 0.0f, 1.0f };
    glm::vec4 CorBoudingBox{ 0.0f, 0.0f, 0.0f, 1.0f };

    // Texturas
    glm::vec2 TexturaCorpo{ 0.45f, 0.56f };
    glm::vec2 TexturaCanhaoDireito{ 1.0f, 1.0f };
    glm::vec2 TexturaCanhaoEsquerdo{ 1.0f, 1.0f };
    glm::vec2 TexturaMotorDireito{ 1.0f, 1.0f };
    glm::vec2 TexturaMotorEsquerdo{ 1.0f, 1.0f };
    glm::vec2 TexturaBoudingBox{ 1.0f, 1.0f };

    std::array<Vertex, 3> AletaEsquerda = {
        Vertex{A, CorCorpo, {0.0f, 0.0f}},
        Vertex{B, AntiVerde, {1.0f, 0.0f}},
        Vertex{C, CorCorpo, {1.0f, 1.0f}} };

    std::array<Vertex, 3> AletaDireita = {
        Vertex{D, AntiVermelho},
        Vertex{E, AntiVerde},
        Vertex{F, AntiAzul} };

    std::array<Vertex, 3> Corpo1 = {
        Vertex{G, AntiAzul},
        Vertex{H, AntiVermelho},
        Vertex{I, AntiVerde} };

    std::array<Vertex, 3> Corpo2 = {
        Vertex{G, CorMotorEsquerdo},
        Vertex{I, CorMotorEsquerdo},
        Vertex{J, CorMotorEsquerdo} };

    std::array<Vertex, 3> BoudingBox1 = {
        Vertex{BoundingBoxA, CorBoudingBox},
        Vertex{BoundingBoxC, CorBoudingBox},
        Vertex{BoundingBoxB, CorBoudingBox} };

    std::array<Vertex, 3> BoudingBox2 = {
        Vertex{BoundingBoxA, CorBoudingBox},
        Vertex{BoundingBoxD, CorBoudingBox},
        Vertex{BoundingBoxC, CorBoudingBox} };


    std::array<std::array<Vertex, 3>, 6> BombaVertices = {

        // Aletas
        AletaEsquerda,
        AletaDireita,
        // Corpo
        Corpo1,
        Corpo2,

        // Bouding Box
        BoudingBox1,
        // Bouding Box
        BoudingBox2

    };

    return BombaVertices;
}