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
    this->ajustaEscalaDaNave(glm::vec3{ 0.05f, 0.05f, 0.05f });
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
    glm::vec4 A{  0.0f,  1.00f,  0.0f, 1.0f };
    glm::vec4 B{ -0.22f, 0.9f,  0.0f, 1.0f };
    glm::vec4 C{  0.0f,  0.9f,  0.0f, 1.0f };
    glm::vec4 D{ -0.35f, 0.7f,  0.0f, 1.0f };
    glm::vec4 E{  0.0f,  0.7f,   0.0f, 1.0f };
    glm::vec4 F{ -0.35f,  -0.8f,   0.0f, 1.0f };
    glm::vec4 G{ 0.0f, -0.8f,  0.0f, 1.0f };
    glm::vec4 H{  -0.08f, -1.0f,  0.0f, 1.0f };
    glm::vec4 I{ -0.12f, -0.7f,  0.0f, 1.0f };
    glm::vec4 J{ -0.4f,-0.7f,  0.0f, 1.0f };
    glm::vec4 K{ -0.45f,  -1.0f,  0.0f, 1.0f };
    glm::vec4 L{ -0.35f, 0.25f,  0.0f, 1.0f };
    glm::vec4 M{ -0.6f, 0.0f,  0.0f, 1.0f };
    glm::vec4 N{ -0.35f, 0.0f,  0.0f, 1.0f };
    glm::vec4 O{ -1.9f,-0.4f,  0.0f, 1.0f };
    glm::vec4 P{ -0.35f, -0.56f,   0.0f, 1.0f };
    glm::vec4 Q{ -2.0f, -0.6f,   0.0f, 1.0f };
    glm::vec4 R{ -1.18f, -0.19f,  0.0f, 1.0f };
    glm::vec4 S{ -1.15f, 0.05f,  0.0f, 1.0f };
    glm::vec4 T{ -1.02f, -0.14f,  0.0f, 1.0f };
    glm::vec4 U{ -1.04f, 0.05f,  0.0f, 1.0f };
    glm::vec4 V{ -1.18f, -0.55f,  0.0f, 1.0f };
    glm::vec4 W{ -1.18f,  -0.68f,  0.0f, 1.0f };
    glm::vec4 Z{ -1.02f,  -0.68f,  0.0f, 1.0f };
    glm::vec4 A1{ -1.02f, -0.57f,  0.0f, 1.0f };
    glm::vec4 AntiA{ 0.0f,  1.00f,  0.0f, 1.0f };
    glm::vec4 AntiB{ 0.22f, 0.9f,  0.0f, 1.0f };
    glm::vec4 AntiC{ 0.0f,  0.9f,  0.0f, 1.0f };
    glm::vec4 AntiD{ 0.35f, 0.7f,  0.0f, 1.0f };
    glm::vec4 AntiE{ 0.0f,  0.7f,   0.0f, 1.0f };
    glm::vec4 AntiF{ 0.35f,  -0.8f,   0.0f, 1.0f };
    glm::vec4 AntiG{ 0.0f, -0.8f,  0.0f, 1.0f };
    glm::vec4 AntiH{ 0.08f, -1.0f,  0.0f, 1.0f };
    glm::vec4 AntiI{ 0.12f, -0.7f,  0.0f, 1.0f };
    glm::vec4 AntiJ{ 0.4f,-0.7f,  0.0f, 1.0f };
    glm::vec4 AntiK{ 0.45f,  -1.0f,  0.0f, 1.0f };
    glm::vec4 AntiL{ 0.35f, 0.25f,  0.0f, 1.0f };
    glm::vec4 AntiM{ 0.6f, 0.0f,  0.0f, 1.0f };
    glm::vec4 AntiN{ 0.35f, 0.0f,  0.0f, 1.0f };
    glm::vec4 AntiO{ 1.9f,-0.4f,  0.0f, 1.0f };
    glm::vec4 AntiP{ 0.35f, -0.56f,   0.0f, 1.0f };
    glm::vec4 AntiQ{ 2.0f, -0.6f,   0.0f, 1.0f };
    glm::vec4 AntiR{ 1.18f, -0.19f,  0.0f, 1.0f };
    glm::vec4 AntiS{ 1.15f, 0.05f,  0.0f, 1.0f };
    glm::vec4 AntiT{ 1.02f, -0.14f,  0.0f, 1.0f };
    glm::vec4 AntiU{ 1.04f, 0.05f,  0.0f, 1.0f };
    glm::vec4 AntiV{ 1.18f, -0.55f,  0.0f, 1.0f };
    glm::vec4 AntiW{ 1.18f,  -0.68f,  0.0f, 1.0f };
    glm::vec4 AntiZ{ 1.02f,  -0.68f,  0.0f, 1.0f };
    glm::vec4 AntiA1{ 1.02f, -0.57f,  0.0f, 1.0f };

    // Bouding Box 

    glm::vec4 BoundingBoxA{ -0.08f, -0.05f,  0.0f, 1.0f };
    glm::vec4 BoundingBoxB{ -0.08f,   0.05f,  0.0f, 1.0f };
    glm::vec4 BoundingBoxC{ 0.08f,   0.05f,  0.0f, 1.0f };
    glm::vec4 BoundingBoxD{ 0.08f, -0.05f,  0.0f, 1.0f };

    // Cores
    glm::vec4 Laranja{ 0.98f, 0.64f, 0.34f, 1.0f };
    glm::vec4 Palha{ 0.972f, 0.937f, 0.843f, 1.0f };
    glm::vec4 AzulClaro{ 0.266f, 0.803f, 0.858f, 1.0f };
    glm::vec4 Cinza{ 0.95f, 0.40f, 0.40f, 1.0f };

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

    std::vector<Vertex> Bico = {
        Vertex{A,AzulClaro},
        Vertex{B, AzulClaro},
        Vertex{C, AzulClaro} };

    std::vector<Vertex> Cabine1 = {
        Vertex{C, Palha},
        Vertex{B, Palha},
        Vertex{E, Palha} };

    std::vector<Vertex> Cabine2 = {
        Vertex{B, Palha},
        Vertex{D, Palha},
        Vertex{E, Palha} };

    std::vector<Vertex> Corpo1 = {
        Vertex{E, Palha},
        Vertex{D, Palha},
        Vertex{G, Palha} };

    std::vector<Vertex> Corpo2 = {
        Vertex{G, Palha},
        Vertex{D, Palha},
        Vertex{F, Palha} };

    std::vector<Vertex> Motor1 = {
        Vertex{H, Laranja},
        Vertex{I, Laranja},
        Vertex{J, Laranja} };

    std::vector<Vertex> Motor2 = {
        Vertex{H, Laranja},
        Vertex{J, Laranja},
        Vertex{K, Laranja} };

    std::vector<Vertex> Asa1 = {
        Vertex{L, AzulClaro},
        Vertex{M, AzulClaro},
        Vertex{N, AzulClaro} };

    std::vector<Vertex> Asa2 = {
        Vertex{N, AzulClaro},
        Vertex{M, AzulClaro},
        Vertex{P, AzulClaro} };

    std::vector<Vertex> Asa3 = {
        Vertex{M, AzulClaro},
        Vertex{O, AzulClaro},
        Vertex{P, AzulClaro} };

    std::vector<Vertex> Asa4 = {
        Vertex{O, Laranja},
        Vertex{Q, Laranja},
        Vertex{P, Laranja} };

    std::vector<Vertex> Arma1 = {
        Vertex{U, Cinza},
        Vertex{S, Cinza},
        Vertex{T, Cinza} };

    std::vector<Vertex> Arma2 = {
        Vertex{S, Cinza},
        Vertex{R, Cinza},
        Vertex{T, Cinza} };

    std::vector<Vertex> Arma3 = {
        Vertex{A1, Cinza},
        Vertex{V, Cinza},
        Vertex{Z, Cinza} };

    std::vector<Vertex> Arma4 = {
        Vertex{V, Cinza},
        Vertex{W, Cinza},
        Vertex{Z, Cinza} };

    // Anti
    std::vector<Vertex> AntiBico = {
    Vertex{AntiA, AzulClaro},
    Vertex{AntiC, AzulClaro},
    Vertex{AntiB, AzulClaro} };

    std::vector<Vertex> AntiCabine1 = {
        Vertex{AntiC, Palha},
        Vertex{AntiE, Palha},
        Vertex{AntiB, Palha} };

    std::vector<Vertex> AntiCabine2 = {
        Vertex{AntiB, Palha},
        Vertex{AntiE, Palha},
        Vertex{AntiD, Palha} };

    std::vector<Vertex> AntiCorpo1 = {
        Vertex{AntiE, Palha},
        Vertex{AntiG, Palha},
        Vertex{AntiD, Palha} };

    std::vector<Vertex> AntiCorpo2 = {
        Vertex{AntiG, Palha},
        Vertex{AntiF, Palha},
        Vertex{AntiD, Palha} };

    std::vector<Vertex> AntiMotor1 = {
        Vertex{AntiH, Laranja},
        Vertex{AntiJ, Laranja},
        Vertex{AntiI, Laranja} };

    std::vector<Vertex> AntiMotor2 = {
        Vertex{AntiH, Laranja},
        Vertex{AntiK, Laranja},
        Vertex{AntiJ, Laranja} };

    std::vector<Vertex> AntiAsa1 = {
        Vertex{AntiL, AzulClaro},
        Vertex{AntiN, AzulClaro},
        Vertex{AntiM, AzulClaro} };

    std::vector<Vertex> AntiAsa2 = {
        Vertex{AntiN, AzulClaro},
        Vertex{AntiP, AzulClaro},
        Vertex{AntiM, AzulClaro} };

    std::vector<Vertex> AntiAsa3 = {
        Vertex{AntiM, AzulClaro},
        Vertex{AntiP, AzulClaro},
        Vertex{AntiO, AzulClaro} };

    std::vector<Vertex> AntiAsa4 = {
        Vertex{AntiO, Laranja},
        Vertex{AntiP, Laranja},
        Vertex{AntiQ, Laranja} };

    std::vector<Vertex> AntiArma1 = {
        Vertex{AntiU, Cinza},
        Vertex{AntiT, Cinza},
        Vertex{AntiS, Cinza} };

    std::vector<Vertex> AntiArma2 = {
        Vertex{AntiS, Cinza},
        Vertex{AntiT, Cinza},
        Vertex{AntiR, Cinza} };

    std::vector<Vertex> AntiArma3 = {
        Vertex{AntiA1, Cinza},
        Vertex{AntiZ, Cinza},
        Vertex{AntiV, Cinza} };

    std::vector<Vertex> AntiArma4 = {
        Vertex{AntiV, Cinza},
        Vertex{AntiZ, Cinza},
        Vertex{AntiW, Cinza} };


    std::vector<std::vector<Vertex>> NaveVertices = {

        Bico,
        Cabine1, Cabine2,
        Corpo1, Corpo2,
        Motor1, Motor2,
        Asa1, Asa2, Asa3, Asa4,
        Arma1, Arma2, Arma3, Arma4,
        AntiBico,
        AntiCabine1, AntiCabine2,
        AntiCorpo1, AntiCorpo2,
        AntiMotor1, AntiMotor2,
        AntiAsa1, AntiAsa2, AntiAsa3, AntiAsa4,
        AntiArma1, AntiArma2, AntiArma3, AntiArma4,

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

        Missil missil(NaveOuAlien, this->modeloDaNave[11][1].Position, this->NaveUp, velocidade);
        this->CanhaoDireitoAtira = false;
        return missil;
    }
    else {
        Missil missil(NaveOuAlien, this->modeloDaNave[26][2].Position, this->NaveUp, velocidade);
        this->CanhaoDireitoAtira = true;
        return missil;
    }
}

