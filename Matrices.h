#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <array>
#include "Triangle.h"

void ScaleMatrix(std::array<Vertex, 3>& Triangle, glm::vec3 FatorDeEscola, glm::vec4& Centro);

void RotationMatrixAlien(std::array<std::array<Vertex, 3>, 18>& Objeto, float graus, glm::vec4& Centro, glm::vec4& Up, glm::vec4 Right);
void RotationMatrixNave(std::array<std::array<Vertex, 3>, 7>& Objeto, float graus, glm::vec4& Centro, glm::vec4& NaveUp, glm::vec4 Right);
void RotationMatrixMissil(std::array<std::array<Vertex, 3>, 4>& Objeto, float graus, glm::vec4& Centro, glm::vec4& NaveUp, glm::vec4 Right);

void TranslationMatrixAlien(std::array<std::array<Vertex, 3>, 18>& Objeto, glm::vec4& CentroObjeto,  glm::vec3 T);
void TranslationMatrixNave(std::array<std::array<Vertex, 3>, 7>& Objeto, glm::vec4& CentroObjeto, glm::vec3 T);
void TranslationMatrixMissil(std::array<std::array<Vertex, 3>, 4>& Objeto, glm::vec4& CentroObjeto, glm::vec3 T);