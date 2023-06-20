#ifndef FLYCAMERA_H
#define FLYCAMERA_H

#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>

class FlyCamera {
public:

	int Width;
	int Height;
	float Speed;

	// Defini��o da Matriz de View
	glm::vec3 Location{ 0.0f, 0.0f, 5.0f };
	glm::vec3 Direction{ 0.0f, 0.0f, -1.0f };
	glm::vec3 Up{ 0.0f, 1.0f, 0.0f };

	// Constructor
	FlyCamera(int Width, int Height, float Speed);

	// Defini��o da Matriz Projection
	float FieldOfView;
	float AspectRatio;
	float Near;
	float Far;

	void MoveFoward(float Amount);
	void MoveRight(float Amount);
	glm::mat4 GetViewProjection() const;

	
};

#endif