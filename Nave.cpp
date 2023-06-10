#include "Nave.h"
#include "Matrices.h"
#include "Triangle.h"
#include <iostream>

Nave::Nave(glm::vec4 NaveCentro) {

    this->NaveCentro = NaveCentro; // Diz qual � o centro de onde o objeto ser� criado
    std::vector<std::vector<Vertex>> NaveModel = this->getNaveModel(); // Modelo Base

    this->modeloDaNave = NaveModel; // Acopla modelo base

    // Define o UP da nave
    this->NaveUp = glm::vec4{ 0.0f, 1.0f, 0.0f, 0.0f };

    // Define o Right da nave
    this->naveRight = glm::vec4{1.0f, 0.0f, 0.0f, 0.0f};

    // Altera os v�rtices da nave
    glm::vec4 Origem = { 0.0f, 0.0f, 0.0f, 1.0f };
    TranslationMatrix(this->modeloDaNave, Origem, this->NaveUp , this->NaveCentro);

    this->escala = glm::vec3{ 1.0f, 1.0f, 1.0f };
    this->CanhaoDireitoAtira = false; 
    this->life = 3000;
    this->tempoDeIntangibilidade = 2.0f;
    this->intangivel = false;
    this->TempoPiscando = 0.2f;
    this->piscando = false;
}

void Nave::ajustaEscalaDaNave(glm::vec3 FatorDeEscala) {
    ScaleMatrix(this->modeloDaNave, FatorDeEscala, this->NaveCentro); // Escala o triangulo
    this->escala *= FatorDeEscala;
}

void Nave::transladaANave(glm::vec3 fatorDeTranslacao) {
    TranslationMatrix(this->modeloDaNave, this->NaveCentro, this->NaveUp , fatorDeTranslacao);
}

void Nave::rotacionaANave(float graus) {
    RotationMatrix(this->modeloDaNave, graus, this->NaveCentro, this->NaveUp, this->naveRight); // Rotaciona o OBJ em rela��o a seu centro
}

void Nave::pisca(float tempoDePiscada, float DeltaTime) {
    // Se ela est� no estado apagado durante a piscada
    if (this->piscando) {
        this->TempoPiscando -= DeltaTime; // Diminui o tempo de piscada
    } else {
        this->TempoPiscando += DeltaTime; // Aumenta o tempo de piscada
    }

    // Se o tempo de piscada chegar a 0, muda para estado "Aceso"
    if (this->TempoPiscando <= 0.0f) {
        this->piscando = false;
    }

    // Se o tempo de piscada chegar ao m�ximo, muda para estado "Apagado"
    if (this->TempoPiscando >= tempoDePiscada) {
        this->piscando = true;
    }
};

void Nave::MoveNaveLateralmente(double MouseXPos, float VelocidadeLateralNave) {
    float realSpeed = (MouseXPos - this->NaveCentro.x) * VelocidadeLateralNave;
    glm::vec3 fatorDeTransalacao{ realSpeed , 0.0f, 0.0f };

    // N�o pode passar da barreira direita
    if (realSpeed + this->NaveCentro.x > 1.9f) {
        fatorDeTransalacao = glm::vec3{ 1.9f - this->NaveCentro.x , 0.0f, 0.0f };
    }

    // N�o pode passar da barreira esquerda
    if (realSpeed + this->NaveCentro.x < -1.9f) {
        fatorDeTransalacao = glm::vec3{ -1.9f - this->NaveCentro.x , 0.0f, 0.0f };
    }

    this->transladaANave(fatorDeTransalacao);
}

void Nave::AtualizaTempoDeTangibilidade(float DeltaTime, float tempoDeIntangibilidadeNave) {
    this->tempoDeIntangibilidade -= 1.0f * DeltaTime;
    if (this->tempoDeIntangibilidade <= 0.0f) {
        this->tempoDeIntangibilidade = tempoDeIntangibilidadeNave;
        this->intangivel = false;
    }
}


