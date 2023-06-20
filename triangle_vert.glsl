#version 330 core

// Positions/Coordinates
layout (location = 0) in vec4 aPos;
// Colors
layout (location = 1) in vec4 aColor;
// Texture Coordinates
layout (location = 2) in vec2 aTex;
// Normals (not necessarily normalized)
layout (location = 3) in vec4 aNormal;


// Outputs the color for the Fragment Shader
out vec4 color;
// Outputs the texture coordinates to the Fragment Shader
out vec2 texCoord;
// Outputs the normal for the Fragment Shader
out vec4 Normal;
// Outputs the current position for the Fragment Shader
out vec4 crntPos;

// Import ModelViewProjection
uniform mat4 ModelViewProjection;

void main()
{
	// Outputs the positions/coordinates of all vertices
	gl_Position = ModelViewProjection * aPos;

	// calculates current position
	crntPos = gl_Position;

	// Assigns the colors from the Vertex Data to "color"
	color = aColor;
	// Assigns the texture coordinates from the Vertex Data to "texCoord"
	texCoord = aTex;
	// Assigns the normal from the Vertex Data to "Normal"
	Normal = aNormal;
}