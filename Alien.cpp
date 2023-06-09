#include "Alien.h"
#include "Matrices.h"
#include "Triangle.h"
#include <iostream>

Alien::Alien() {}

Alien::Alien(glm::vec4 Centro) {
    this->Centro = Centro;
    std::vector<std::vector<Vertex>> inimigoModel = this->getAlienModel(); // Modelo Base

    this->modeloDoInimigo = inimigoModel; // Acopla modelo base

    this->CanhaoDireitoAtira = true;
    this->disponível = true;
    this->hasBomb = false;
    this->ataca = false;
    this->life = 50;
    this->recua = false;
    this->vivo = true;
    this->intangivel = false;
    this->tempoDeIntangibilidade = 2.0f;
    this->TempoPiscando = 0.2f;
    this->piscando = false;

    // Encontra o UP do Alien
    this->Up = glm::vec4{ 0.0f, 1.0f, 0.0f, 0.0f };

    // Define o Right do Alien
    this->Right = glm::vec4{1.0f, 0.0f, 0.0f, 0.0f};

    // Altera os vértices da nave
    glm::vec4 Origem = { 0.0f, 0.0f, 0.0f, 1.0f };
    TranslationMatrix(this->modeloDoInimigo, Origem, this->Up ,this->Centro);
}


void Alien::ajustaEscalaDoAlien(glm::vec3 FatorDeEscala) {
    ScaleMatrix(this->modeloDoInimigo, FatorDeEscala, this->Centro); // Escala o triangulo
    this->escala *= FatorDeEscala;
}

void Alien::transladaOAlien(glm::vec3 fatorDeTranslacao) {
    TranslationMatrix(this->modeloDoInimigo, this->Centro, this->Up , fatorDeTranslacao);
}

void Alien::rotacionaOAlien(float graus) {
    RotationMatrix(this->modeloDoInimigo, graus, this->Centro, this->Up, this->Right); // Rotaciona o triangulo em relação ao centro do OBJ
}

void Alien::pisca(float tempoDePiscada, float DeltaTime) {
    if (this->piscando) { // Se ele está no estado apagado durante a piscada
        this->TempoPiscando -= DeltaTime; // Diminui o tempo de piscada
    }
    else {
        this->TempoPiscando += DeltaTime; // Aumenta o tempo de piscada
    }

    if (this->TempoPiscando <= 0.0f) { // Se o tempo de piscada chegar a 0
        this->piscando = false;				 // Passa para o estado "aceso" da piscada
    }

    if (this->TempoPiscando >= tempoDePiscada) { // Se o tempo de piscada chegar ao tempo determinado de piscada
        this->piscando = true; // Passa para o estado apagado da piscada
    }
}

void Alien::MoveAlienLateralmente(bool& AlienMoveLeft, float velocidadeInimigos, float DeltaTime) {
    glm::vec3 fatorDeTranslacaoLateral;
    if (AlienMoveLeft) {
        fatorDeTranslacaoLateral = glm::vec3{ -1.0f * velocidadeInimigos * DeltaTime, 0.0f , 0.0f }; // Move para a esquerda
    } else {
        fatorDeTranslacaoLateral = glm::vec3{ 1.0f * velocidadeInimigos * DeltaTime, 0.0f , 0.0f }; // Move para a direita
    }

    this->transladaOAlien(fatorDeTranslacaoLateral); // Translada o Alien

    if (this->hasBomb && !this->bomba.Dropada) { // Se o Alien tiver bomba e a bomba não estiver dropada
        this->bomba.translada(fatorDeTranslacaoLateral); // Move a bomba
    }

    if (this->Centro.x < -1.8f) { // Se algum alien alcançar a parede esquerda, move pra direita
        AlienMoveLeft = false;
    } else if (this->Centro.x > 1.8f) {// Se algum alien alcançar a parede direita, move pra esquerda
        AlienMoveLeft =  true;
    }
}

void Alien::AtacaEmEsquadrao(float localDeSobrevooDosAliens, glm::vec3 fatorDeTranslacaoEsquadrao, glm::vec3 fatorDeTranslacaoEsquadraoSobe, float alturaDoPlaneta) {
    if (this->Centro.y > localDeSobrevooDosAliens && this->Centro.z < 0.7f) { // Sobe Z
        this->transladaOAlien(fatorDeTranslacaoEsquadraoSobe);
        if (this->hasBomb && !this->bomba.Dropada) { // Se for o alien com bomba
            this->bomba.translada(fatorDeTranslacaoEsquadraoSobe); // Sobe a bomba
        }
    }

    if (this->Centro.y < localDeSobrevooDosAliens && this->Centro.z > 0.0f) { // Desce Z
        this->transladaOAlien(-1.0f * fatorDeTranslacaoEsquadraoSobe);
        if (this->hasBomb && !this->bomba.Dropada) { // Se for o Alien com bomba
            this->bomba.translada(-1.0f * fatorDeTranslacaoEsquadraoSobe); // Desce a bomba
        }
    }

    this->transladaOAlien(fatorDeTranslacaoEsquadrao); // Anda ele rumo ao planeta				

    if (this->Centro.y < alturaDoPlaneta) { // Se o Alien chegar ao planeta
        this->recua = true; // Manda recuar
        this->ataca = false;
        if (this->hasBomb) { // Se for o Alien que carrega a bomba
            this->bomba.Dropada = true; // Dropa a bomba
        }
    }
}

