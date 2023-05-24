#include "Vectors.h"

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <array>



const int Width = 800;
const int Height = 600;


int main() {


	// Inicializa GLFW
	glfwInit();

	// Criar uma janela
	GLFWwindow* Window = glfwCreateWindow(Width, Height, "Space Invaders - CG 2023/1 - Aluno: Eduardo Fiuza - Professor: Renato Ferreira", nullptr, nullptr);

	// Torna a janela a atual para renderiza��o OpenGL
	glfwMakeContextCurrent(Window);

	// Inicializa o GLEW (Depois da cria��o da janela)
	glewInit();

	// Verificar a vers�o do OpenGL que estamos usando
	GLint GLMajorVersion = 0; // Declara GLMajorVersion
	GLint GLMinorVersion = 0; // Declara GLMinorVersion
	glGetIntegerv(GL_MAJOR_VERSION, &GLMajorVersion); // GL_MAJOR_VERSION -> GLMajorVersion
	glGetIntegerv(GL_MINOR_VERSION, &GLMinorVersion); // GL_MINOR_VERSION -> GLMinorVersion
	std::cout << "OpenGL Version: " << GLMajorVersion << "." << GLMinorVersion << std::endl; // Imprime a vers�o no format 4.6

	// Usar o glGetString() para obter informa��es do driver que estamos usando
	std::cout << "OpenGL Vendor: " << glGetString(GL_VENDOR) << std::endl; // Imprime no format NVIDIA
	std::cout << "OpenGL Renderer: " << glGetString(GL_RENDERER) << std::endl; // Diz qual placa gr�fica est� instalada
	std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl; // Diz qual � a vers�o em formato string completo
	std::cout << "GLSL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl; // Vers�o dos shaders

	// Testa componentes
	Constructors();
	Components();
	Swizzle();
	Operations();

	// Definir um triangulo em coordenadas normalizadas
	std::array<glm::vec3, 3> Triangle = {
		glm::vec3{-1.0f, -1.0f, 0.0f},
		glm::vec3{ 1.0f, -1.0f, 0.0f},
		glm::vec3{ 0.0f,  1.0f, 0.0f}
	};

	// Copiar os v�rtices do triangulo para a mem�ria da GPU
	GLuint VertexBuffer;

	// Pedir para o OpenGL gerar o identificador do VertexBuffer
	glGenBuffers(1, &VertexBuffer);

	// Ativar o VertexBuffer como sendo o Buffer para onde vamos copiar os dados do triangulo
	glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);

	// Copiar os dados do trianuglo para a mem�ria de v�deo
	glBufferData(GL_ARRAY_BUFFER, sizeof(Triangle), Triangle.data(), GL_STATIC_DRAW); // (Buffer ativado, quantos bytes ser�o copiados, ponteiro para os dados, tipo de uso do buffer)

	// Definir cor de fundo da janela
	glClearColor(0.01f, 0.0f, 0.06f, 1.0f); // Azul escuro

	// Loop de eventos da aplica��o
	while (!glfwWindowShouldClose(Window)){

		// Limpa o framebuffer. GL_COLOR_BUFFER_BIT limpa o buffer de cor e preenche com a cor definida em "glClearColor"
		// Para desenharmos objetos 3D na tela teremos que voltar ao glClear para limparmos o buffer de profundidade
		glClear(GL_COLOR_BUFFER_BIT);

		
		glEnableVertexAttribArray(0);

		// Diz ao OpenGL que o VertexBuffer vai ser o buffer ativo no momento
		glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);

		// Informa ao OpenGL onde, dentro do vertexBuffer, os v�rtices est�o. 
		// No caso o array Triangles � cont�guo na mem�ria, ent�o basta dizer quantos v�rtices vamos usar para desenhar o triangulo
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

		// Desenha na tela
		glDrawArrays(GL_TRIANGLES, 0, 3);

		// Reverte o estado que n�s criamos
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glDisableVertexAttribArray(0);

		// Processa todos os eventos na fila de eventos do GLFW
		// Eventos: Teclado, mouse, gamepad
		glfwPollEvents();

		// Envia o conte�do do framebuffer da janela para ser desenhado na tela
		glfwSwapBuffers(Window);
	}

	// Desalocar o VertexBuffer
	glDeleteBuffers(1, &VertexBuffer);

	// Encerra GLFW
	glfwTerminate();

	return 0;
}