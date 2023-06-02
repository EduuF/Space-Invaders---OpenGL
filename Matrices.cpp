#include "Matrices.h"
#include "Triangle.h"

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <array>

// Leva o triangulo para o centro do objeto, escala e volta para a posicao original
// Isso evita que ao fazer a escala o objeto se aproxime ou afaste da origem do plano original
void ScaleMatrix(std::array<Vertex, 3>& Triangle, glm::vec3 FatorDeEscala, glm::vec4 &Centro) {
	glm::vec3 OrigemDoObjeto{ Centro.x, Centro.y, Centro.z };
	glm::mat4 I = glm::identity<glm::mat4>();
	glm::mat4 TranslationToObjectOrigin = glm::translate(I, -OrigemDoObjeto); // Translada Centro para o Origem do ambiente
	glm::mat4 Scale = glm::scale(I, FatorDeEscala); // Faz escala
	glm::mat4 TranslationToObjectBack = glm::translate(I, OrigemDoObjeto); // Translada o ponto de volta para seu lugar original
	// Composição de transformações
	glm::mat4 Transformation = TranslationToObjectBack * Scale * TranslationToObjectOrigin;

	for (auto& vertex : Triangle) {
		vertex.Position = Transformation * vertex.Position;
	}
}

void RotationMatrixAlien(std::array<std::array<Vertex, 3>, 18>& Objeto, float graus, glm::vec4& Centro, glm::vec4& Up) {

	glm::vec3 eixoDeRotacao{ 0.0f, 0.0f, 1.0f };
	glm::mat4 I = glm::identity<glm::mat4>();
	float Angle = glm::radians(graus);

	glm::vec3 CentroDoObjeto{ Centro.x, Centro.y, Centro.z };
	glm::mat4 TranslationToObjectOrigin = glm::translate(I, -CentroDoObjeto); // Translada o triangulo para a origem do objeto
	glm::mat4 Rotation = glm::rotate(I, Angle, eixoDeRotacao); // Rotaciona
	glm::mat4 TranslationToObjectBack = glm::translate(I, CentroDoObjeto); // Translada o ponto de volta para seu lugar original

	glm::mat4 Transformation = TranslationToObjectBack * Rotation * TranslationToObjectOrigin;

	Up = Transformation * Up;

	for (auto& triangulo : Objeto) {
		for (auto& vertex : triangulo) {
			vertex.Position = Transformation * vertex.Position;
		}
	}
}

void RotationMatrixNave(std::array<std::array<Vertex, 3>, 7>& Objeto, float graus, glm::vec4& Centro, glm::vec4& NaveUp) {

	glm::vec3 eixoDeRotacao{ 0.0f, 0.0f, 1.0f };
	glm::mat4 I = glm::identity<glm::mat4>();
	float Angle = glm::radians(graus);

	glm::vec3 CentroDoObjeto{ Centro.x, Centro.y, Centro.z };
	glm::mat4 TranslationToObjectOrigin = glm::translate(I, -CentroDoObjeto); // Translada o triangulo para a origem do objeto
	glm::mat4 Rotation = glm::rotate(I, Angle, eixoDeRotacao); // Rotaciona
	glm::mat4 TranslationToObjectBack = glm::translate(I, CentroDoObjeto); // Translada o ponto de volta para seu lugar original

	glm::mat4 Transformation = TranslationToObjectBack * Rotation * TranslationToObjectOrigin;

	NaveUp = Transformation * NaveUp;

	for (auto& triangulo : Objeto) {
		for (auto& vertex : triangulo) {
			vertex.Position = Transformation * vertex.Position;
		}
	}
}

void RotationMatrixMissil(std::array<std::array<Vertex, 3>, 4>& Objeto, float graus, glm::vec4& Centro, glm::vec4& NaveUp) {

	glm::vec3 eixoDeRotacao{ 0.0f, 0.0f, 1.0f };
	glm::mat4 I = glm::identity<glm::mat4>();
	float Angle = glm::radians(graus);

	glm::vec3 CentroDoObjeto{ Centro.x, Centro.y, Centro.z };
	glm::mat4 TranslationToObjectOrigin = glm::translate(I, -CentroDoObjeto); // Translada o triangulo para a origem do objeto
	glm::mat4 Rotation = glm::rotate(I, Angle, eixoDeRotacao); // Rotaciona
	glm::mat4 TranslationToObjectBack = glm::translate(I, CentroDoObjeto); // Translada o ponto de volta para seu lugar original

	glm::mat4 Transformation = TranslationToObjectBack * Rotation * TranslationToObjectOrigin;

	NaveUp = Transformation * NaveUp;

	for (auto& triangulo : Objeto) {
		for (auto& vertex : triangulo) {
			vertex.Position = Transformation * vertex.Position;
		}
	}
}


void TranslationMatrixAlien(std::array<std::array<Vertex, 3>, 18>& Objeto, glm::vec4& CentroObjeto,  glm::vec3 T) {
	glm::mat4 I = glm::identity<glm::mat4>();
	glm::mat4 Translation = glm::translate(I, T); // Translation translada qualquer ponto em 10 no x, 10 no y e 10 no z

	// Translada o centro do objeto
	CentroObjeto = Translation * CentroObjeto;

	// Translada o restante dos vertices
	for (auto& triangulo : Objeto) {
		for (auto& vertex : triangulo) {
			vertex.Position = Translation * vertex.Position;
		}
	}
}

void TranslationMatrixNave(std::array<std::array<Vertex, 3>, 7>& Objeto, glm::vec4& CentroObjeto, glm::vec3 T) {
	glm::mat4 I = glm::identity<glm::mat4>();
	glm::mat4 Translation = glm::translate(I, T); // Translation translada qualquer ponto em 10 no x, 10 no y e 10 no z

	// Translada o centro do objeto
	CentroObjeto = Translation * CentroObjeto;

	// Translada o restante dos vertices
	for (auto& triangulo : Objeto) {
		for (auto& vertex : triangulo) {
			vertex.Position = Translation * vertex.Position;
		}
	}
}

void TranslationMatrixMissil(std::array<std::array<Vertex, 3>, 4>& Objeto, glm::vec4& CentroObjeto, glm::vec3 T) {
	glm::mat4 I = glm::identity<glm::mat4>();
	glm::mat4 Translation = glm::translate(I, T); // Translation translada qualquer ponto em 10 no x, 10 no y e 10 no z

	// Translada o centro do objeto
	CentroObjeto = Translation * CentroObjeto;

	// Translada o restante dos vertices
	for (auto& triangulo : Objeto) {
		for (auto& vertex : triangulo) {
			vertex.Position = Translation * vertex.Position;
		}
	}
}