void Alien::RecuaEmEsquadrao(glm::vec3 fatorDeTranslacaoEsquadrao, glm::vec3 fatorDeTranslacaoEsquadraoSobe) {
    if (this->Centro.y > 0.5f && this->Centro.y < this->yOriginal && this->Centro.z < 1.0f) { // Sobe Z
        this->transladaOAlien(fatorDeTranslacaoEsquadraoSobe);
    }

    if (this->Centro.y >= this->yOriginal && this->Centro.z > -0.1f) { // Desce Z
        this->transladaOAlien(-1.0f * fatorDeTranslacaoEsquadraoSobe);
    }

    if (this->Centro.z < 0.0f) { // Se a nave tiver descido demais quando foi retornar
        this->transladaOAlien(glm::vec3{ 0.0f, 0.0f, 0.0f - this->Centro.z }); // conserta sua posição
    }

    if (this->Centro.y < this->yOriginal) {
        this->transladaOAlien(-1.0f * fatorDeTranslacaoEsquadrao); // Retorna ele para a posição original
    }

    if (this->Centro.y >= this->yOriginal && this->Centro.z == 0.0f) {
        this->recua = false;
        this->transladaOAlien(glm::vec3{ 0.0f, this->yOriginal - this->Centro.y, 0.0f - this->Centro.z });
    }
}

void Alien::AtualizaEstadoDaBomba(float DeltaTime, glm::vec3 fatorDeTranslacaoEsquadrao, float intensidadePiscadaBombaDropada, float velocidadeDePiscadaBombaDropada) {
    // Se não estiver dropada, anda com a bomba
    if (!this->bomba.Dropada) {
        this->bomba.translada(fatorDeTranslacaoEsquadrao);
    }
    else { // Se estiver Dropada, Pisca a bomba
        if (this->bomba.Centro.z != 0.0f) {
            this->bomba.ajustaEixoZ();
        }
        this->bomba.pisca(DeltaTime, intensidadePiscadaBombaDropada, velocidadeDePiscadaBombaDropada);
    }
    // Diminui o tempo do countdown da bomba depois que ela for dropada
    if (this->bomba.Dropada) {
        this->bomba.CountDown -= DeltaTime;
    }
}

void Alien::AtualizaTempoDeTangibilidade(float DeltaTime, float tempoDeIntangibilidadeAlien) {
    this->tempoDeIntangibilidade -= 1.0f * DeltaTime;
    if (this->tempoDeIntangibilidade <= 0.0f) {
        this->tempoDeIntangibilidade = tempoDeIntangibilidadeAlien;
        this->intangivel = false;
    }
}

