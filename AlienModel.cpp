#include "Alien.h"

std::vector<std::vector<Vertex>> getAlienModelEstado1() {

    // Bouding Box
    glm::vec4 BoundingBoxA{ -0.11f,  -0.05f,  0.0f, 1.0f };
    glm::vec4 BoundingBoxB{ -0.11f,    0.06f,  0.0f, 1.0f };
    glm::vec4 BoundingBoxC{ 0.11f,    0.06f,  0.0f, 1.0f };
    glm::vec4 BoundingBoxD{ 0.11f,  -0.05f,  0.0f, 1.0f };

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

    //Modela o Alien
    glm::vec4 L = glm::vec4{ -1.2f, -0.4f,  +0.0f, 1.0f };
    glm::vec4 I = glm::vec4{ -1.2f, 0.0f, +0.0f, 1.0f };
    glm::vec4 M = glm::vec4{ -1.0f, 0.0f,  +0.0f, 1.0f };
    glm::vec4 N = glm::vec4{ -1.00f, -0.4f,  +0.0f, 1.0f };

    glm::vec4 J = glm::vec4{ -1.2f, 0.2f, +0.0f, 1.0f };
    glm::vec4 H = glm::vec4{ -0.8f, 0.0f,  +0.0f, 1.0f };
    glm::vec4 K = glm::vec4{ -0.8f, 0.2f,  +0.0f, 1.0f };

    glm::vec4 O = glm::vec4{ -1.0f, 0.2f, +0.0f, 1.0f };
    glm::vec4 Q = glm::vec4{ -0.8f, 0.4f,  +0.0f, 1.0f };
    glm::vec4 P = glm::vec4{ -1.0f, 0.4f,  +0.0f, 1.0f };

    glm::vec4 E = glm::vec4{ -0.8f, -0.4f,  +0.0f, 1.0f };
    glm::vec4 F = glm::vec4{ -0.8f, 0.6f, +0.0f, 1.0f };
    glm::vec4 D = glm::vec4{ -0.6f, -0.4f,  +0.0f, 1.0f };
    glm::vec4 G = glm::vec4{ -0.6f, 0.6f,  +0.0f, 1.0f };

    glm::vec4 V = glm::vec4{ -0.8f, 0.8f,  +0.0f, 1.0f };
    glm::vec4 Z = glm::vec4{ -0.8f, 1.0f, +0.0f, 1.0f };
    glm::vec4 W = glm::vec4{ -0.6f, 1.0f,  +0.0f, 1.0f };
    glm::vec4 S = glm::vec4{ -0.6f, 0.8f,  +0.0f, 1.0f };

    glm::vec4 B = glm::vec4{ -0.6f, -0.6f,  +0.0f, 1.0f };
    glm::vec4 C = glm::vec4{ -0.2f, -0.4f,  +0.0f, 1.0f };
    glm::vec4 A = glm::vec4{ -0.2f, -0.6f,  +0.0f, 1.0f };

    glm::vec4 H1 = glm::vec4{ -0.6f, -0.2f,  +0.0f, 1.0f };
    glm::vec4 F1 = glm::vec4{ -0.6f, 0.2f, +0.0f, 1.0f };
    glm::vec4 G1 = glm::vec4{ -0.4f, 0.2f,  +0.0f, 1.0f };
    glm::vec4 D1 = glm::vec4{ -0.4f, -0.2f,  +0.0f, 1.0f };

    glm::vec4 R = glm::vec4{ -0.6f, 0.4f, +0.0f, 1.0f };
    glm::vec4 T = glm::vec4{ -0.4f, 0.8f,  +0.0f, 1.0f };
    glm::vec4 U = glm::vec4{ -0.4f, 0.4f,  +0.0f, 1.0f };

    glm::vec4 A1 = glm::vec4{ -0.4f, 0.6f,  +0.0f, 1.0f };
    glm::vec4 B1 = glm::vec4{ 0.0f, 0.6f,  +0.0f, 1.0f };
    glm::vec4 E1 = glm::vec4{ 0.0f, -0.2f,  +0.0f, 1.0f };

    glm::vec4 LInverso = glm::vec4{ 1.2f, -0.4f,  +0.0f, 1.0f };
    glm::vec4 IInverso = glm::vec4{ 1.2f, 0.0f, +0.0f, 1.0f };
    glm::vec4 MInverso = glm::vec4{ 1.0f, 0.0f,  +0.0f, 1.0f };
    glm::vec4 NInverso = glm::vec4{ 1.00f, -0.4f,  +0.0f, 1.0f };

    glm::vec4 JInverso = glm::vec4{ 1.2f, 0.2f, +0.0f, 1.0f };
    glm::vec4 HInverso = glm::vec4{ 0.8f, 0.0f,  +0.0f, 1.0f };
    glm::vec4 KInverso = glm::vec4{ 0.8f, 0.2f,  +0.0f, 1.0f };

    glm::vec4 OInverso = glm::vec4{ 1.0f, 0.2f, +0.0f, 1.0f };
    glm::vec4 QInverso = glm::vec4{ 0.8f, 0.4f,  +0.0f, 1.0f };
    glm::vec4 PInverso = glm::vec4{ 1.0f, 0.4f,  +0.0f, 1.0f };

    glm::vec4 EInverso = glm::vec4{ 0.8f, -0.4f,  +0.0f, 1.0f };
    glm::vec4 FInverso = glm::vec4{ 0.8f, 0.6f, +0.0f, 1.0f };
    glm::vec4 DInverso = glm::vec4{ 0.6f, -0.4f,  +0.0f, 1.0f };
    glm::vec4 GInverso = glm::vec4{ 0.6f, 0.6f,  +0.0f, 1.0f };

    glm::vec4 VInverso = glm::vec4{ 0.8f, 0.8f,  +0.0f, 1.0f };
    glm::vec4 ZInverso = glm::vec4{ 0.8f, 1.0f, +0.0f, 1.0f };
    glm::vec4 WInverso = glm::vec4{ 0.6f, 1.0f,  +0.0f, 1.0f };
    glm::vec4 SInverso = glm::vec4{ 0.6f, 0.8f,  +0.0f, 1.0f };

    glm::vec4 BInverso = glm::vec4{ 0.6f, -0.6f,  +0.0f, 1.0f };
    glm::vec4 CInverso = glm::vec4{ 0.2f, -0.4f,  +0.0f, 1.0f };
    glm::vec4 AInverso = glm::vec4{ 0.2f, -0.6f,  +0.0f, 1.0f };

    glm::vec4 H1Inverso = glm::vec4{ 0.6f, -0.2f,  +0.0f, 1.0f };
    glm::vec4 F1Inverso = glm::vec4{ 0.6f, 0.2f, +0.0f, 1.0f };
    glm::vec4 G1Inverso = glm::vec4{ 0.4f, 0.2f,  +0.0f, 1.0f };
    glm::vec4 D1Inverso = glm::vec4{ 0.4f, -0.2f,  +0.0f, 1.0f };

    glm::vec4 RInverso = glm::vec4{ 0.6f, 0.4f, +0.0f, 1.0f };
    glm::vec4 TInverso = glm::vec4{ 0.4f, 0.8f,  +0.0f, 1.0f };
    glm::vec4 UInverso = glm::vec4{ 0.4f, 0.4f,  +0.0f, 1.0f };

    glm::vec4 A1Inverso = glm::vec4{ 0.4f, 0.6f,  +0.0f, 1.0f };
    glm::vec4 B1Inverso = glm::vec4{ 0.0f, 0.6f,  +0.0f, 1.0f };
    glm::vec4 E1Inverso = glm::vec4{ 0.0f, -0.2f,  +0.0f, 1.0f };

    std::vector<Vertex> Inverso1 = {
        Vertex{D1Inverso, CorCorpo},
        Vertex{A1Inverso, CorCorpo},
        Vertex{B1Inverso, CorCorpo}
    };

    std::vector<Vertex> Inverso2 = {
        Vertex{D1Inverso, CorCorpo},
        Vertex{B1Inverso, CorCorpo},
        Vertex{E1Inverso, CorCorpo}
    };

    std::vector<Vertex> Inverso3 = {
        Vertex{RInverso, CorCorpo},
        Vertex{SInverso, CorCorpo},
        Vertex{TInverso, CorCorpo}
    };

    std::vector<Vertex> Inverso4 = {
        Vertex{RInverso, CorCorpo},
        Vertex{TInverso, CorCorpo},
        Vertex{UInverso, CorCorpo}
    };

    std::vector<Vertex> Inverso5 = {
        Vertex{H1Inverso, CorCorpo},
        Vertex{F1Inverso, CorCorpo},
        Vertex{G1Inverso, CorCorpo}
    };

    std::vector<Vertex> Inverso6 = {
        Vertex{H1Inverso, CorCorpo},
        Vertex{G1Inverso, CorCorpo},
        Vertex{D1Inverso, CorCorpo}
    };

    std::vector<Vertex> Inverso7 = {
        Vertex{BInverso, CorCorpo},
        Vertex{DInverso, CorCorpo},
        Vertex{CInverso, CorCorpo}
    };

    std::vector<Vertex> Inverso8 = {
        Vertex{BInverso, CorCorpo},
        Vertex{CInverso, CorCorpo},
        Vertex{AInverso, CorCorpo}
    };

    std::vector<Vertex> Inverso9 = {
        Vertex{VInverso, CorCorpo},
        Vertex{ZInverso, CorCorpo},
        Vertex{WInverso, CorCorpo}
    };

    std::vector<Vertex> Inverso10 = {
        Vertex{VInverso, CorCorpo},
        Vertex{WInverso, CorCorpo},
        Vertex{SInverso, CorCorpo}
    };

    std::vector<Vertex> Inverso11 = {
        Vertex{EInverso, CorCorpo},
        Vertex{FInverso, CorCorpo},
        Vertex{DInverso, CorCorpo}
    };

    std::vector<Vertex> Inverso12 = {
        Vertex{DInverso, CorCorpo},
        Vertex{FInverso, CorCorpo},
        Vertex{GInverso, CorCorpo}
    };

    std::vector<Vertex> Inverso13 = {
        Vertex{OInverso, CorCorpo},
        Vertex{QInverso, CorCorpo},
        Vertex{KInverso, CorCorpo}
    };

    std::vector<Vertex> Inverso14 = {
        Vertex{OInverso, CorCorpo},
        Vertex{PInverso, CorCorpo},
        Vertex{QInverso, CorCorpo}
    };

    std::vector<Vertex> Inverso15 = {
        Vertex{IInverso, CorCorpo},
        Vertex{JInverso, CorCorpo},
        Vertex{HInverso, CorCorpo}
    };

    std::vector<Vertex> Inverso16 = {
        Vertex{HInverso, CorCorpo},
        Vertex{JInverso, CorCorpo},
        Vertex{KInverso, CorCorpo}
    };

    std::vector<Vertex> Inverso17 = {
        Vertex{LInverso, CorCorpo},
        Vertex{IInverso, CorCorpo},
        Vertex{MInverso, CorCorpo}
    };

    std::vector<Vertex> Inverso18 = {
        Vertex{LInverso, CorCorpo},
        Vertex{MInverso, CorCorpo},
        Vertex{NInverso, CorCorpo}
    };

    std::vector<Vertex> Corpo1 = {
        Vertex{D1, CorCorpo},
        Vertex{B1, CorCorpo},
        Vertex{A1, CorCorpo}
    };

    std::vector<Vertex> Corpo2 = {
        Vertex{D1, CorCorpo},
        Vertex{E1, CorCorpo},
        Vertex{B1, CorCorpo}
    };

    std::vector<Vertex> Corpo3 = {
        Vertex{R, CorCorpo},
        Vertex{T, CorCorpo},
        Vertex{S, CorCorpo}
    };

    std::vector<Vertex> Corpo4 = {
        Vertex{R, CorCorpo},
        Vertex{U, CorCorpo},
        Vertex{T, CorCorpo}
    };

    std::vector<Vertex> Corpo5 = {
        Vertex{H1, CorCorpo},
        Vertex{G1, CorCorpo},
        Vertex{F1, CorCorpo}
    };

    std::vector<Vertex> Corpo6 = {
        Vertex{H1, CorCorpo},
        Vertex{D1, CorCorpo},
        Vertex{G1, CorCorpo}
    };

    std::vector<Vertex> Corpo7 = {
        Vertex{B, CorCorpo},
        Vertex{C, CorCorpo},
        Vertex{D, CorCorpo}
    };

    std::vector<Vertex> Corpo8 = {
        Vertex{B, CorCorpo},
        Vertex{A, CorCorpo},
        Vertex{C, CorCorpo}
    };

    std::vector<Vertex> Corpo9 = {
        Vertex{V, CorCorpo},
        Vertex{W, CorCorpo},
        Vertex{Z, CorCorpo}
    };

    std::vector<Vertex> Corpo10 = {
        Vertex{V, CorCorpo},
        Vertex{S, CorCorpo},
        Vertex{W, CorCorpo}
    };

    std::vector<Vertex> Corpo11 = {
        Vertex{E, CorCorpo},
        Vertex{D, CorCorpo},
        Vertex{F, CorCorpo}
    };

    std::vector<Vertex> Corpo12 = {
        Vertex{D, CorCorpo},
        Vertex{G, CorCorpo},
        Vertex{F, CorCorpo}
    };

    std::vector<Vertex> Corpo13 = {
        Vertex{O, CorCorpo},
        Vertex{K, CorCorpo},
        Vertex{Q, CorCorpo}
    };

    std::vector<Vertex> Corpo14 = {
        Vertex{O, CorCorpo},
        Vertex{Q, CorCorpo},
        Vertex{P, CorCorpo}
    };

    std::vector<Vertex> Corpo15 = {
        Vertex{I, CorCorpo},
        Vertex{H, CorCorpo},
        Vertex{J, CorCorpo}
    };

    std::vector<Vertex> Corpo16 = {
        Vertex{H, CorCorpo},
        Vertex{K, CorCorpo},
        Vertex{J, CorCorpo}
    };

    std::vector<Vertex> Corpo17 = {
        Vertex{L, CorCorpo},
        Vertex{M, CorCorpo},
        Vertex{I, CorCorpo}
    };

    std::vector<Vertex> Corpo18 = {
        Vertex{L, CorCorpo},
        Vertex{N, CorCorpo},
        Vertex{M, CorCorpo}
    };

    std::vector<Vertex> BoudingBox1 = {
        Vertex{BoundingBoxA, CorCorpo},
        Vertex{BoundingBoxB, CorCorpo},
        Vertex{BoundingBoxC, CorCorpo}
    };

    std::vector<Vertex> BoudingBox2 = {
        Vertex{BoundingBoxA, CorCorpo},
        Vertex{BoundingBoxC, CorCorpo},
        Vertex{BoundingBoxD, CorCorpo}
    };


    std::vector<std::vector<Vertex>> alienVertices = {
        Inverso1,Inverso2,Inverso3,Inverso4,Inverso5,Inverso6,Inverso7,Inverso8,Inverso9,Inverso10,Inverso11,Inverso12,Inverso13,Inverso14,Inverso15,Inverso16,Inverso17,Inverso18,
        Corpo1,Corpo2,Corpo3,Corpo4,Corpo5,Corpo6,Corpo7,Corpo8,Corpo9,Corpo10,Corpo11,Corpo12,Corpo13,Corpo14,Corpo15,Corpo16,Corpo17,Corpo18,

        // Bouding Box
        BoudingBox1,
        // Bouding Box
        BoudingBox2
    };
    return alienVertices;
}

