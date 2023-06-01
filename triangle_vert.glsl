#version 330 core

layout (location = 0) in vec4 InPosition;
layout (location = 1) in vec4 InColor;
layout (location = 2) in vec2 InUV;

uniform mat4 ModelViewProjection;

out vec4 Color;
out vec2 UV;

void main(){
	Color = InColor;
	UV = InUV;
	gl_Position = ModelViewProjection * InPosition;
}