#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

const int Width = 800;
const int Height = 600;


int main() {


	// Inicializa GLFW
	if (glfwInit() == GLFW_FALSE) {
		std::cout << "O GLFW não foi inicializado como o esperado";
		return 0;
	}

	// Criar uma janela
	GLFWwindow* Window = glfwCreateWindow(Width, Height, "Space Invaders - CG 2023/1 - Eduardo Fiuza", nullptr, nullptr);

	// Loop de eventos da aplicação
	while (!glfwWindowShouldClose(Window)) 
	{
		// Processa todos os eventos na fila de eventos do GLFW
		// Eventos: Teclado, mouse, gamepad
		glfwPollEvents();

		// Envia o conteúdo do framebuffer da janela para ser desenhado na tela
		glfwSwapBuffers(Window);
	}



	// Encerra GLFW
	glfwTerminate();

	return 0;
}