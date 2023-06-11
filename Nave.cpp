#include "Nave.h"
#include "Matrices.h"
#include "Triangle.h"
#include <iostream>

Nave::Nave(glm::vec4 NaveCentro) {

    this->NaveCentro = NaveCentro; // Diz qual é o centro de onde o objeto será criado
    std::vector<std::vector<Vertex>> NaveModel = this->getNaveModel(); // Modelo Base

    this->modeloDaNave = NaveModel; // Acopla modelo base

    // Define o UP da nave
    this->NaveUp = glm::vec4{ 0.0f, 1.0f, 0.0f, 0.0f };

    // Define o Right da nave
    this->naveRight = glm::vec4{1.0f, 0.0f, 0.0f, 0.0f};

    // Altera os vértices da nave
    glm::vec4 Origem = { 0.0f, 0.0f, 0.0f, 1.0f };
    TranslationMatrix(this->modeloDaNave, Origem, this->NaveUp , this->NaveCentro);

    
    this->CanhaoDireitoAtira = false; 
    this->life = 500;
    this->tempoDeIntangibilidade = 2.0f;
    this->intangivel = false;
    this->TempoPiscando = 0.2f;
    this->piscando = false;
    this->ajustaEscalaDaNave(glm::vec3{ 0.2f, 0.2f, 0.2f });
    this->escala = glm::vec3{ 1.0f, 1.0f, 1.0f };
}

void Nave::ajustaEscalaDaNave(glm::vec3 FatorDeEscala) {
    ScaleMatrix(this->modeloDaNave, FatorDeEscala, this->NaveCentro); // Escala o triangulo
    this->escala *= FatorDeEscala;
}

void Nave::transladaANave(glm::vec3 fatorDeTranslacao) {
    TranslationMatrix(this->modeloDaNave, this->NaveCentro, this->NaveUp , fatorDeTranslacao);
}

void Nave::rotacionaANave(float graus) {
    RotationMatrix(this->modeloDaNave, graus, this->NaveCentro, this->NaveUp, this->naveRight); // Rotaciona o OBJ em relação a seu centro
}

void Nave::pisca(float tempoDePiscada, float DeltaTime) {
    // Se ela está no estado apagado durante a piscada
    if (this->piscando) {
        this->TempoPiscando -= DeltaTime; // Diminui o tempo de piscada
    } else {
        this->TempoPiscando += DeltaTime; // Aumenta o tempo de piscada
    }

    // Se o tempo de piscada chegar a 0, muda para estado "Aceso"
    if (this->TempoPiscando <= 0.0f) {
        this->piscando = false;
    }

    // Se o tempo de piscada chegar ao máximo, muda para estado "Apagado"
    if (this->TempoPiscando >= tempoDePiscada) {
        this->piscando = true;
    }
};

