#version 330 core

layout (location = 0) in vec4 InPosition;
layout (location = 1) in vec4 InColor;

uniform mat4 ModelViewProjection;

out vec4 Color;

void main(){
	Color = InColor;

	gl_Position = ModelViewProjection * InPosition;
}