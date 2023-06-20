#version 330 core

layout (location = 0) in vec4 aPos;

// Import ModelViewProjection
uniform mat4 ModelViewProjection;

void main()
{
	gl_Position = ModelViewProjection * aPos;
}