std::vector<std::vector<Vertex>> getAlienModelEstado2() {

    // Bouding Box
    glm::vec4 BoundingBoxA{ -0.11f,  -0.05f,  0.0f, 1.0f };
    glm::vec4 BoundingBoxB{ -0.11f,    0.06f,  0.0f, 1.0f };
    glm::vec4 BoundingBoxC{ 0.11f,    0.06f,  0.0f, 1.0f };
    glm::vec4 BoundingBoxD{ 0.11f,  -0.05f,  0.0f, 1.0f };

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

    //Modela o Alien
    glm::vec4 L = glm::vec4{ -1.6f, 0.2f,  +0.0f, 1.0f };
    glm::vec4 I = glm::vec4{ -1.2f, 0.0f, +0.0f, 1.0f };
    glm::vec4 M = glm::vec4{ -1.0f, 0.0f,  +0.0f, 1.0f };
    glm::vec4 N = glm::vec4{ -1.6f, 0.0f,  +0.0f, 1.0f };

    glm::vec4 J = glm::vec4{ -1.2f, 0.2f, +0.0f, 1.0f };
    glm::vec4 H = glm::vec4{ -0.8f, 0.0f,  +0.0f, 1.0f };
    glm::vec4 K = glm::vec4{ -0.8f, 0.2f,  +0.0f, 1.0f };

    glm::vec4 O = glm::vec4{ -1.0f, 0.2f, +0.0f, 1.0f };
    glm::vec4 Q = glm::vec4{ -0.8f, 0.4f,  +0.0f, 1.0f };
    glm::vec4 P = glm::vec4{ -1.0f, 0.4f,  +0.0f, 1.0f };

    glm::vec4 E = glm::vec4{ -0.8f, -0.4f,  +0.0f, 1.0f };
    glm::vec4 F = glm::vec4{ -0.8f, 0.6f, +0.0f, 1.0f };
    glm::vec4 D = glm::vec4{ -0.6f, -0.4f,  +0.0f, 1.0f };
    glm::vec4 G = glm::vec4{ -0.6f, 0.6f,  +0.0f, 1.0f };

    glm::vec4 V = glm::vec4{ -0.8f, 0.8f,  +0.0f, 1.0f };
    glm::vec4 Z = glm::vec4{ -0.8f, 1.0f, +0.0f, 1.0f };
    glm::vec4 W = glm::vec4{ -0.6f, 1.0f,  +0.0f, 1.0f };
    glm::vec4 S = glm::vec4{ -0.6f, 0.8f,  +0.0f, 1.0f };

    glm::vec4 B = glm::vec4{ -0.6f, -0.6f,  +0.0f, 1.0f };
    glm::vec4 C = glm::vec4{ -0.2f, -0.4f,  +0.0f, 1.0f };
    glm::vec4 A = glm::vec4{ -0.2f, -0.6f,  +0.0f, 1.0f };

    glm::vec4 H1 = glm::vec4{ -0.6f, -0.2f,  +0.0f, 1.0f };
    glm::vec4 F1 = glm::vec4{ -0.6f, 0.2f, +0.0f, 1.0f };
    glm::vec4 G1 = glm::vec4{ -0.4f, 0.2f,  +0.0f, 1.0f };
    glm::vec4 D1 = glm::vec4{ -0.4f, -0.2f,  +0.0f, 1.0f };

    glm::vec4 R = glm::vec4{ -0.6f, 0.4f, +0.0f, 1.0f };
    glm::vec4 T = glm::vec4{ -0.4f, 0.8f,  +0.0f, 1.0f };
    glm::vec4 U = glm::vec4{ -0.4f, 0.4f,  +0.0f, 1.0f };

    glm::vec4 A1 = glm::vec4{ -0.4f, 0.6f,  +0.0f, 1.0f };
    glm::vec4 B1 = glm::vec4{ 0.0f, 0.6f,  +0.0f, 1.0f };
    glm::vec4 E1 = glm::vec4{ 0.0f, -0.2f,  +0.0f, 1.0f };

    glm::vec4 LInverso = glm::vec4{ 1.6f, 0.2f,  +0.0f, 1.0f };
    glm::vec4 IInverso = glm::vec4{ 1.2f, 0.0f, +0.0f, 1.0f };
    glm::vec4 MInverso = glm::vec4{ 1.0f, 0.0f,  +0.0f, 1.0f };
    glm::vec4 NInverso = glm::vec4{ 1.6f, 0.0f,  +0.0f, 1.0f };

    glm::vec4 JInverso = glm::vec4{ 1.2f, 0.2f, +0.0f, 1.0f };
    glm::vec4 HInverso = glm::vec4{ 0.8f, 0.0f,  +0.0f, 1.0f };
    glm::vec4 KInverso = glm::vec4{ 0.8f, 0.2f,  +0.0f, 1.0f };

    glm::vec4 OInverso = glm::vec4{ 1.0f, 0.2f, +0.0f, 1.0f };
    glm::vec4 QInverso = glm::vec4{ 0.8f, 0.4f,  +0.0f, 1.0f };
    glm::vec4 PInverso = glm::vec4{ 1.0f, 0.4f,  +0.0f, 1.0f };

    glm::vec4 EInverso = glm::vec4{ 0.8f, -0.4f,  +0.0f, 1.0f };
    glm::vec4 FInverso = glm::vec4{ 0.8f, 0.6f, +0.0f, 1.0f };
    glm::vec4 DInverso = glm::vec4{ 0.6f, -0.4f,  +0.0f, 1.0f };
    glm::vec4 GInverso = glm::vec4{ 0.6f, 0.6f,  +0.0f, 1.0f };

    glm::vec4 VInverso = glm::vec4{ 0.8f, 0.8f,  +0.0f, 1.0f };
    glm::vec4 ZInverso = glm::vec4{ 0.8f, 1.0f, +0.0f, 1.0f };
    glm::vec4 WInverso = glm::vec4{ 0.6f, 1.0f,  +0.0f, 1.0f };
    glm::vec4 SInverso = glm::vec4{ 0.6f, 0.8f,  +0.0f, 1.0f };

    glm::vec4 BInverso = glm::vec4{ 0.6f, -0.6f,  +0.0f, 1.0f };
    glm::vec4 CInverso = glm::vec4{ 0.2f, -0.4f,  +0.0f, 1.0f };
    glm::vec4 AInverso = glm::vec4{ 0.2f, -0.6f,  +0.0f, 1.0f };

    glm::vec4 H1Inverso = glm::vec4{ 0.6f, -0.2f,  +0.0f, 1.0f };
    glm::vec4 F1Inverso = glm::vec4{ 0.6f, 0.2f, +0.0f, 1.0f };
    glm::vec4 G1Inverso = glm::vec4{ 0.4f, 0.2f,  +0.0f, 1.0f };
    glm::vec4 D1Inverso = glm::vec4{ 0.4f, -0.2f,  +0.0f, 1.0f };

    glm::vec4 RInverso = glm::vec4{ 0.6f, 0.4f, +0.0f, 1.0f };
    glm::vec4 TInverso = glm::vec4{ 0.4f, 0.8f,  +0.0f, 1.0f };
    glm::vec4 UInverso = glm::vec4{ 0.4f, 0.4f,  +0.0f, 1.0f };

    glm::vec4 A1Inverso = glm::vec4{ 0.4f, 0.6f,  +0.0f, 1.0f };
    glm::vec4 B1Inverso = glm::vec4{ 0.0f, 0.6f,  +0.0f, 1.0f };
    glm::vec4 E1Inverso = glm::vec4{ 0.0f, -0.2f,  +0.0f, 1.0f };

    std::vector<Vertex> Inverso1 = {
        Vertex{D1Inverso, CorCorpo},
        Vertex{A1Inverso, CorCorpo},
        Vertex{B1Inverso, CorCorpo}
    };

    std::vector<Vertex> Inverso2 = {
        Vertex{D1Inverso, CorCorpo},
        Vertex{B1Inverso, CorCorpo},
        Vertex{E1Inverso, CorCorpo}
    };

    std::vector<Vertex> Inverso3 = {
        Vertex{RInverso, CorCorpo},
        Vertex{SInverso, CorCorpo},
        Vertex{TInverso, CorCorpo}
    };

    std::vector<Vertex> Inverso4 = {
        Vertex{RInverso, CorCorpo},
        Vertex{TInverso, CorCorpo},
        Vertex{UInverso, CorCorpo}
    };

    std::vector<Vertex> Inverso5 = {
        Vertex{H1Inverso, CorCorpo},
        Vertex{F1Inverso, CorCorpo},
        Vertex{G1Inverso, CorCorpo}
    };

    std::vector<Vertex> Inverso6 = {
        Vertex{H1Inverso, CorCorpo},
        Vertex{G1Inverso, CorCorpo},
        Vertex{D1Inverso, CorCorpo}
    };

    std::vector<Vertex> Inverso7 = {
        Vertex{BInverso, CorCorpo},
        Vertex{DInverso, CorCorpo},
        Vertex{CInverso, CorCorpo}
    };

    std::vector<Vertex> Inverso8 = {
        Vertex{BInverso, CorCorpo},
        Vertex{CInverso, CorCorpo},
        Vertex{AInverso, CorCorpo}
    };

    std::vector<Vertex> Inverso9 = {
        Vertex{VInverso, CorCorpo},
        Vertex{ZInverso, CorCorpo},
        Vertex{WInverso, CorCorpo}
    };

    std::vector<Vertex> Inverso10 = {
        Vertex{VInverso, CorCorpo},
        Vertex{WInverso, CorCorpo},
        Vertex{SInverso, CorCorpo}
    };

    std::vector<Vertex> Inverso11 = {
        Vertex{EInverso, CorCorpo},
        Vertex{FInverso, CorCorpo},
        Vertex{DInverso, CorCorpo}
    };

    std::vector<Vertex> Inverso12 = {
        Vertex{DInverso, CorCorpo},
        Vertex{FInverso, CorCorpo},
        Vertex{GInverso, CorCorpo}
    };

    std::vector<Vertex> Inverso13 = {
        Vertex{OInverso, CorCorpo},
        Vertex{QInverso, CorCorpo},
        Vertex{KInverso, CorCorpo}
    };

    std::vector<Vertex> Inverso14 = {
        Vertex{OInverso, CorCorpo},
        Vertex{PInverso, CorCorpo},
        Vertex{QInverso, CorCorpo}
    };

    std::vector<Vertex> Inverso15 = {
        Vertex{IInverso, CorCorpo},
        Vertex{JInverso, CorCorpo},
        Vertex{HInverso, CorCorpo}
    };

    std::vector<Vertex> Inverso16 = {
        Vertex{HInverso, CorCorpo},
        Vertex{JInverso, CorCorpo},
        Vertex{KInverso, CorCorpo}
    };

    std::vector<Vertex> Inverso17 = {
        Vertex{LInverso, CorCorpo},
        Vertex{JInverso, CorCorpo},
        Vertex{NInverso, CorCorpo}
    };

    std::vector<Vertex> Inverso18 = {
        Vertex{NInverso, CorCorpo},
        Vertex{JInverso, CorCorpo},
        Vertex{IInverso, CorCorpo}
    };

    std::vector<Vertex> Corpo1 = {
        Vertex{D1, CorCorpo},
        Vertex{B1, CorCorpo},
        Vertex{A1, CorCorpo}
    };

    std::vector<Vertex> Corpo2 = {
        Vertex{D1, CorCorpo},
        Vertex{E1, CorCorpo},
        Vertex{B1, CorCorpo}
    };

    std::vector<Vertex> Corpo3 = {
        Vertex{R, CorCorpo},
        Vertex{T, CorCorpo},
        Vertex{S, CorCorpo}
    };

    std::vector<Vertex> Corpo4 = {
        Vertex{R, CorCorpo},
        Vertex{U, CorCorpo},
        Vertex{T, CorCorpo}
    };

    std::vector<Vertex> Corpo5 = {
        Vertex{H1, CorCorpo},
        Vertex{G1, CorCorpo},
        Vertex{F1, CorCorpo}
    };

    std::vector<Vertex> Corpo6 = {
        Vertex{H1, CorCorpo},
        Vertex{D1, CorCorpo},
        Vertex{G1, CorCorpo}
    };

    std::vector<Vertex> Corpo7 = {
        Vertex{B, CorCorpo},
        Vertex{C, CorCorpo},
        Vertex{D, CorCorpo}
    };

    std::vector<Vertex> Corpo8 = {
        Vertex{B, CorCorpo},
        Vertex{A, CorCorpo},
        Vertex{C, CorCorpo}
    };

    std::vector<Vertex> Corpo9 = {
        Vertex{V, CorCorpo},
        Vertex{W, CorCorpo},
        Vertex{Z, CorCorpo}
    };

    std::vector<Vertex> Corpo10 = {
        Vertex{V, CorCorpo},
        Vertex{S, CorCorpo},
        Vertex{W, CorCorpo}
    };

    std::vector<Vertex> Corpo11 = {
        Vertex{E, CorCorpo},
        Vertex{D, CorCorpo},
        Vertex{F, CorCorpo}
    };

    std::vector<Vertex> Corpo12 = {
        Vertex{D, CorCorpo},
        Vertex{G, CorCorpo},
        Vertex{F, CorCorpo}
    };

    std::vector<Vertex> Corpo13 = {
        Vertex{O, CorCorpo},
        Vertex{K, CorCorpo},
        Vertex{Q, CorCorpo}
    };

    std::vector<Vertex> Corpo14 = {
        Vertex{O, CorCorpo},
        Vertex{Q, CorCorpo},
        Vertex{P, CorCorpo}
    };

    std::vector<Vertex> Corpo15 = {
        Vertex{I, CorCorpo},
        Vertex{H, CorCorpo},
        Vertex{J, CorCorpo}
    };

    std::vector<Vertex> Corpo16 = {
        Vertex{H, CorCorpo},
        Vertex{K, CorCorpo},
        Vertex{J, CorCorpo}
    };

    std::vector<Vertex> Corpo17 = {
        Vertex{L, CorCorpo},
        Vertex{N, CorCorpo},
        Vertex{J, CorCorpo}
    };

    std::vector<Vertex> Corpo18 = {
        Vertex{N, CorCorpo},
        Vertex{I, CorCorpo},
        Vertex{J, CorCorpo}
    };

    std::vector<Vertex> BoudingBox1 = {
        Vertex{BoundingBoxA, CorCorpo},
        Vertex{BoundingBoxB, CorCorpo},
        Vertex{BoundingBoxC, CorCorpo}
    };

    std::vector<Vertex> BoudingBox2 = {
        Vertex{BoundingBoxA, CorCorpo},
        Vertex{BoundingBoxC, CorCorpo},
        Vertex{BoundingBoxD, CorCorpo}
    };


    std::vector<std::vector<Vertex>> alienVertices = {
        Inverso1,Inverso2,Inverso3,Inverso4,Inverso5,Inverso6,Inverso7,Inverso8,Inverso9,Inverso10,Inverso11,Inverso12,Inverso13,Inverso14,Inverso15,Inverso16,Inverso17,Inverso18,
        Corpo1,Corpo2,Corpo3,Corpo4,Corpo5,Corpo6,Corpo7,Corpo8,Corpo9,Corpo10,Corpo11,Corpo12,Corpo13,Corpo14,Corpo15,Corpo16,Corpo17,Corpo18,

        // Bouding Box
        BoudingBox1,
        // Bouding Box
        BoudingBox2
    };
    return alienVertices;
}

