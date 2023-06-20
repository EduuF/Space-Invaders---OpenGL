#version 330 core

// Outputs colors in RGBA
out vec4 FragColor;

// Imports the color from the Vertex Shader
in vec4 color;
// Imports the texture coordinates to the Fragment Shader
in vec2 texCoord;
// Imports the normal from the Vertex Shader
in vec4 Normal;
// Imports the current position from the Vertex Shader
in vec4 crntPos;

// Gets the color of the light from the main function
uniform vec4 lightColor;
// Gets the position of the light from the main function
uniform vec4 lightPos;
// Gets the position of the camera from the main function
uniform vec4 camPos;

void main()
{
	// ambient lighting
	float ambient = 0.7f;

	// diffuse lighting
	vec4 normal = normalize(Normal);
	vec4 lightDirection = normalize(lightPos - crntPos);
	float diffuse = dot(normal, lightDirection);

	// specular lighting
	float specularLight = 0.5f;
	vec4 viewDirection = normalize(camPos - crntPos);
	vec4 reflectionDirection = reflect(-lightDirection, normal);
	float specAmount = pow(max(dot(viewDirection, reflectionDirection), 0.0f), 8);
	float specular = specAmount * specularLight;

	// outputs final color
	FragColor = color + (lightColor * (diffuse + ambient + specular));
}