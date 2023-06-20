#include "FlyCamera.h"

FlyCamera::FlyCamera(int Width, int Height, float Speed) {
	this->Width = Width;
	this->Height = Height;
	this->Speed = Speed;

	// Definição da Matriz de View
	this->Location = glm::vec4 { 0.0f, 0.0f, 5.0f, 1.0f };
	this->Direction = glm::vec4{ 0.0f, 0.0f, -1.0f, 0.0f };
	this->Up = glm::vec4 { 0.0f, 1.0f, 0.0f, 0.0f };

	// Definição da Matriz Projection
	this->FieldOfView = glm::radians(45.0f);
	this->AspectRatio = Width / Height;
	this->Near = 0.01f;
	this->Far = 1000.0f;
}

void FlyCamera::MoveFoward(float Amount) {
	Location += glm::normalize(Direction) * Amount * Speed;
}

void FlyCamera::MoveRight(float Amount) {
	glm::vec3 Right = glm::normalize(glm::cross(glm::vec3(Direction), glm::vec3(Up)));
	Location += glm::vec4(Right * Amount * Speed, 0.0f);
}

glm::mat4 FlyCamera::GetViewProjection() const {
	glm::mat4 View = glm::lookAt(glm::vec3(Location), glm::vec3(Location + Direction), glm::vec3(Up));
	glm::mat4 Projection = glm::perspective(FieldOfView, AspectRatio, Near, Far);
	return Projection * View;
}