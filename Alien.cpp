#include "Alien.h"
#include "Matrices.h"
#include "Triangle.h"
#include <iostream>

Alien::Alien() {}

Alien::Alien(glm::vec4 Centro) {
    this->Centro = Centro;

    this->Vertices = getAlienVertices(); // Modelo Base // Acopla modelo base
    this->Indices = getAlienIndices(0); // Modelo Base // Acopla modelo base

    this->CanhaoDireitoAtira = true;
    this->disponível = true;
    this->hasBomb = false;
    this->ataca = false;
    this->life = 10;
    this->recua = false;
    this->vivo = true;
    this->intangivel = false;
    this->tempoDeIntangibilidade = 2.0f;
    this->TempoPiscando = 0.2f;
    this->piscando = false;
    this->skin = 0;
    this->sobeAsa = true;
    this->TempoParaTrocarSkin = 0.0f;

    // Encontra o UP do Alien
    this->Up = glm::vec4{ 0.0f, 1.0f, 0.0f, 0.0f };

    // Define o Right do Alien
    this->Right = glm::vec4{1.0f, 0.0f, 0.0f, 0.0f};

    // Altera os vértices da nave
    glm::vec4 Origem = { 0.0f, 0.0f, 0.0f, 1.0f };
    TranslationMatrix(this->Vertices, Origem, this->Up ,this->Centro);
    this->ajustaEscalaDoAlien(glm::vec3{ 0.13f, 0.13f, 1.0f });

    
}


void Alien::ajustaEscalaDoAlien(glm::vec3 FatorDeEscala) {
    ScaleMatrix(this->Vertices, FatorDeEscala, this->Centro); // Escala o triangulo
    this->escala *= FatorDeEscala;
}

void Alien::transladaOAlien(glm::vec3 fatorDeTranslacao) {
    TranslationMatrix(this->Vertices, this->Centro, this->Up , fatorDeTranslacao);
}

void Alien::rotacionaOAlien(float graus) {
    RotationMatrix(this->Vertices, graus, this->Centro, this->Up, this->Right); // Rotaciona o triangulo em relação ao centro do OBJ
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

void Alien::RecuaEmEsquadrao(glm::vec3 fatorDeTranslacaoEsquadrao, glm::vec3 fatorDeTranslacaoEsquadraoSobe, float localDeSobrevooDosAliens) {
    if (this->Centro.y > localDeSobrevooDosAliens && this->Centro.y < this->yOriginal && this->Centro.z < 1.0f) { // Sobe Z
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

Missil Alien::Atira(float velocidade){

    bool NaveOuAlien = false;

    if (this->CanhaoDireitoAtira) {

        Missil missil(NaveOuAlien, this->Centro, -1.0f * this->Up, velocidade);
        this->CanhaoDireitoAtira = false;
        return missil;
    }
    else {
        Missil missil(NaveOuAlien, this->Centro, -1.0f * this->Up, velocidade);
        this->CanhaoDireitoAtira = true;
        return missil;
    }
}

void Alien::CarregaBomba(float CountDown) {
    this->hasBomb = true;
    this->ataca = true;
    this->bomba = Bomba(this->Centro, CountDown);
}

void Alien::TrocaSkin(float DeltaTime, float velocidadeDoAlien, bool hasPowerUp1, bool hasPowerUp2, bool congela) {
    if (congela) {
        this->TempoParaTrocarSkin = 0.0f;
    }
    this->TempoParaTrocarSkin -= DeltaTime * velocidadeDoAlien * 5;

    // PowerUps
    if (hasPowerUp2) {
        for (auto& vertice : this->Vertices) {
            vertice.Color = glm::vec4{ 0.35f, 0.35f, 0.8f, 1.0f };
        }
    } else if (hasPowerUp1) {
        for (auto& vertice : this->Vertices) {
            vertice.Color = glm::vec4{ 1.0f, 0.0f, 1.0f, 1.0f };
        }
    } else {
        for (auto& vertice : this->Vertices) {
            vertice.Color = glm::vec4{ 0.10f, 0.60f, 0.05f, 1.0f };
        }
    }

    // Bater Asas

    if (this->TempoParaTrocarSkin <= 0) {
        this->TempoParaTrocarSkin = 0.3f;

        if (sobeAsa) {
            glm::vec3 FatorTranslacaoVoo{ 0.0f, -0.015f, 0.0f };
            this->skin++;


            if (this->skin == 0) {
                this->Indices = this->getAlienIndices(0);
            }
            if (this->skin == 1) {
                this->Indices = this->getAlienIndices(1);
            }
            if (this->skin == 2) {
                this->Indices = this->getAlienIndices(2);
            }
            this->transladaOAlien(FatorTranslacaoVoo);


            if (this->skin >= 2) {
                this->sobeAsa = false;
            }
        }
        else {
            glm::vec3 FatorTranslacaoVoo{ 0.0f, 0.015f, 0.0f };
            this->skin--;
            if (this->skin == 0) {
                this->Indices = this->getAlienIndices(0);
            }
            if (this->skin == 1) {
                this->Indices = this->getAlienIndices(1);
            }
            if (this->skin == 2) {
                this->Indices = this->getAlienIndices(2);
            }

            this->transladaOAlien(FatorTranslacaoVoo);

            if (this->skin <= 0) {
                this->sobeAsa = true;
            }
        }
    }
    
}
