#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <array>

void ScaleMatrix(std::array<glm::vec4, 3>& Triangle, glm::vec3 FatorDeEscola, glm::vec4& Centro);
void RotationMatrixAlien(std::array<std::array<glm::vec4, 3>, 18>& Objeto, float graus, glm::vec4& Centro);
void RotationMatrixNave(std::array<std::array<glm::vec4, 3>, 7>& Objeto, float graus, glm::vec4& Centro);
void TranslationMatrixAlien(std::array<std::array<glm::vec4, 3>, 18>& Objeto, glm::vec4& CentroObjeto,  glm::vec3 T);
void TranslationMatrixNave(std::array<std::array<glm::vec4, 3>, 7>& Objeto, glm::vec4& CentroObjeto, glm::vec3 T);

void ModelViewProjectionAlien(std::array<std::array<glm::vec4, 3>, 18>& Objeto, glm::vec3 Eye, glm::vec3 Center, glm::vec3 Up, float FoVAngle);
void ModelViewProjectionNave(std::array<std::array<glm::vec4, 3>, 7>& Objeto, glm::vec3 Eye, glm::vec3 Center, glm::vec3 Up, float FoVAngle);