#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <array>

void TranslationMatrix(glm::vec4 &CentroObjeto, std::array<std::array<glm::vec4, 3>, 7>& Objeto, glm::vec3 T);
void ScaleMatrix(std::array<glm::vec4, 3>& Triangle, glm::vec3 FatorDeEscola, glm::vec4& Centro);
void RotationMatrix(std::array<glm::vec4, 3>& Triangle, float graus, glm::vec4& Centro);
void ComposedMatrix();
void TranslationMatrixAlien(glm::vec4& CentroObjeto, std::array<std::array<glm::vec4, 3>, 18>& Objeto, glm::vec3 T);