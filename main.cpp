#include "Vectors.h"
#include "Nave.h"
#include "Alien.h"

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <array>



const int Width = 800;
const int Height = 800;


int main() {


	// Inicializa GLFW
	glfwInit();

	// Criar uma janela
	GLFWwindow* Window = glfwCreateWindow(Width, Height, "Space Invaders - CG 2023/1 - Aluno: Eduardo Fiuza - Professor: Renato Ferreira", nullptr, nullptr);

	// Torna a janela a atual para renderização OpenGL
	glfwMakeContextCurrent(Window);

	// Inicializa o GLEW (Depois da criação da janela)
	glewInit();

	// Verificar a versão do OpenGL que estamos usando
	GLint GLMajorVersion = 0; // Declara GLMajorVersion
	GLint GLMinorVersion = 0; // Declara GLMinorVersion
	glGetIntegerv(GL_MAJOR_VERSION, &GLMajorVersion); // GL_MAJOR_VERSION -> GLMajorVersion
	glGetIntegerv(GL_MINOR_VERSION, &GLMinorVersion); // GL_MINOR_VERSION -> GLMinorVersion
	std::cout << "OpenGL Version: " << GLMajorVersion << "." << GLMinorVersion << std::endl; // Imprime a versão no format 4.6

	// Usar o glGetString() para obter informações do driver que estamos usando
	std::cout << "OpenGL Vendor: " << glGetString(GL_VENDOR) << std::endl; // Imprime no format NVIDIA
	std::cout << "OpenGL Renderer: " << glGetString(GL_RENDERER) << std::endl; // Diz qual placa gráfica está instalada
	std::cout << "OpenGL Version: " << glGetString(GL_VERSION) << std::endl; // Diz qual é a versão em formato string completo
	std::cout << "GLSL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl; // Versão dos shaders

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

	// Cria uma nave
	Nave nave1 = Nave(glm::vec4{0.0f, 0.0f, 0.0f, 1.0f}); // A quarta dimensão deve ser 1.0f pois é um ponto
	glm::vec3 fatorDeEscalaNave{ 1.0f, 3.0f, 0.0f };
	nave1.ajustaEscalaDaNave(fatorDeEscalaNave);
	glm::vec3 fatorDeTranslacaoNave{ -0.5f, -0.5f, 0.0f };
	nave1.transladaANave(fatorDeTranslacaoNave);
	float angleRotacaoNave = -30;
	nave1.rotacionaANave(angleRotacaoNave);

	// Cria inimigos
	std::array<Alien, 3> TodosAliens;
	for (int i = 0; i < 3; i++) {
		TodosAliens[i] = Alien(glm::vec4{ -1.0f + ((i+1) * 0.5f), 0.8f, 0.0f, 1.0f });
	}
	//alien1.modelaAlien();
	//glm::vec3 fatorDeEscalaAlien{ 0.3f, 0.5f, 0.0f };
	//alien1.ajustaEscalaDoAlien(fatorDeEscalaAlien);
	//glm::vec3 fatorDeTranslacaoAlien{ 0.8,0.4,0.0 };
	//alien1.transladaOAlien(fatorDeTranslacaoAlien);
	//float angleRotacaoAlien = 45;
	//glm::vec3 eixoDeRotacaoAlien{ 0,0,1 };
	//alien1.rotacionaOAlien(angleRotacaoAlien, eixoDeRotacaoAlien);
	

	// Copiar os vértices do triangulo para a memória da GPU
	GLuint VertexBuffer;

	// Pedir para o OpenGL gerar o identificador do VertexBuffer
	glGenBuffers(1, &VertexBuffer);

	// Ativar o VertexBuffer como sendo o Buffer para onde vamos copiar os dados do triangulo
	glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);

	// Copiar os dados dos triangulos para a memória de vídeo
	// Carregue os dados de todos os triângulos no buffer da GPU.
	// (Buffer ativado, quantos bytes serão copiados, ponteiro para os dados, tipo de uso do buffer)
	const int tamanhoDaNave = 7; // A quantidade de triangulos na nave
	const int tamanhoDoAlien = 18; // A quantidade de triangulos do Alien

	std::array<std::array<glm::vec4, 3>, tamanhoDaNave+tamanhoDoAlien*3> bufferData; // Cria um vetor de triangulos
	std::copy(nave1.modeloDaNave.begin(), nave1.modeloDaNave.end(), bufferData.begin()); // Copia todos os triangulos da nave para o bufferData
	int i = 1;
	for (int i = 0; i < 3; i++) {
		std::copy(TodosAliens[i].modeloDoInimigo.begin(), TodosAliens[i].modeloDoInimigo.end(), bufferData.begin() + tamanhoDaNave + (i * tamanhoDoAlien)); // Copia todos os triangulos do Alien para o bufferData
	}
	
	// Copiar os dados dos triângulos para a memória de vídeo
	// Carregue os dados de todos os triângulos no buffer da GPU.
	// (Buffer ativado, quantos bytes serão copiados, ponteiro para os dados, tipo de uso do buffer)
	glBufferData(GL_ARRAY_BUFFER, sizeof(bufferData), bufferData.data(), GL_STATIC_DRAW);

	// Definir cor de fundo da janela
	glClearColor(0.01f, 0.0f, 0.06f, 1.0f); // Azul escuro

	//TESTE
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	// Loop de eventos da aplicação
	while (!glfwWindowShouldClose(Window)){

		// Limpa o framebuffer. GL_COLOR_BUFFER_BIT limpa o buffer de cor e preenche com a cor definida em "glClearColor"
		// Para desenharmos objetos 3D na tela teremos que voltar ao glClear para limparmos o buffer de profundidade
		glClear(GL_COLOR_BUFFER_BIT);

		
		glEnableVertexAttribArray(0);

		// Diz ao OpenGL que o VertexBuffer vai ser o buffer ativo no momento
		glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);

		// Informa ao OpenGL onde, dentro do vertexBuffer, os vértices estão. 
		// No caso o array Triangles é contíguo na memória, então basta dizer quantos vértices vamos usar para desenhar o triangulo
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, nullptr); // 4 = cada vértice é representado por 4 valores de ponto flutuante

		// Desenha a nave
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glDrawArrays(GL_TRIANGLES, 0, (tamanhoDaNave - 2) * 3);

		// Desenha a Bouding Box
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glDrawArrays(GL_TRIANGLES, (tamanhoDaNave - 2) * 3, 6);

		for (int i = 0; i < TodosAliens.size(); i++) {
			// Desenha os inimigos
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glDrawArrays(GL_TRIANGLES, ((tamanhoDaNave) * 3) + ((tamanhoDoAlien) * 3 * i) , ((tamanhoDoAlien - 2) * 3));

			// Desenha Bouding Box dos inimigos
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			glDrawArrays(GL_TRIANGLES, (tamanhoDaNave + (tamanhoDoAlien * (i+1)) - 2) * 3, 6);
		}

		// Reverte o estado que nós criamos
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glDisableVertexAttribArray(0);

		// Processa todos os eventos na fila de eventos do GLFW
		// Eventos: Teclado, mouse, gamepad
		glfwPollEvents();

		// Envia o conteúdo do framebuffer da janela para ser desenhado na tela
		glfwSwapBuffers(Window);
	}

	// Desalocar o VertexBuffer
	glDeleteBuffers(1, &VertexBuffer);

	// Encerra GLFW
	glfwTerminate();

	return 0;
}