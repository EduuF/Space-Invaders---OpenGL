#include "Bomba.h"
#include "Triangle.h"
#include <array>

Bomba::Bomba() {};

Bomba::~Bomba() {};

Bomba::Bomba(glm::vec4 Centro, float CountDown) {
    this->Model = this->getModel();
    this->Up = glm::vec4{ 0.0f, 1.0f, 0.0f, 0.0f };
    this->Right = glm::vec4{ 1.0f, 0.0f, 0.0f, 0.0f };
    this->Centro = glm::vec4{ Centro.x, Centro.y - 0.12f, 0.0f, 1.0f };

    // Altera os vértices da nave
    glm::vec4 Origem = { 0.0f, 0.0f, 0.0f, 1.0f };
    TranslationMatrix(this->Model, Origem, this->Up, this->Centro);

    this->escala = glm::vec3{ 1.0f, 1.0f, 1.0f };
    this->Dropada = false;
    this->Aumentando = true;
    this->CountDown = CountDown;

    this->ajustaEscala(glm::vec3{ 1.5f, 1.5f, 0.0f });
    this->escala = glm::vec3{ 1.0f, 1.0f, 1.0f };
}


void Bomba::translada(glm::vec3 fatorDeTranslacao) {
    TranslationMatrix(this->Model, this->Centro, this->Up ,fatorDeTranslacao);
}

void Bomba::rotaciona(float graus) {
    RotationMatrix(this->Model, graus, this->Centro, this->Up, this->Right); // Rotaciona o triangulo em relação ao centro do OBJ
}

void Bomba::ajustaEscala(glm::vec3 FatorDeEscala) {
    ScaleMatrix(this->Model, FatorDeEscala, this->Centro); // Escala o triangulo
    this->escala *= FatorDeEscala;
}

void Bomba::ajustaEixoZ() {
    TranslationMatrix(this->Model, this->Centro, this->Up, glm::vec3{ 0.0f, 0.0f, 0.0f - this->Centro.z});
}

void Bomba::pisca(float DeltaTime, float intensidadeDePiscada, float velocidadeDePiscada) {
    if (this->escala.x >= intensidadeDePiscada) {
        this->Aumentando = false;
    }
    if (this->escala.x <= 0.9f) {
        this->Aumentando = true;
    }

    if (this->Aumentando) {
        this->ajustaEscala(glm::vec3{ 1 + DeltaTime * velocidadeDePiscada, 1 + DeltaTime * velocidadeDePiscada, 0.0f });
    }
    else {
        this->ajustaEscala(glm::vec3{ 1 - DeltaTime * velocidadeDePiscada, 1 - DeltaTime * velocidadeDePiscada, 0.0f });
    }
}

std::vector<std::vector<Vertex>> Bomba::getModel() {

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

    glm::vec4 CorAleta{ 0.65f, 0.18f, 0.18f, 1.0f };
    glm::vec4 CorCorpo{ 0.65f, 0.20f, 0.50f, 1.0f };
    glm::vec4 CorCorpo2{ 0.75f, 0.25f, 0.60f, 1.0f };
    glm::vec4 CorBoudingBox{ 0.0f, 0.0f, 0.0f, 1.0f };

    // Texturas
    glm::vec2 TexturaCorpo{ 0.45f, 0.56f };
    glm::vec2 TexturaBoudingBox{ 1.0f, 1.0f };

    std::vector<Vertex> AletaEsquerda = {
        Vertex{A, CorAleta, {0.0f, 0.0f}},
        Vertex{C, CorAleta, {1.0f, 0.0f}},
        Vertex{B, CorAleta, {1.0f, 1.0f}} };

    std::vector<Vertex> AletaDireita = {
        Vertex{D, CorAleta},
        Vertex{F, CorAleta},
        Vertex{E, CorAleta} };

    std::vector<Vertex> Corpo1 = {
        Vertex{G, CorCorpo},
        Vertex{I, CorCorpo},
        Vertex{H, CorCorpo} };

    std::vector<Vertex> Corpo2 = {
        Vertex{G, CorCorpo2},
        Vertex{J, CorCorpo2},
        Vertex{I, CorCorpo2} };

    std::vector<Vertex> BoudingBox1 = {
        Vertex{BoundingBoxA},
        Vertex{BoundingBoxC},
        Vertex{BoundingBoxB} };

    std::vector<Vertex> BoudingBox2 = {
        Vertex{BoundingBoxA},
        Vertex{BoundingBoxD},
        Vertex{BoundingBoxC} };


    std::vector<std::vector<Vertex>> BombaVertices = {

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