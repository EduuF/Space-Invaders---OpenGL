#include "Matrices.h"

#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <array>

// Leva o triangulo para o centro do objeto, escala e volta para a posicao original
// Isso evita que ao fazer a escala o objeto se aproxime ou afaste da origem do plano original
void ScaleMatrix(std::array<glm::vec4, 3>& Triangle, glm::vec3 FatorDeEscala, glm::vec4 &Centro) {
	glm::vec3 OrigemDoObjeto{ Centro.x, Centro.y, Centro.z };
	glm::mat4 I = glm::identity<glm::mat4>();
	glm::mat4 TranslationToObjectOrigin = glm::translate(I, -OrigemDoObjeto); // Translada Centro para o Origem do ambiente
	glm::mat4 Scale = glm::scale(I, FatorDeEscala); // Faz escala
	glm::mat4 TranslationToObjectBack = glm::translate(I, OrigemDoObjeto); // Translada o ponto de volta para seu lugar original
	// Composição de transformações
	glm::mat4 Transformation = TranslationToObjectBack * Scale * TranslationToObjectOrigin;


	for (int i = 0; i < 3; i++) {
		Triangle[i] = Transformation * Triangle[i];
	}
}

void RotationMatrixAlien(std::array<std::array<glm::vec4, 3>, 18>& Objeto, float graus, glm::vec4& Centro) {

	glm::vec3 eixoDeRotacao{ 0.0f, 0.0f, 1.0f };
	glm::mat4 I = glm::identity<glm::mat4>();
	float Angle = glm::radians(graus);

	glm::vec3 CentroDoObjeto{ Centro.x, Centro.y, Centro.z };
	glm::mat4 TranslationToObjectOrigin = glm::translate(I, -CentroDoObjeto); // Translada o triangulo para a origem do objeto
	glm::mat4 Rotation = glm::rotate(I, Angle, eixoDeRotacao); // Rotaciona
	glm::mat4 TranslationToObjectBack = glm::translate(I, CentroDoObjeto); // Translada o ponto de volta para seu lugar original

	glm::mat4 Transformation = TranslationToObjectBack * Rotation * TranslationToObjectOrigin;

	for (int i = 0; i < 18; i++) {
		for (int j = 0; j < 3; j++) {
			Objeto[i][j] = Transformation * Objeto[i][j];
		}
	}
}

void RotationMatrixNave(std::array<std::array<glm::vec4, 3>, 7>& Objeto, float graus, glm::vec4& Centro) {

	glm::vec3 eixoDeRotacao{ 0.0f, 0.0f, 1.0f };
	glm::mat4 I = glm::identity<glm::mat4>();
	float Angle = glm::radians(graus);

	glm::vec3 CentroDoObjeto{ Centro.x, Centro.y, Centro.z };
	glm::mat4 TranslationToObjectOrigin = glm::translate(I, -CentroDoObjeto); // Translada o triangulo para a origem do objeto
	glm::mat4 Rotation = glm::rotate(I, Angle, eixoDeRotacao); // Rotaciona
	glm::mat4 TranslationToObjectBack = glm::translate(I, CentroDoObjeto); // Translada o ponto de volta para seu lugar original

	glm::mat4 Transformation = TranslationToObjectBack * Rotation * TranslationToObjectOrigin;

	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 3; j++) {
			Objeto[i][j] = Transformation * Objeto[i][j];
		}
	}
}


void TranslationMatrixAlien(std::array<std::array<glm::vec4, 3>, 18>& Objeto, glm::vec4& CentroObjeto,  glm::vec3 T) {
	glm::mat4 I = glm::identity<glm::mat4>();
	glm::mat4 Translation = glm::translate(I, T); // Translation translada qualquer ponto em 10 no x, 10 no y e 10 no z

	// Translada o centro do objeto
	CentroObjeto = Translation * CentroObjeto;

	// Translada o restante dos vertices
	for (auto& triangulo : Objeto) {
		for (auto& vertice : triangulo) {
			vertice = Translation * vertice;
		}
	}
}

void TranslationMatrixNave(std::array<std::array<glm::vec4, 3>, 7>& Objeto, glm::vec4& CentroObjeto, glm::vec3 T) {
	glm::mat4 I = glm::identity<glm::mat4>();
	glm::mat4 Translation = glm::translate(I, T); // Translation translada qualquer ponto em 10 no x, 10 no y e 10 no z

	// Translada o centro do objeto
	CentroObjeto = Translation * CentroObjeto;

	// Translada o restante dos vertices
	for (auto& triangulo : Objeto) {
		for (auto& vertice : triangulo) {
			vertice = Translation * vertice;
		}
	}
}

void ModelViewProjectionAlien(std::array<std::array<glm::vec4, 3>, 18>& Objeto, float AspectRatio, glm::vec3 Eye, glm::vec3 Center, glm::vec3 Up, float FoVAngle) {
	// Model vai ser a matriz formada pelas transformações de translação,
	// rotação e escala. Uma matriz composta
	glm::mat4 ModelMatrix = glm::identity<glm::mat4>();

	//View
	//glm::vec3 Eye{ 0,0,10 };
	//glm::vec3 Center{ 0,0,0 };
	//glm::vec3 Up{ 0, 1, 0 };
	glm::mat4 ViewMatrix = glm::lookAt(Eye, Center, Up);

	float FoV = glm::radians(FoVAngle);
	//float AspectRatio = 800.0f / 800.0f;
	float Near = 0.001f;
	float Far = 1000.0f;
	glm::mat4 Projection = glm::perspective(FoV, AspectRatio, Near, Far);

	glm::mat4 ModelViewProjection = Projection * ViewMatrix * ModelMatrix;

	for(auto& triangulo: Objeto){
		for (auto& vertice : triangulo) {
			vertice = ModelViewProjection * vertice;
			vertice = vertice / vertice.w;
		}
	}
};


void ModelViewProjectionNave(std::array<std::array<glm::vec4, 3>, 7>& Objeto, float AspectRatio, glm::vec3 Eye, glm::vec3 Center, glm::vec3 Up, float FoVAngle) {
	// Model vai ser a matriz formada pelas transformações de translação,
	// rotação e escala. Uma matriz composta
	glm::mat4 ModelMatrix = glm::identity<glm::mat4>();

	//View
	//glm::vec3 Eye{ 0,0,10 };
	//glm::vec3 Center{ 0,0,0 };
	//glm::vec3 Up{ 0, 1, 0 };
	glm::mat4 ViewMatrix = glm::lookAt(Eye, Center, Up);

	float FoV = glm::radians(FoVAngle);
	//float AspectRatio = 800.0f / 800.0f;
	float Near = 0.001f;
	float Far = 1000.0f;
	glm::mat4 Projection = glm::perspective(FoV, AspectRatio, Near, Far);

	glm::mat4 ModelViewProjection = Projection * ViewMatrix * ModelMatrix;

	for (auto& triangulo : Objeto) {
		for (auto& vertice : triangulo) {
			vertice = ModelViewProjection * vertice;
			vertice = vertice / vertice.w;
		}
	}
};