void Nave::MoveNaveLateralmente(double MouseXPos, float VelocidadeLateralNave) {
    float realSpeed = (MouseXPos - this->NaveCentro.x) * VelocidadeLateralNave;
    glm::vec3 fatorDeTransalacao{ realSpeed , 0.0f, 0.0f };

    // Não pode passar da barreira direita
    if (realSpeed + this->NaveCentro.x > 1.9f) {
        fatorDeTransalacao = glm::vec3{ 1.9f - this->NaveCentro.x , 0.0f, 0.0f };
    }

    // Não pode passar da barreira esquerda
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
    glm::vec4 A{  0.0f,  0.70f,  0.0f, 1.0f };
    glm::vec4 B{ -0.05f, 0.65f,  0.0f, 1.0f };
    glm::vec4 C{  0.0f,  0.65f,  0.0f, 1.0f };
    glm::vec4 D{ -0.06f, 0.56f,  0.0f, 1.0f };
    glm::vec4 E{  0.0f,  0.60f,   0.0f, 1.0f };
    glm::vec4 F{ -0.07f,  0.56f,   0.0f, 1.0f };
    glm::vec4 G{ -0.1f, -0.2f,  0.0f, 1.0f };
    glm::vec4 H{  0.0f, -0.2f,  0.0f, 1.0f };
    glm::vec4 I{ -0.12f, 0.38f,  0.0f, 1.0f };
    glm::vec4 J{ -0.15f,-0.2f,  0.0f, 1.0f };
    glm::vec4 K{ -0.06f,  0.46f,  0.0f, 1.0f };
    glm::vec4 L{ -0.127f, 0.24f,  0.0f, 1.0f };
    glm::vec4 M{ -1.1f, 0.0f,  0.0f, 1.0f };
    glm::vec4 N{ -0.138f, 0.0f,  0.0f, 1.0f };
    glm::vec4 O{ -0.018f,-0.15f,  0.0f, 1.0f };
    glm::vec4 P{ -0.06f, -0.32f,   0.0f, 1.0f };
    glm::vec4 Q{ -0.25f, -0.32f,   0.0f, 1.0f };
    glm::vec4 R{ -1.13f, 0.16f,  0.0f, 1.0f };
    glm::vec4 S{ -1.14f, 0.0f,  0.0f, 1.0f };
    glm::vec4 T{ -1.1f, 0.16f,  0.0f, 1.0f };
    glm::vec4 U{ -0.489f, 0.1885f,  0.0f, 1.0f };
    glm::vec4 V{ -1.1f, 0.1f,  0.0f, 1.0f };
    glm::vec4 W{ -0.46f,  0.24f,  0.0f, 1.0f };
    glm::vec4 Z{ -0.442f,  0.198f,  0.0f, 1.0f };
    glm::vec4 A1{ -0.43f, 0.24f,  0.0f, 1.0f };
    glm::vec4 AntiA{ 0.0f, 0.70f,  0.0f, 1.0f };
    glm::vec4 AntiB{ 0.05f,   0.65f,  0.0f, 1.0f };
    glm::vec4 AntiC{ 0.0f, 0.65f,  0.0f, 1.0f };
    glm::vec4 AntiD{ 0.05f, 0.60f,  0.0f, 1.0f };
    glm::vec4 AntiE{ 0.0f,  0.60f,   0.0f, 1.0f };
    glm::vec4 AntiF{ 0.1f,  0.60f,   0.0f, 1.0f };
    glm::vec4 AntiG{ 0.1f, -0.2f,  0.0f, 1.0f };
    glm::vec4 AntiH{ 0.0f, -0.2f,  0.0f, 1.0f };
    glm::vec4 AntiI{ 0.15f, 0.45f,  0.0f, 1.0f };
    glm::vec4 AntiJ{ 0.15f, -0.2f,  0.0f, 1.0f };
    glm::vec4 AntiK{ 0.1f, 0.45f,  0.0f, 1.0f };
    glm::vec4 AntiL{ 0.15f, 0.25f,  0.0f, 1.0f };
    glm::vec4 AntiM{ 1.1f, 0.0f,  0.0f, 1.0f };
    glm::vec4 AntiN{ 0.15f, 0.0f,  0.0f, 1.0f };
    glm::vec4 AntiO{ 0.018f,-0.15f,  0.0f, 1.0f };
    glm::vec4 AntiP{ 0.06f, -0.32f,   0.0f, 1.0f };
    glm::vec4 AntiQ{ 0.25f, -0.32f,   0.0f, 1.0f };
    glm::vec4 AntiR{ 1.13f, 0.16f,  0.0f, 1.0f };
    glm::vec4 AntiS{ 1.14f, 0.0f,  0.0f, 1.0f };
    glm::vec4 AntiT{ 1.1f, 0.16f,  0.0f, 1.0f };
    glm::vec4 AntiU{ 0.5f, 0.195f,  0.0f, 1.0f };
    glm::vec4 AntiV{ 1.1f, 0.1f,  0.0f, 1.0f };
    glm::vec4 AntiW{ 0.49f,  0.25f,  0.0f, 1.0f };
    glm::vec4 AntiZ{ 0.45f,  0.202f,  0.0f, 1.0f };
    glm::vec4 AntiA1{0.46f, 0.25f,  0.0f, 1.0f };

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

    std::vector<Vertex> BoudingBox1 = { 
        Vertex{BoundingBoxA, CorBoudingBox}, 
        Vertex{BoundingBoxC, CorBoudingBox}, 
        Vertex{BoundingBoxB, CorBoudingBox} };

    std::vector<Vertex> BoudingBox2 = { 
        Vertex{BoundingBoxA, CorBoudingBox}, 
        Vertex{BoundingBoxD, CorBoudingBox}, 
        Vertex{BoundingBoxC, CorBoudingBox} };

    std::vector<Vertex> Cabine = {
        Vertex{A},
        Vertex{B},
        Vertex{C} };

    std::vector<Vertex> Corpo1 = {
        Vertex{C},
        Vertex{B},
        Vertex{E} };

    std::vector<Vertex> Corpo2 = {
        Vertex{B},
        Vertex{D},
        Vertex{E} };

    std::vector<Vertex> Corpo3 = {
        Vertex{E},
        Vertex{F},
        Vertex{H} };

    std::vector<Vertex> Corpo4 = {
        Vertex{F},
        Vertex{G},
        Vertex{H} };

    std::vector<Vertex> Corpo5 = {
        Vertex{I},
        Vertex{G},
        Vertex{K} };

    std::vector<Vertex> Corpo6 = {
        Vertex{I},
        Vertex{J},
        Vertex{G} };

    std::vector<Vertex> Turbina1 = {
        Vertex{O},
        Vertex{Q},
        Vertex{P} };

    std::vector<Vertex> Turbina2 = {
        Vertex{O},
        Vertex{J},
        Vertex{Q} };

    std::vector<Vertex> Asa1 = {
        Vertex{L},
        Vertex{V},
        Vertex{M} };

    std::vector<Vertex> Asa2 = {
        Vertex{L},
        Vertex{M},
        Vertex{N} };

    std::vector<Vertex> Arma1 = {
        Vertex{A1},
        Vertex{W},
        Vertex{Z} };

    std::vector<Vertex> Arma2 = {
        Vertex{W},
        Vertex{U},
        Vertex{Z} };

    std::vector<Vertex> Winglet1 = {
        Vertex{R},
        Vertex{M},
        Vertex{T} };

    std::vector<Vertex> Winglet2 = {
        Vertex{R},
        Vertex{S},
        Vertex{M} };

    // Anti
    std::vector<Vertex> AntiCabine = {
        Vertex{AntiA},
        Vertex{AntiC},
        Vertex{AntiB} };

    std::vector<Vertex> AntiCorpo1 = {
        Vertex{AntiC},
        Vertex{AntiE},
        Vertex{AntiB} };

    std::vector<Vertex> AntiCorpo2 = {
        Vertex{AntiB},
        Vertex{AntiE},
        Vertex{AntiD} };


    std::vector<Vertex> AntiCorpo3 = {
        Vertex{AntiE},
        Vertex{AntiH},
        Vertex{AntiF} };

    std::vector<Vertex> AntiCorpo4 = {
        Vertex{AntiF},
        Vertex{AntiH},
        Vertex{AntiG} };

    std::vector<Vertex> AntiCorpo5 = {
        Vertex{AntiI},
        Vertex{AntiK},
        Vertex{AntiG} };

    std::vector<Vertex> AntiCorpo6 = {
        Vertex{AntiI},
        Vertex{AntiG},
        Vertex{AntiJ} };

    std::vector<Vertex> AntiTurbina1 = {
        Vertex{AntiO},
        Vertex{AntiP},
        Vertex{AntiQ} };

    std::vector<Vertex> AntiTurbina2 = {
        Vertex{AntiO},
        Vertex{AntiQ},
        Vertex{AntiJ} };

    std::vector<Vertex> AntiAsa1 = {
        Vertex{AntiL},
        Vertex{AntiN},
        Vertex{AntiM} };

    std::vector<Vertex> AntiAsa2 = {
        Vertex{AntiL},
        Vertex{AntiM},
        Vertex{AntiV} };

    std::vector<Vertex> AntiArma1 = {
        Vertex{AntiA1},
        Vertex{AntiZ},
        Vertex{AntiW} };

    std::vector<Vertex> AntiArma2 = {
        Vertex{AntiW},
        Vertex{AntiZ},
        Vertex{AntiU} };

    std::vector<Vertex> AntiWinglet1 = {
        Vertex{AntiR},
        Vertex{AntiT},
        Vertex{AntiM} };

    std::vector<Vertex> AntiWinglet2 = {
        Vertex{AntiR},
        Vertex{AntiM},
        Vertex{AntiS} };


    std::vector<std::vector<Vertex>> NaveVertices = {

        Cabine,
        Corpo1, Corpo2, Corpo3, Corpo4, Corpo5, Corpo6,
        Turbina1, Turbina2,
        Asa1, Asa2,
        Arma1, Arma2,
        Winglet1, Winglet2,
        AntiCabine,
        AntiCorpo1, AntiCorpo2, AntiCorpo3, AntiCorpo4, AntiCorpo5, AntiCorpo6,
        AntiTurbina1, AntiTurbina2,
        AntiAsa1, AntiAsa2,
        AntiArma1, AntiArma2,
        AntiWinglet1, AntiWinglet2,

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

