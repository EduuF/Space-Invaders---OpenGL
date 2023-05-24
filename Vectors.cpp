#include "Vectors.h"

#define GLM_SWIZZLE
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>

void Constructors() {
    std::cout << std::endl << "Constructor:" << std::endl;

    glm::vec2 Point2{ 10.0f, 0.0f};
    glm::vec3 Point3{ 10.0f, 0.0f, 0.0f };
    glm::vec4 Point4{ 10.0f, 0.0f, 0.0f, 0.0f };
    glm::ivec2 Point5{ 1,2 };
    glm::bvec2 Point6{ false, true };
    glm::dvec2 Point7{ 10.0,10.0 }; // precisão dupla
    glm::vec3 Point8{ Point2, 1.0f };
    glm::vec3 Point9{ Point8 + 0.2f };

    std::cout << "Point2: " << glm::to_string(Point2) << std::endl;
    std::cout << "Point3: " << glm::to_string(Point3) << std::endl;
    std::cout << "Point4: " << glm::to_string(Point4) << std::endl;
    std::cout << "Point5: " << glm::to_string(Point5) << std::endl;
    std::cout << "Point6: " << glm::to_string(Point6) << std::endl;
    std::cout << "Point7: " << glm::to_string(Point7) << std::endl;
    std::cout << "Point8: " << glm::to_string(Point8) << std::endl;
    std::cout << "Point9: " << glm::to_string(Point9) << std::endl;
    std::cout << std::endl;
}

void Components() {
    std::cout << "Components:" << std::endl;

    glm::vec3 P{ 1, 2, 3 };
    std::cout << "X: " << P.x << "| Y: " << P.y << "| Z: " << P.z << std::endl;

    std::cout << std::endl;
}

void Swizzle() {
    std::cout << "Swizzle:" << std::endl;

    glm::vec4 P{ 1,2,3,4 };

    glm::vec3 Q = P.xxx;
    glm::vec3 R = P.xyx;
    glm::vec4 S = P.zxyw;

    std::cout << "Q: " << glm::to_string(Q) << std::endl;
    std::cout << "S: " << glm::to_string(S) << std::endl;
    std::cout << std::endl;

}

void Operations() {
    std::cout << "Operations:" << std::endl;

    glm::vec3 P0{ 2.0f, 6.0f, 0.0f };
    glm::vec3 P1{ 1.0f, 0.5f, 3.0f };

    std::cout << "P0: " << glm::to_string(P0) << std::endl;
    std::cout << "P1: " << glm::to_string(P1) << std::endl;

    glm::vec3 R;

    // Soma
    R = P0 + P1;
    std::cout << "Soma: " << glm::to_string(R) << std::endl;

    // Escalar
    R = P0 * 2.0f;
    std::cout << "Escalar (2): " << glm::to_string(R) << std::endl;

    // Multiplicação entre vetores Componente a componente
    R = P0 * P1;
    std::cout << "Multiplicacao entre vetores componente a componente: " << glm::to_string(R) << std::endl;

    // Modulo de um vetor
    float L = glm::length(P0);
    std::cout << "Modulo de um vetor (P0): " << L << std::endl;

    // Vetor normalizado
    glm::vec3 Norm = glm::normalize(P1);
    std::cout << "Vetor normalizado (PO): " << glm::to_string(Norm) << std::endl;

    // Dot Product
    float Dot = glm::dot(P0, P1);
    std::cout << "Produto escalar (P0 & P1): " << Dot << std::endl;

    // Produto Vetorial
    R = glm::cross(P0,P1);
    std::cout << "Produto Vetorial (PO & P1): " << glm::to_string(R) << std::endl;

    // Distancia entre pontos (definidos por vetor)
    float d = glm::distance(P0, P1);
    std::cout << "Distancia entre pontos (definidos por vetor) (P0 & P1): " << d << std::endl;

    // Refração
    glm::vec3 Refract = glm::refract(P0, Norm, 0.7f);
    std::cout << "Refracao (PO): " << glm::to_string(Refract) << std::endl;

    // Reflexão
    glm::vec3 Reflect = glm::reflect(P0, Norm);
    std::cout << "Reflexao (PO): " << glm::to_string(Reflect) << std::endl;


}