std::vector<std::vector<Vertex>> getAlienModelEstado3() {

    // Bouding Box
    glm::vec4 BoundingBoxA{ -0.11f,  -0.05f,  0.0f, 1.0f };
    glm::vec4 BoundingBoxB{ -0.11f,    0.06f,  0.0f, 1.0f };
    glm::vec4 BoundingBoxC{ 0.11f,    0.06f,  0.0f, 1.0f };
    glm::vec4 BoundingBoxD{ 0.11f,  -0.05f,  0.0f, 1.0f };

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

    //Modela o Alien
    glm::vec4 L = glm::vec4{ -1.0f, 0.6f,  +0.0f, 1.0f };
    glm::vec4 I = glm::vec4{ -1.2f, 0.0f, +0.0f, 1.0f };
    glm::vec4 M = glm::vec4{ -1.0f, 0.0f,  +0.0f, 1.0f };
    glm::vec4 N = glm::vec4{ -1.2f, 0.6f,  +0.0f, 1.0f };

    glm::vec4 J = glm::vec4{ -1.2f, 0.2f, +0.0f, 1.0f };
    glm::vec4 H = glm::vec4{ -0.8f, 0.0f,  +0.0f, 1.0f };
    glm::vec4 K = glm::vec4{ -0.8f, 0.2f,  +0.0f, 1.0f };

    glm::vec4 O = glm::vec4{ -1.0f, 0.2f, +0.0f, 1.0f };
    glm::vec4 Q = glm::vec4{ -0.8f, 0.4f,  +0.0f, 1.0f };
    glm::vec4 P = glm::vec4{ -1.0f, 0.4f,  +0.0f, 1.0f };

    glm::vec4 E = glm::vec4{ -0.8f, -0.4f,  +0.0f, 1.0f };
    glm::vec4 F = glm::vec4{ -0.8f, 0.6f, +0.0f, 1.0f };
    glm::vec4 D = glm::vec4{ -0.6f, -0.4f,  +0.0f, 1.0f };
    glm::vec4 G = glm::vec4{ -0.6f, 0.6f,  +0.0f, 1.0f };

    glm::vec4 V = glm::vec4{ -0.8f, 0.8f,  +0.0f, 1.0f };
    glm::vec4 Z = glm::vec4{ -0.8f, 1.0f, +0.0f, 1.0f };
    glm::vec4 W = glm::vec4{ -0.6f, 1.0f,  +0.0f, 1.0f };
    glm::vec4 S = glm::vec4{ -0.6f, 0.8f,  +0.0f, 1.0f };

    glm::vec4 B = glm::vec4{ -0.6f, -0.6f,  +0.0f, 1.0f };
    glm::vec4 C = glm::vec4{ -0.2f, -0.4f,  +0.0f, 1.0f };
    glm::vec4 A = glm::vec4{ -0.2f, -0.6f,  +0.0f, 1.0f };

    glm::vec4 H1 = glm::vec4{ -0.6f, -0.2f,  +0.0f, 1.0f };
    glm::vec4 F1 = glm::vec4{ -0.6f, 0.2f, +0.0f, 1.0f };
    glm::vec4 G1 = glm::vec4{ -0.4f, 0.2f,  +0.0f, 1.0f };
    glm::vec4 D1 = glm::vec4{ -0.4f, -0.2f,  +0.0f, 1.0f };

    glm::vec4 R = glm::vec4{ -0.6f, 0.4f, +0.0f, 1.0f };
    glm::vec4 T = glm::vec4{ -0.4f, 0.8f,  +0.0f, 1.0f };
    glm::vec4 U = glm::vec4{ -0.4f, 0.4f,  +0.0f, 1.0f };

    glm::vec4 A1 = glm::vec4{ -0.4f, 0.6f,  +0.0f, 1.0f };
    glm::vec4 B1 = glm::vec4{ 0.0f, 0.6f,  +0.0f, 1.0f };
    glm::vec4 E1 = glm::vec4{ 0.0f, -0.2f,  +0.0f, 1.0f };

    glm::vec4 LInverso = glm::vec4{ 1.0f, 0.6f,  +0.0f, 1.0f };
    glm::vec4 IInverso = glm::vec4{ 1.2f, 0.0f, +0.0f, 1.0f };
    glm::vec4 MInverso = glm::vec4{ 1.0f, 0.0f,  +0.0f, 1.0f };
    glm::vec4 NInverso = glm::vec4{ 1.2f, 0.6f,  +0.0f, 1.0f };

    glm::vec4 JInverso = glm::vec4{ 1.2f, 0.2f, +0.0f, 1.0f };
    glm::vec4 HInverso = glm::vec4{ 0.8f, 0.0f,  +0.0f, 1.0f };
    glm::vec4 KInverso = glm::vec4{ 0.8f, 0.2f,  +0.0f, 1.0f };

    glm::vec4 OInverso = glm::vec4{ 1.0f, 0.2f, +0.0f, 1.0f };
    glm::vec4 QInverso = glm::vec4{ 0.8f, 0.4f,  +0.0f, 1.0f };
    glm::vec4 PInverso = glm::vec4{ 1.0f, 0.4f,  +0.0f, 1.0f };

    glm::vec4 EInverso = glm::vec4{ 0.8f, -0.4f,  +0.0f, 1.0f };
    glm::vec4 FInverso = glm::vec4{ 0.8f, 0.6f, +0.0f, 1.0f };
    glm::vec4 DInverso = glm::vec4{ 0.6f, -0.4f,  +0.0f, 1.0f };
    glm::vec4 GInverso = glm::vec4{ 0.6f, 0.6f,  +0.0f, 1.0f };

    glm::vec4 VInverso = glm::vec4{ 0.8f, 0.8f,  +0.0f, 1.0f };
    glm::vec4 ZInverso = glm::vec4{ 0.8f, 1.0f, +0.0f, 1.0f };
    glm::vec4 WInverso = glm::vec4{ 0.6f, 1.0f,  +0.0f, 1.0f };
    glm::vec4 SInverso = glm::vec4{ 0.6f, 0.8f,  +0.0f, 1.0f };

    glm::vec4 BInverso = glm::vec4{ 0.6f, -0.6f,  +0.0f, 1.0f };
    glm::vec4 CInverso = glm::vec4{ 0.2f, -0.4f,  +0.0f, 1.0f };
    glm::vec4 AInverso = glm::vec4{ 0.2f, -0.6f,  +0.0f, 1.0f };

    glm::vec4 H1Inverso = glm::vec4{ 0.6f, -0.2f,  +0.0f, 1.0f };
    glm::vec4 F1Inverso = glm::vec4{ 0.6f, 0.2f, +0.0f, 1.0f };
    glm::vec4 G1Inverso = glm::vec4{ 0.4f, 0.2f,  +0.0f, 1.0f };
    glm::vec4 D1Inverso = glm::vec4{ 0.4f, -0.2f,  +0.0f, 1.0f };

    glm::vec4 RInverso = glm::vec4{ 0.6f, 0.4f, +0.0f, 1.0f };
    glm::vec4 TInverso = glm::vec4{ 0.4f, 0.8f,  +0.0f, 1.0f };
    glm::vec4 UInverso = glm::vec4{ 0.4f, 0.4f,  +0.0f, 1.0f };

    glm::vec4 A1Inverso = glm::vec4{ 0.4f, 0.6f,  +0.0f, 1.0f };
    glm::vec4 B1Inverso = glm::vec4{ 0.0f, 0.6f,  +0.0f, 1.0f };
    glm::vec4 E1Inverso = glm::vec4{ 0.0f, -0.2f,  +0.0f, 1.0f };

    std::vector<Vertex> Inverso1 = {
        Vertex{D1Inverso, CorCorpo},
        Vertex{A1Inverso, CorCorpo},
        Vertex{B1Inverso, CorCorpo}
    };

    std::vector<Vertex> Inverso2 = {
        Vertex{D1Inverso, CorCorpo},
        Vertex{B1Inverso, CorCorpo},
        Vertex{E1Inverso, CorCorpo}
    };

    std::vector<Vertex> Inverso3 = {
        Vertex{RInverso, CorCorpo},
        Vertex{SInverso, CorCorpo},
        Vertex{TInverso, CorCorpo}
    };

    std::vector<Vertex> Inverso4 = {
        Vertex{RInverso, CorCorpo},
        Vertex{TInverso, CorCorpo},
        Vertex{UInverso, CorCorpo}
    };

    std::vector<Vertex> Inverso5 = {
        Vertex{H1Inverso, CorCorpo},
        Vertex{F1Inverso, CorCorpo},
        Vertex{G1Inverso, CorCorpo}
    };

    std::vector<Vertex> Inverso6 = {
        Vertex{H1Inverso, CorCorpo},
        Vertex{G1Inverso, CorCorpo},
        Vertex{D1Inverso, CorCorpo}
    };

    std::vector<Vertex> Inverso7 = {
        Vertex{BInverso, CorCorpo},
        Vertex{DInverso, CorCorpo},
        Vertex{CInverso, CorCorpo}
    };

    std::vector<Vertex> Inverso8 = {
        Vertex{BInverso, CorCorpo},
        Vertex{CInverso, CorCorpo},
        Vertex{AInverso, CorCorpo}
    };

    std::vector<Vertex> Inverso9 = {
        Vertex{VInverso, CorCorpo},
        Vertex{ZInverso, CorCorpo},
        Vertex{WInverso, CorCorpo}
    };

    std::vector<Vertex> Inverso10 = {
        Vertex{VInverso, CorCorpo},
        Vertex{WInverso, CorCorpo},
        Vertex{SInverso, CorCorpo}
    };

    std::vector<Vertex> Inverso11 = {
        Vertex{EInverso, CorCorpo},
        Vertex{FInverso, CorCorpo},
        Vertex{DInverso, CorCorpo}
    };

    std::vector<Vertex> Inverso12 = {
        Vertex{DInverso, CorCorpo},
        Vertex{FInverso, CorCorpo},
        Vertex{GInverso, CorCorpo}
    };

    std::vector<Vertex> Inverso13 = {
        Vertex{OInverso, CorCorpo},
        Vertex{QInverso, CorCorpo},
        Vertex{KInverso, CorCorpo}
    };

    std::vector<Vertex> Inverso14 = {
        Vertex{OInverso, CorCorpo},
        Vertex{PInverso, CorCorpo},
        Vertex{QInverso, CorCorpo}
    };

    std::vector<Vertex> Inverso15 = {
        Vertex{IInverso, CorCorpo},
        Vertex{JInverso, CorCorpo},
        Vertex{HInverso, CorCorpo}
    };

    std::vector<Vertex> Inverso16 = {
        Vertex{HInverso, CorCorpo},
        Vertex{JInverso, CorCorpo},
        Vertex{KInverso, CorCorpo}
    };

    std::vector<Vertex> Inverso17 = {
        Vertex{OInverso, CorCorpo},
        Vertex{NInverso, CorCorpo},
        Vertex{LInverso, CorCorpo}
    };

    std::vector<Vertex> Inverso18 = {
        Vertex{NInverso, CorCorpo},
        Vertex{OInverso, CorCorpo},
        Vertex{JInverso, CorCorpo}
    };

    std::vector<Vertex> Corpo1 = {
        Vertex{D1, CorCorpo},
        Vertex{B1, CorCorpo},
        Vertex{A1, CorCorpo}
    };

    std::vector<Vertex> Corpo2 = {
        Vertex{D1, CorCorpo},
        Vertex{E1, CorCorpo},
        Vertex{B1, CorCorpo}
    };

    std::vector<Vertex> Corpo3 = {
        Vertex{R, CorCorpo},
        Vertex{T, CorCorpo},
        Vertex{S, CorCorpo}
    };

    std::vector<Vertex> Corpo4 = {
        Vertex{R, CorCorpo},
        Vertex{U, CorCorpo},
        Vertex{T, CorCorpo}
    };

    std::vector<Vertex> Corpo5 = {
        Vertex{H1, CorCorpo},
        Vertex{G1, CorCorpo},
        Vertex{F1, CorCorpo}
    };

    std::vector<Vertex> Corpo6 = {
        Vertex{H1, CorCorpo},
        Vertex{D1, CorCorpo},
        Vertex{G1, CorCorpo}
    };

    std::vector<Vertex> Corpo7 = {
        Vertex{B, CorCorpo},
        Vertex{C, CorCorpo},
        Vertex{D, CorCorpo}
    };

    std::vector<Vertex> Corpo8 = {
        Vertex{B, CorCorpo},
        Vertex{A, CorCorpo},
        Vertex{C, CorCorpo}
    };

    std::vector<Vertex> Corpo9 = {
        Vertex{V, CorCorpo},
        Vertex{W, CorCorpo},
        Vertex{Z, CorCorpo}
    };

    std::vector<Vertex> Corpo10 = {
        Vertex{V, CorCorpo},
        Vertex{S, CorCorpo},
        Vertex{W, CorCorpo}
    };

    std::vector<Vertex> Corpo11 = {
        Vertex{E, CorCorpo},
        Vertex{D, CorCorpo},
        Vertex{F, CorCorpo}
    };

    std::vector<Vertex> Corpo12 = {
        Vertex{D, CorCorpo},
        Vertex{G, CorCorpo},
        Vertex{F, CorCorpo}
    };

    std::vector<Vertex> Corpo13 = {
        Vertex{O, CorCorpo},
        Vertex{K, CorCorpo},
        Vertex{Q, CorCorpo}
    };

    std::vector<Vertex> Corpo14 = {
        Vertex{O, CorCorpo},
        Vertex{Q, CorCorpo},
        Vertex{P, CorCorpo}
    };

    std::vector<Vertex> Corpo15 = {
        Vertex{I, CorCorpo},
        Vertex{H, CorCorpo},
        Vertex{J, CorCorpo}
    };

    std::vector<Vertex> Corpo16 = {
        Vertex{H, CorCorpo},
        Vertex{K, CorCorpo},
        Vertex{J, CorCorpo}
    };

    std::vector<Vertex> Corpo17 = {
        Vertex{O, CorCorpo},
        Vertex{L, CorCorpo},
        Vertex{N, CorCorpo}
    };

    std::vector<Vertex> Corpo18 = {
        Vertex{N, CorCorpo},
        Vertex{J, CorCorpo},
        Vertex{O, CorCorpo}
    };

    std::vector<Vertex> BoudingBox1 = {
        Vertex{BoundingBoxA, CorCorpo},
        Vertex{BoundingBoxB, CorCorpo},
        Vertex{BoundingBoxC, CorCorpo}
    };

    std::vector<Vertex> BoudingBox2 = {
        Vertex{BoundingBoxA, CorCorpo},
        Vertex{BoundingBoxC, CorCorpo},
        Vertex{BoundingBoxD, CorCorpo}
    };


    std::vector<std::vector<Vertex>> alienVertices = {
        Inverso1,Inverso2,Inverso3,Inverso4,Inverso5,Inverso6,Inverso7,Inverso8,Inverso9,Inverso10,Inverso11,Inverso12,Inverso13,Inverso14,Inverso15,Inverso16,Inverso17,Inverso18,
        Corpo1,Corpo2,Corpo3,Corpo4,Corpo5,Corpo6,Corpo7,Corpo8,Corpo9,Corpo10,Corpo11,Corpo12,Corpo13,Corpo14,Corpo15,Corpo16,Corpo17,Corpo18,

        // Bouding Box
        BoudingBox1,
        // Bouding Box
        BoudingBox2
    };
    return alienVertices;
}