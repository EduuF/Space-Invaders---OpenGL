#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <vector>
#include "Triangle.h"

void ScaleMatrix(std::vector<Vertex>& Vertices, glm::vec3 FatorDeEscola, glm::vec4& Centro);
void RotationMatrix(std::vector<Vertex>& Vertices, float graus, glm::vec4& Centro, glm::vec4& Up, glm::vec4 Right);
void TranslationMatrix(std::vector<Vertex>& Vertices, glm::vec4& CentroObjeto, glm::vec4& Up,  glm::vec3 T);
void RotacionaEmRelacaoAOrigem(std::vector<Vertex>& Vertices, float graus, glm::vec4& Centro, glm::vec4& Up, glm::vec4 Right);