#ifndef FLYCAMERA_H
#define FLYCAMERA_H

#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>

class FlyCamera {
public:

	int Width;
	int Height;
	float Speed;

	// Definição da Matriz de View
	glm::vec4 Location;
	glm::vec4 Direction;
	glm::vec4 Up;

	// Constructor
	FlyCamera(int Width, int Height, float Speed);

	// Definição da Matriz Projection
	float FieldOfView;
	float AspectRatio;
	float Near;
	float Far;

	void MoveFoward(float Amount);
	void MoveRight(float Amount);
	glm::mat4 GetViewProjection() const;

	
};

#endif