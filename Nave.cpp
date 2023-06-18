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
    this->life = 5;
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

