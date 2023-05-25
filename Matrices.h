#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <array>

void TranslationMatrix(glm::vec4 &CentroObjeto, glm::vec3 T);
void ScaleMatrix(std::array<glm::vec4, 3>& Triangle, glm::vec3 FatorDeEscola);
void RotationMatrix(std::array<glm::vec4, 3>& Triangle, float graus, glm::vec3 eixoDeRotacao);
void ComposedMatrix();