std::vector<std::vector<Vertex>> Nave::getNaveModel() {

    // Modela a nave
    glm::vec4 A{ -0.04f, -0.03f,  0.0f, 1.0f };
    glm::vec4 B{  0.0f,   0.05f,  0.0f, 1.0f };
    glm::vec4 C{  0.04f, -0.03f,  0.0f, 1.0f };
    glm::vec4 D{ -0.08f, -0.03f,  0.0f, 1.0f };
    glm::vec4 E{ -0.06f,  0.0f,   0.0f, 1.0f };
    glm::vec4 F{  0.06f,  0.0f,   0.0f, 1.0f };
    glm::vec4 G{  0.08f, -0.03f,  0.0f, 1.0f };
    glm::vec4 H{ -0.03f, -0.05f,  0.0f, 1.0f };
    glm::vec4 I{ -0.05f, -0.05f,  0.0f, 1.0f };
    glm::vec4 J{  0.05f, -0.05f,  0.0f, 1.0f };
    glm::vec4 K{  0.03f, -0.05f,  0.0f, 1.0f };

    // Bouding Box 

    glm::vec4 BoundingBoxA{ -0.08f, -0.05f,  0.0f, 1.0f };
    glm::vec4 BoundingBoxB{ -0.08f,   0.05f,  0.0f, 1.0f };
    glm::vec4 BoundingBoxC{ 0.08f,   0.05f,  0.0f, 1.0f };
    glm::vec4 BoundingBoxD{ 0.08f, -0.05f,  0.0f, 1.0f };

    // Cores
    glm::vec4 Vermelho         { 1.0f, 0.0f, 0.0f, 1.0f };
    glm::vec4 Verde            { 0.0f, 1.0f, 0.0f, 1.0f };
    glm::vec4 Azul             { 0.0f, 0.0f, 1.0f, 1.0f };
    glm::vec4 AntiVermelho     { 0.0f, 1.0f, 1.0f, 1.0f };
    glm::vec4 AntiVerde        { 1.0f, 0.0f, 1.0f, 1.0f };
    glm::vec4 AntiAzul         { 1.0f, 1.0f, 0.0f, 1.0f };

    glm::vec4 CorCorpo         { 0.45f, 0.56f, 0.67f, 1.0f };
    glm::vec4 CorCanhaoDireito { 0.1f, 0.0f, 1.0f, 1.0f };
    glm::vec4 CorCanhaoEsquerdo{ 0.1f, 0.0f, 1.0f, 1.0f };
    glm::vec4 CorMotorDireito  { 1.0f, 0.0f, 0.0f, 1.0f };
    glm::vec4 CorMotorEsquerdo { 1.0f, 0.0f, 0.0f, 1.0f };
    glm::vec4 CorBoudingBox   { 0.0f, 0.0f, 0.0f, 1.0f };

    // Texturas
    glm::vec2 TexturaCorpo{ 0.45f, 0.56f };
    glm::vec2 TexturaCanhaoDireito{ 1.0f, 1.0f };
    glm::vec2 TexturaCanhaoEsquerdo{ 1.0f, 1.0f };
    glm::vec2 TexturaMotorDireito{ 1.0f, 1.0f };
    glm::vec2 TexturaMotorEsquerdo{ 1.0f, 1.0f };
    glm::vec2 TexturaBoudingBox{ 1.0f, 1.0f };

    std::vector<Vertex> Corpo = { 
        Vertex{A, CorCorpo, {0.0f, 0.0f}},
        Vertex{C, AntiVerde, {1.0f, 0.0f}},
        Vertex{B, CorCorpo, {1.0f, 1.0f}} };

    std::vector<Vertex> CanhaoEsquerdo = { 
        Vertex{A, AntiVermelho}, 
        Vertex{E, AntiVerde}, 
        Vertex{D, AntiAzul} };

    std::vector<Vertex> CanhaoDireito = { 
        Vertex{C, AntiAzul}, 
        Vertex{G, AntiVermelho}, 
        Vertex{F, AntiVerde} };

    std::vector<Vertex> MotorEsquerdo = { 
        Vertex{A, CorMotorEsquerdo}, 
        Vertex{I, CorMotorEsquerdo}, 
        Vertex{H, CorMotorEsquerdo} };

    std::vector<Vertex> MotorDireito = { 
        Vertex{C, CorMotorDireito}, 
        Vertex{K, CorMotorDireito}, 
        Vertex{J, CorMotorDireito} };

    std::vector<Vertex> BoudingBox1 = { 
        Vertex{BoundingBoxA, CorBoudingBox}, 
        Vertex{BoundingBoxC, CorBoudingBox}, 
        Vertex{BoundingBoxB, CorBoudingBox} };

    std::vector<Vertex> BoudingBox2 = { 
        Vertex{BoundingBoxA, CorBoudingBox}, 
        Vertex{BoundingBoxD, CorBoudingBox}, 
        Vertex{BoundingBoxC, CorBoudingBox} };


    std::vector<std::vector<Vertex>> NaveVertices = {

        // Corpo
        Corpo,
        // Asa esquerda
        CanhaoEsquerdo,
        // Asa direita
        CanhaoDireito,
        // Entrada de ar
        MotorEsquerdo,
        // FarolEsqcuerdo
        MotorDireito,

        // Bouding Box
        BoudingBox1,
        // Bouding Box
        BoudingBox2

    };

    return NaveVertices;
}

void Nave::MoveRight(float Amount) {
    this->rotacionaANave(Amount);
}

Missil Nave::Atira(float velocidade) {

    bool NaveOuAlien = true;

    if (this->CanhaoDireitoAtira) {

        Missil missil(NaveOuAlien, this->modeloDaNave[2][2].Position, this->NaveUp, velocidade);
        this->CanhaoDireitoAtira = false;
        return missil;
    }
    else {
        Missil missil(NaveOuAlien, this->modeloDaNave[1][1].Position, this->NaveUp, velocidade);
        this->CanhaoDireitoAtira = true;
        return missil;
    }
}

