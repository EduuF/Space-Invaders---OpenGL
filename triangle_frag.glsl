#version 330 core


in vec4 Color;
in vec2 UV;

out vec4 OutColor;

void main(){
	OutColor = Color;
	//OutColor = vec4(UV,0.0f, 1.0f);
}

