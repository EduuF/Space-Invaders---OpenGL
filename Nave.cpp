#include "Nave.h"
#include "Matrices.h"
#include <iostream>

Nave::Nave(glm::vec4 NaveCentro) {
    // Define o centro do obejto como 0,0,0 (Pode ser alterado futuramente)
    this->NaveCentro = NaveCentro;
    modelaANave();

}

void Nave::modelaANave() {

    NaveCentro = this->NaveCentro;

    // Modela os vértices do bounding box do objeto
    // 
    // A = {-1, -1, 0} 
    // B = {-1,  1, 0}
    // C = { 1,  1, 0} 
    // D = { 1, -1, 0}
    //
    this->BoundingBoxA = glm::vec4{ NaveCentro.x -0.08f, NaveCentro.y -0.05f, NaveCentro.z +0.0f, 1.0f };
    this->BoundingBoxB = glm::vec4{ NaveCentro.x -0.08f, NaveCentro.y +0.05f, NaveCentro.z +0.0f, 1.0f };
    this->BoundingBoxC = glm::vec4{ NaveCentro.x +0.08f, NaveCentro.y +0.05f, NaveCentro.z +0.0f, 1.0f };
    this->BoundingBoxD = glm::vec4{ NaveCentro.x +0.08f, NaveCentro.y -0.05f, NaveCentro.z +0.0f, 1.0f };

    // Modela a nave
    glm::vec4 A{ NaveCentro.x -0.04f, NaveCentro.y -0.03f, NaveCentro.z +0.0f, 1.0f };
    glm::vec4 B{ NaveCentro.x +0.0f,  NaveCentro.y +0.05f, NaveCentro.z +0.0f, 1.0f };
    glm::vec4 C{ NaveCentro.x +0.04f, NaveCentro.y -0.03f, NaveCentro.z +0.0f, 1.0f };
    glm::vec4 D{ NaveCentro.x -0.08f, NaveCentro.y -0.03f, NaveCentro.z +0.0f, 1.0f };
    glm::vec4 E{ NaveCentro.x -0.06f, NaveCentro.y +0.0f,  NaveCentro.z +0.0f, 1.0f };
    glm::vec4 F{ NaveCentro.x +0.06f, NaveCentro.y +0.0f,  NaveCentro.z +0.0f, 1.0f };
    glm::vec4 G{ NaveCentro.x +0.08f, NaveCentro.y -0.03f, NaveCentro.z +0.0f, 1.0f };
    glm::vec4 H{ NaveCentro.x -0.03f, NaveCentro.y -0.05f, NaveCentro.z +0.0f, 1.0f };
    glm::vec4 I{ NaveCentro.x -0.05f, NaveCentro.y -0.05f, NaveCentro.z +0.0f, 1.0f };
    glm::vec4 J{ NaveCentro.x +0.05f, NaveCentro.y -0.05f, NaveCentro.z +0.0f, 1.0f };
    glm::vec4 K{ NaveCentro.x +0.03f, NaveCentro.y -0.05f, NaveCentro.z +0.0f, 1.0f };

    std::array<glm::vec4, 3> Corpo = { A, B, C };
    std::array<glm::vec4, 3> CanhaoEsquerdo = { A, D, E };
    std::array<glm::vec4, 3> CanhaoDireito = { C, F, G };
    std::array<glm::vec4, 3> MotorEsquerdo = { A, H, I };
    std::array<glm::vec4, 3> MotorDireito = { C, J, K };

    std::array<std::array<glm::vec4, 3>, 5> NaveVertices = {

        // Corpo
        Corpo,
        // Asa esquerda
        CanhaoEsquerdo,
        // Asa direita
        CanhaoDireito,
        // Entrada de ar
        MotorEsquerdo,
        // FarolEsqcuerdo
        MotorDireito

    };

    this->modeloDaNave = NaveVertices;
}

void Nave::ajustaEscalaDaNave(glm::vec3 FatorDeEscola) {
    for (auto& parte : modeloDaNave) {
        ScaleMatrix(parte, FatorDeEscola);
    }
}

void Nave::transladaANave(glm::vec3 fatorDeTranslacao) {
    TranslationMatrix(this->NaveCentro, fatorDeTranslacao);
    std::cout << "TESTE" << std::endl;
    std::cout << this->NaveCentro.x << this->NaveCentro.y << std::endl;
    this->modelaANave();
}

void Nave::rotacionaANave(float graus, glm::vec3 eixoDeRotacao) {
    for (auto& parte : modeloDaNave) {
        RotationMatrix(parte, graus, eixoDeRotacao);
    }
}