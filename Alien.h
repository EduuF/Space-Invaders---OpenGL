#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <array>

class Alien {
public:
	float posicao, rotacao;

    // FitaCassete
    std::array<glm::vec3, 3> Esquerda = {
        glm::vec3{-0.15f, -0.05f, 0.0f},
        glm::vec3{-0.05f, -0.05f, 0.0f},
        glm::vec3{-0.1f, 0.05f, 0.0f},
    };

    std::array<glm::vec3, 3> Direita = {
        glm::vec3{0.05f, -0.05f, 0.0f},
        glm::vec3{0.15f, -0.05f, 0.0f},
        glm::vec3{0.1f, 0.05f, 0.0f},
    };

    std::array<glm::vec3, 3> Cima = {
        glm::vec3{-0.05f, 0.05f, 0.0f},
        glm::vec3{0.05f, 0.05f, 0.0f},
        glm::vec3{0.0f, 0.1f, 0.0f},
    };

    std::array<glm::vec3, 3> baixo = {
        glm::vec3{-0.05f, -0.05f, 0.0f},
        glm::vec3{0.05f, -0.05f, 0.0f},
        glm::vec3{0.0f, -0.1f, 0.0f}
    };

    std::array<std::array<glm::vec3, 3>, 4> cassetteVertices = {
        // Esquerda
        Esquerda,
        // Direita
        Direita,
        // Cima
        Cima,
        // Baixo
        baixo
    };

    // TV
    std::array<glm::vec3, 3> Corpo = {
        glm::vec3{-0.15f, -0.1f, 0.0f},
        glm::vec3{0.15f, -0.1f, 0.0f},
        glm::vec3{0.0f, 0.1f, 0.0f},
    };


    std::array<glm::vec3, 3> Suporte = {
        glm::vec3{-0.05f, -0.2f, 0.0f},
        glm::vec3{0.05f, -0.2f, 0.0f},
        glm::vec3{0.0f, -0.1f, 0.0f}
    };

    std::array<std::array<glm::vec3, 3>, 2> tvVertices = {
        // Corpo
        Corpo,
        // Suporte
        Suporte
    };


	Alien(float posicao, float rotacao, float escala);
    std::array<std::array<glm::vec3, 3>, 2> constroiAlien();
};
