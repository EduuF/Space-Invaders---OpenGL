#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <vector>
#include "Triangle.h"

std::vector<Vertex> getAlienVertices(bool hasPowerUp1, bool hasPowerUp2);
std::vector<glm::ivec3> getAlienIndices(int pose);
