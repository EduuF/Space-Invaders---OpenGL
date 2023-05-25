#include "Matrices.h"

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <array>

void TranslationMatrix(glm::vec4 &CentroObjeto, glm::vec3 T) {
	glm::mat4 I = glm::identity<glm::mat4>();
	glm::mat4 Translation = glm::translate(I, T); // Translation translada qualquer ponto em 10 no x, 10 no y e 10 no z

	CentroObjeto = Translation * CentroObjeto;

	std:: cout << "TMatrix" << std::endl;
	std::cout << CentroObjeto.x << CentroObjeto.y << std::endl;
}

void ScaleMatrix(std::array<glm::vec4, 3>& Triangle, glm::vec3 FatorDeEscola) {
	glm::mat4 I = glm::identity<glm::mat4>();
	glm::mat4 Scale = glm::scale(I, FatorDeEscola);

	for (int i = 0; i < 3; i++) {
		Triangle[i] = Scale * Triangle[i];
	}
}

void RotationMatrix(std::array<glm::vec4, 3>& Triangle, float graus, glm::vec3 eixoDeRotacao) {

	glm::mat4 I = glm::identity<glm::mat4>();
	float Angle = glm::radians(graus);

	glm::mat4 Rotation = glm::rotate(I, Angle, eixoDeRotacao);

	for (int i = 0; i < 3; i++) {
		Triangle[i] = Rotation * Triangle[i];
	}
}

void ComposedMatrix() {

}