std::vector<std::vector<Vertex>> Alien::getAlienModel() {

    

    //Modela o Alien
    glm::vec4 A = glm::vec4{ -0.04f, +0.05f,  +0.0f, 1.0f };
    glm::vec4 B = glm::vec4{ +0.04f, +0.05f, +0.0f, 1.0f };
    glm::vec4 C = glm::vec4{ +0.04f, -0.01f,  +0.0f, 1.0f };
    glm::vec4 D = glm::vec4{ -0.04f, -0.01f,  +0.0f, 1.0f };
    glm::vec4 E = glm::vec4{ -0.04f, +0.01f, +0.0f, 1.0f };
    glm::vec4 F = glm::vec4{ -0.11f, +0.01f, +0.0f, 1.0f };
    glm::vec4 G = glm::vec4{ -0.11f, +0.05f, +0.0f, 1.0f };
    glm::vec4 H = glm::vec4{ -0.08f, +0.01f, +0.0f, 1.0f };
    glm::vec4 I = glm::vec4{ -0.08f, -0.03f, +0.0f, 1.0f };
    glm::vec4 J = glm::vec4{ -0.11f, -0.03f, +0.0f, 1.0f };
    glm::vec4 K = glm::vec4{ -0.1f,  -0.03f, +0.0f, 1.0f };
    glm::vec4 L = glm::vec4{ -0.1f,  -0.05f, +0.0f, 1.0f };
    glm::vec4 M = glm::vec4{ -0.11f, -0.05f, +0.0f, 1.0f };
    glm::vec4 N = glm::vec4{ +0.11f, +0.05f, +0.0f, 1.0f };
    glm::vec4 O = glm::vec4{ +0.11f, +0.01f, +0.0f, 1.0f };
    glm::vec4 P = glm::vec4{ +0.04f, +0.01f, +0.0f, 1.0f };
    glm::vec4 Q = glm::vec4{ +0.11f, -0.03f, +0.0f, 1.0f };
    glm::vec4 R = glm::vec4{ +0.08f, -0.03f, +0.0f, 1.0f };
    glm::vec4 S = glm::vec4{ +0.08f, +0.01f, +0.0f, 1.0f };
    glm::vec4 T = glm::vec4{ +0.11f, -0.05f, +0.0f, 1.0f };
    glm::vec4 U = glm::vec4{ +0.1f,  -0.05f, +0.0f, 1.0f };
    glm::vec4 V = glm::vec4{ +0.1f,  -0.03f, +0.0f, 1.0f };
    glm::vec4 X = glm::vec4{ -0.03f, +0.06f, +0.0f, 1.0f };
    glm::vec4 W = glm::vec4{ -0.01f, +0.06f, +0.0f, 1.0f };
    glm::vec4 Y = glm::vec4{ -0.02f, +0.05f, +0.0f, 1.0f };
    glm::vec4 Z = glm::vec4{ +0.01f, +0.06f, +0.0f, 1.0f };
    glm::vec4 A1 = glm::vec4{ +0.03f, +0.06f, +0.0f, 1.0f };
    glm::vec4 B1 = glm::vec4{ +0.02f, +0.05f, +0.0f, 1.0f };


    // Bouding Box
    glm::vec4 BoundingBoxA {- 0.11f,  - 0.05f,  0.0f, 1.0f };
    glm::vec4 BoundingBoxB {- 0.11f,    0.06f,  0.0f, 1.0f };
    glm::vec4 BoundingBoxC {  0.11f,    0.06f,  0.0f, 1.0f };
    glm::vec4 BoundingBoxD {  0.11f,  - 0.05f,  0.0f, 1.0f };

    //Cores
    glm::vec4 Vermelho{ 1.0f, 0.0f, 0.0f, 1.0f };
    glm::vec4 Verde{ 0.0f, 1.0f, 0.0f, 1.0f };
    glm::vec4 Azul{ 0.0f, 0.0f, 1.0f, 1.0f };
    glm::vec4 AntiVermelho{ 0.0f, 1.0f, 1.0f, 1.0f };
    glm::vec4 AntiVerde{ 1.0f, 0.0f, 1.0f, 1.0f };
    glm::vec4 AntiAzul{ 1.0f, 1.0f, 0.0f, 1.0f };

    glm::vec4 CorCorpo{ 0.73f, 0.54f, 0.75f, 1.0f };
    glm::vec4 CorBracoEsquerdo{ 0.42f, 0.20f, 0.58f, 1.0f };
    glm::vec4 CorMaoEsquerda{ 0.41f, 0.05f, 0.69f, 1.0f };
    glm::vec4 CorCanhaoEsquerdo{ 1.0f, 0.0f, 0.0f, 1.0f };
    glm::vec4 CorBracoDireito{ 0.42f, 0.20f, 0.58f, 1.0f };
    glm::vec4 CorMaoDireita{ 0.41f, 0.05f, 0.69f, 1.0f };
    glm::vec4 CorCanhaoDireito{ 1.0f, 0.0f, 0.0f, 1.0f };
    glm::vec4 CorMotorEsquerdo{ 1.0f, 0.0f, 0.0f, 1.0f };
    glm::vec4 CorMotorDireito{ 1.0f, 0.0f, 0.0f, 1.0f };
    glm::vec4 CorBoundingBox{ 0.0f, 0.0f, 0.0f, 1.0f };

    std::vector<Vertex> Corpo1 = {
        Vertex{A, CorCorpo},
        Vertex{D, CorCorpo},
        Vertex{C, CorCorpo}
    };

    std::vector<Vertex> Corpo2 = {
        Vertex{A, CorCorpo},
        Vertex{C, CorCorpo},
        Vertex{B, CorCorpo}
    };

    std::vector<Vertex> BracoEsquerdo1 = {
        Vertex{A, CorBracoEsquerdo},
        Vertex{F, CorBracoEsquerdo},
        Vertex{E, CorBracoEsquerdo}
    };

    std::vector<Vertex> BracoEsquerdo2 = {
        Vertex{A, CorBracoEsquerdo},
        Vertex{G, CorBracoEsquerdo},
        Vertex{F, CorBracoEsquerdo}
    };

    std::vector<Vertex> MaoEsquerda1 = {
        Vertex{H, CorMaoEsquerda},
        Vertex{J, CorMaoEsquerda},
        Vertex{I, CorMaoEsquerda}
    };

    std::vector<Vertex> MaoEsquerda2 = {
        Vertex{H, CorMaoEsquerda},
        Vertex{F, CorMaoEsquerda},
        Vertex{J, CorMaoEsquerda}
    };

    std::vector<Vertex> CanhaoEsquerdo1 = {
        Vertex{K, CorCanhaoEsquerdo},
        Vertex{M, CorCanhaoEsquerdo},
        Vertex{L, CorCanhaoEsquerdo}
    };

    std::vector<Vertex> CanhaoEsquerdo2 = {
        Vertex{K, CorCanhaoEsquerdo},
        Vertex{J, CorCanhaoEsquerdo},
        Vertex{M, CorCanhaoEsquerdo}
    };

    std::vector<Vertex> BracoDireito1 = {
        Vertex{B, CorBracoDireito},
        Vertex{P, CorBracoDireito},
        Vertex{O, CorBracoDireito}
    };

    std::vector<Vertex> BracoDireito2 = {
        Vertex{B, CorBracoDireito},
        Vertex{O, CorBracoDireito},
        Vertex{N, CorBracoDireito}
    };

    std::vector<Vertex> MaoDireita1 = {
        Vertex{O, CorMaoDireita},
        Vertex{R, CorMaoDireita},
        Vertex{Q, CorMaoDireita}
    };

    std::vector<Vertex> MaoDireita2 = {
        Vertex{O, CorMaoDireita},
        Vertex{S, CorMaoDireita},
        Vertex{R, CorMaoDireita}
    };

    std::vector<Vertex> CanhaoDireito1 = {
        Vertex{Q, CorCanhaoDireito},
        Vertex{U, CorCanhaoDireito},
        Vertex{T, CorCanhaoDireito}
    };

    std::vector<Vertex> CanhaoDireito2 = {
        Vertex{Q, CorCanhaoDireito},
        Vertex{V, CorCanhaoDireito},
        Vertex{U, CorCanhaoDireito}
    };

    std::vector<Vertex> MotorEsquerdo = {
        Vertex{X, CorMotorEsquerdo},
        Vertex{Y, CorMotorEsquerdo},
        Vertex{W, CorMotorEsquerdo}
    };

    std::vector<Vertex> MotorDireito = {
        Vertex{Z, CorMotorDireito},
        Vertex{B1, CorMotorDireito},
        Vertex{A1, CorMotorDireito}
    };

    std::vector<Vertex> BoudingBox1 = {
        Vertex{BoundingBoxA, CorBoundingBox},
        Vertex{BoundingBoxC, CorBoundingBox},
        Vertex{BoundingBoxB, CorBoundingBox}
    };

    std::vector<Vertex> BoudingBox2 = {
        Vertex{BoundingBoxA, CorBoundingBox},
        Vertex{BoundingBoxD, CorBoundingBox},
        Vertex{BoundingBoxC, CorBoundingBox}
    };


    std::vector<std::vector<Vertex>> alienVertices = {
        // Corpo
        Corpo1, Corpo2,

        // Braco Esquerdo
        BracoEsquerdo1, BracoEsquerdo2,
        // Mao Esquerda
        MaoEsquerda1, MaoEsquerda2,
        // CanhaoEsquerdo
        CanhaoEsquerdo1, CanhaoEsquerdo2,
        // Motor Esquerdo
        MotorEsquerdo,

        // Braco Direito
        BracoDireito1, BracoDireito2,
        // Mao Direito
        MaoDireita1, MaoDireita2,
        // Canhao Direito
        CanhaoDireito1, CanhaoDireito2,
        // Motor Direito
        MotorDireito,

        // Bouding Box
        BoudingBox1,
        // Bouding Box
        BoudingBox2
    };
    return alienVertices;
}

Missil Alien::Atira(float velocidade){

    bool NaveOuAlien = false;

    if (this->CanhaoDireitoAtira) {

        Missil missil(NaveOuAlien, this->modeloDoInimigo[7][2].Position, -1.0f * this->Up, velocidade);
        this->CanhaoDireitoAtira = false;
        return missil;
    }
    else {
        Missil missil(NaveOuAlien, this->modeloDoInimigo[14][1].Position, -1.0f * this->Up, velocidade);
        this->CanhaoDireitoAtira = true;
        return missil;
    }
}

void Alien::CarregaBomba(float CountDown) {
    this->hasBomb = true;
    this->ataca = true;
    this->bomba = Bomba(this->Centro, CountDown);
}

