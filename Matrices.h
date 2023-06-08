#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <array>
#include <vector>
#include "Triangle.h"

void ScaleMatrix(std::vector<Vertex>& Triangle, glm::vec3 FatorDeEscola, glm::vec4& Centro);

void RotationMatrixAlien(std::vector<std::vector<Vertex>>& Objeto, float graus, glm::vec4& Centro, glm::vec4& Up, glm::vec4 Right);
void RotationMatrixNave(std::vector<std::vector<Vertex>>& Objeto, float graus, glm::vec4& Centro, glm::vec4& NaveUp, glm::vec4 Right);
void RotationMatrixMissil(std::vector<std::vector<Vertex>>& Objeto, float graus, glm::vec4& Centro, glm::vec4& NaveUp, glm::vec4 Right);
void RotationMatrixBomba(std::vector<std::vector<Vertex>>& Objeto, float graus, glm::vec4& Centro, glm::vec4& Up, glm::vec4 Right);

void TranslationMatrixAlien(std::vector<std::vector<Vertex>>& Objeto, glm::vec4& CentroObjeto,  glm::vec3 T);
void TranslationMatrixNave(std::vector<std::vector<Vertex>>& Objeto, glm::vec4& CentroObjeto, glm::vec3 T);
void TranslationMatrixMissil(std::vector<std::vector<Vertex>>& Objeto, glm::vec4& CentroObjeto, glm::vec3 T);
void TranslationMatrixBomba(std::vector<std::vector<Vertex>>& Objeto, glm::vec4& CentroObjeto, glm::vec3 T);