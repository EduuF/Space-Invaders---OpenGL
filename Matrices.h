#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <vector>
#include "Triangle.h"

void ScaleMatrix(std::vector<std::vector<Vertex>>& Objeto, glm::vec3 FatorDeEscola, glm::vec4& Centro);
void RotationMatrix(std::vector<std::vector<Vertex>>& Objeto, float graus, glm::vec4& Centro, glm::vec4& Up, glm::vec4 Right);
void TranslationMatrix(std::vector<std::vector<Vertex>>& Objeto, glm::vec4& CentroObjeto, glm::vec4& Up,  glm::vec3 T);
void RotacionaEmRelacaoAOrigem(std::vector<std::vector<Vertex>>& Objeto, float graus, glm::vec4& Centro, glm::vec4& Up, glm::vec4 Right);