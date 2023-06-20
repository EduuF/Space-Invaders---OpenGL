#include "Vectors.h"
#include "Nave.h"
#include "Alien.h"
#include "Matrices.h"
#include "Triangle.h"
#include "Missil.h"
#include "GameState.h"
#include "PowerUp.h"
#include "Stars.h"
#include "Life.h"
#include "Smoke.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "FlyCamera.h"
#include "Cube.h"


#include <iostream>
#include <fstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stdlib.h> 

#include <random>
#include <vector>

const int Width = 1280;
const int Height = 1280;
const float Sensitivity = 0.1f;
const float Speed = 1.0f;

std::string ReadFile(const char* FilePath) {

	std::string FileContents;
	if (std::ifstream FileStream{ FilePath, std::ios::in }) {
		// Vai ler dentro do FileContets o conte�do do arquivo apontado por FilePath
		FileContents.assign(std::istreambuf_iterator<char>(FileStream), std::istreambuf_iterator<char>());
	}
	return FileContents;
}

void CheckShader(GLuint ShaderId) {
	// ShaderId tem que ser um identificador de um Shader j� compilado

	GLint Result = GL_TRUE;
	glGetShaderiv(ShaderId, GL_COMPILE_STATUS, &Result);

	if (Result == GL_FALSE) {
		// Houve erro ao compilar o shader, imprime o log do shader para saber qual foi o erro

		//Obter o tamanho do log
		GLint InfoLogLength = 0;
		glGetShaderiv(ShaderId, GL_INFO_LOG_LENGTH, &InfoLogLength);

		// Se o log existir
		if (InfoLogLength > 0) {
			std::string ShaderInfoLog(InfoLogLength, '\0');
			glGetShaderInfoLog(ShaderId, InfoLogLength, nullptr, &ShaderInfoLog[0]);

			std::cout << "Erro no Shader: " << std::endl;
			std::cout << ShaderInfoLog << std::endl;
		}
	}
}

GLuint LoadShaders(const char* VertexShaderFile, const char* FragmnetShaderFile) {

	// Ler o conte�do dos arquivos de shaders
	std::string VertexShaderSource = ReadFile(VertexShaderFile);
	std::string FragmentShaderSource = ReadFile(FragmnetShaderFile);

	// Criar os identificadores do Vertex e Fragment Shaders
	GLuint VertexShaderId = glCreateShader(GL_VERTEX_SHADER);
	GLuint FragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);

	// Compilando os arquivos de Shaders
	const char* VertexShaderSourcePtr = VertexShaderSource.c_str();
	glShaderSource(VertexShaderId, 1, &VertexShaderSourcePtr, nullptr); // Podem haver mais de 1 shaders
	glCompileShader(VertexShaderId);

	// Verificar se a compila��o do VertexShader deu certo
	CheckShader(VertexShaderId);

	// Compilando os arquivos de Shaders
	const char* FragmentShaderSourcePtr = FragmentShaderSource.c_str();
	glShaderSource(FragmentShaderId, 1, &FragmentShaderSourcePtr, nullptr); // Podem haver mais de 1 shaders
	glCompileShader(FragmentShaderId);

	// Verificar se a compila��o do FragmentShader deu certo
	CheckShader(FragmentShaderId);

	// Associando os shaders ao programa
	std::cout << "Linkando o programa" << std::endl;

	GLuint ProgramId = glCreateProgram();
	glAttachShader(ProgramId, VertexShaderId);
	glAttachShader(ProgramId, FragmentShaderId);

	glLinkProgram(ProgramId);

	// Verificar o programa
	GLint Result = GL_TRUE;
	glGetProgramiv(ProgramId, GL_LINK_STATUS, &Result);

	if (Result == GL_FALSE) {
		// Pega o log para saber o problema
		

		GLint InfoLogLength = 0;
		glGetProgramiv(ProgramId, GL_INFO_LOG_LENGTH, &InfoLogLength);

		if (InfoLogLength > 0) {
			std::string ProgramInfoLog(InfoLogLength, '\0');
			glGetShaderInfoLog(ProgramId, InfoLogLength, nullptr, &ProgramInfoLog[0]);

			std::cout << "Erro ao linkar o programa" << std::endl;
			std::cout << ProgramInfoLog << std::endl;
		}
	}

	// Desacopla e deleta os shaders pois j� est�o carregados
	glDetachShader(ProgramId, VertexShaderId);
	glDetachShader(ProgramId, FragmentShaderId);

	glDeleteShader(VertexShaderId);
	glDeleteShader(FragmentShaderId);

	return ProgramId;
}


// Declara um objeto camera globalmente
FlyCamera Camera = FlyCamera(Width, Height, Speed);
//bool bEnableMouseMovement = false;
glm::vec2 PreviousCursor(0.0, 0.0);

void MouseButtonCallback(GLFWwindow* Window, int Button, int Action, int Modifiers) {
	std::cout << "Button: " << Button << " Action: " << Action << " Modifiers: " << Modifiers << std::endl;

	/*
	if (Button == GLFW_MOUSE_BUTTON_LEFT) {
		if (Action == GLFW_PRESS) {

			double X, Y;
			glfwGetCursorPos(Window, &X, &Y);
			PreviousCursor = glm::vec2{ X, Y };
			bEnableMouseMovement = true;
		}
		if (Action == GLFW_RELEASE) {
			bEnableMouseMovement = false;
		}
	}
	*/

	if (Button == GLFW_MOUSE_BUTTON_LEFT) {
		if (Action == GLFW_PRESS) {

			double X, Y;
			glfwGetCursorPos(Window, &X, &Y);
			PreviousCursor = glm::vec2{ X, Y };
		}
		if (Action == GLFW_RELEASE) {
		}
	}
}

void MouseMotionCallback(GLFWwindow* Window, double X, double Y) {
	/*
	if (bEnableMouseMovement) {
		glm::vec2 CurrentCursor(X, Y);
		glm::vec2 DeltaCursor = CurrentCursor - PreviousCursor;

		PreviousCursor = CurrentCursor;
		std::cout << "DeltaCursor: " << glm::to_string(DeltaCursor) << std::endl;
	}
	*/
	glm::vec2 CurrentCursor(X, Y);

	PreviousCursor = CurrentCursor;
	//std::cout << "X: " << X << " Y: " << Y << std::endl;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

int main() {
	int fase = 0;
	while (true) {
		fase++;
		std::cout << fase << std::endl;
		// GameState
		GameState gameState = GameState();
		gameState.CadenciaDeTirosNave += 0.1f * fase;
		gameState.NumeroDeLinhasDeInimigos += 1 * fase;
		gameState.velocidadeDosAlien += 0.01f * fase;
		gameState.TempoParaBombaExplodirBombaDropada -= 1 * fase;
		gameState.VelocidadeDoTiroAlien += 0.2f * fase;

		// Inicializa GLFW
		glfwInit();

		// Criar uma janela
		GLFWwindow* Window = glfwCreateWindow(Width, Height, "Space Invaders - CG 2023/1 - Aluno: Eduardo Fiuza - Professor: Renato Ferreira", nullptr, nullptr);

		// Cria o Viewport
		//glViewport(0, 0, Width, Height);

		// Ajusta o Viewport dependendo se o usu�rio aumentou ou diminui a tela
		//glfwSetFramebufferSizeCallback(Window, framebuffer_size_callback);

		// Cadastrar as callbacks no GLFW
		glfwSetMouseButtonCallback(Window, MouseButtonCallback);
		glfwSetCursorPosCallback(Window, MouseMotionCallback);

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

		// Carrega os Shaders
		GLuint ProgramId = LoadShaders("triangle_vert.glsl", "triangle_frag.glsl");

		// Carrega LightShader
		GLuint LightShaderId = LoadShaders("light_vert.glsl", "light_frag.glsl");

		// Cria uma nave
		Nave nave1 = Nave(glm::vec4{ 0.0f, -1.7f, 0.0f, 1.0f }); // A quarta dimens�o deve ser 1.0f pois � um ponto
		glm::vec3 fatorDeEscalaNave{ 1.5f, 3.0f, 0.0f };
		nave1.ajustaEscalaDaNave(fatorDeEscalaNave);

		// Cria inimigos
		const GLuint NumeroTotalDeInimigos = gameState.NumeroDeLinhasDeInimigos * gameState.NumeroDeColunasDeInimigos;
		const float LarguraAlien = 0.20f;
		const float LarguraIntervalo = 0.15f;
		const float LarguraJanela = (LarguraAlien * gameState.NumeroDeColunasDeInimigos) + (LarguraIntervalo * (gameState.NumeroDeColunasDeInimigos - 1));
		const float WidthGap = ((4 - LarguraJanela) / 2) - 2;

		std::vector<Alien> TodosAliens;
		for (int i = 0; i < NumeroTotalDeInimigos; i++) {
			GLuint linha = i / gameState.NumeroDeColunasDeInimigos;
			GLuint coluna = i % gameState.NumeroDeColunasDeInimigos;
			TodosAliens.push_back(Alien(glm::vec4{ WidthGap + (coluna * LarguraIntervalo) + (coluna * LarguraAlien), 1.8f - (linha * 0.3),  0.0f, 1.0f }));
			TodosAliens[i].yOriginal = 1.8f - (linha * 0.3);
		}


		glm::vec3 fatorDeTranslacaoAlien{ 0.8,0.4,0.0 };
		glm::vec3 fatorDeEscalaAlien{ 0.7f, 1.0f, 0.0f };
		for (int i = 0; i < TodosAliens.size(); i++) {
			TodosAliens[i].ajustaEscalaDoAlien(fatorDeEscalaAlien);
		}

		std::vector<Missil> TodosMisseis;
		std::vector<PowerUp> TodosPowerUp;
		std::vector<Stars> TodasStars;
		std::vector<Life> TodasLifes;
		std::vector<Smoke> TodasSmokes;

		// Cria um LightCube
		glm::vec4 LightCubeColor{ 1.0f, 1.0f, 1.0f, 1.0f };
		glm::vec4 LightCubePosition{ -1.5f, -1.0f, 2.0f, 1.0f };
		Cube LightCube = Cube(LightCubePosition, LightCubeColor);

		// Cria as lifes
		// Verifica o Life para desenhar os cora��es
		for (int i = 0; i < nave1.life; i++) {
			glm::vec4 PosicaoDaLife{ -1.9f + (i * 0.2f), -1.9f, 0.0f, 1.0f };
			Life life(PosicaoDaLife);
			TodasLifes.push_back(life);
		}

		glClearColor(0.07f, 0.03f, 0.10f, 1.0f); // Definir cor de fundo da janela

		double PreviousTime = glfwGetTime();	// Guarda o tempo do frame anterior
		float ContadorDeDelayDeTiros = 0.0f;// Contador de delay de tiros

		// Rendeiza apenas a face da frente
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);

		glEnable(GL_DEPTH_TEST);


		// Loop de eventos da aplica��o
		while (!glfwWindowShouldClose(Window)) {

			// Limpa o framebuffer. GL_COLOR_BUFFER_BIT limpa o buffer de cor e preenche com a cor definida em "glClearColor"
			// Para desenharmos objetos 3D na tela teremos que voltar ao glClear para limparmos o buffer de profundidade
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			if (gameState.vitoria) {
				break;
			}
			if (gameState.gameOver) {
				fase--;
				break;
			}

			// Habilita objetos transparentes
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


			// Calcula o tempo dos frames
			double CurrentTime = glfwGetTime();
			double DeltaTime = CurrentTime - PreviousTime;

			if (DeltaTime > 0.0) {
				PreviousTime = CurrentTime;
			}

			// RNG do frame
			int rng = gameState.GeraNumeroAleatorio();

			gameState.AlienComABomba = -1;

			std::vector<std::vector<std::vector<Vertex>>> bufferVertices; // Cria um vetor de Vertices
			std::vector<std::vector<std::vector<glm::ivec3>>> bufferIndices; // Cria um vetor de Indices

			std::vector<std::vector<Vertex>> AuxVertices;
			std::vector<std::vector<glm::ivec3>> AuxIndices;

			// Nave
			AuxVertices.push_back(nave1.Vertices);
			AuxIndices.push_back(nave1.Indices);

			bufferVertices.push_back(AuxVertices);
			bufferIndices.push_back(AuxIndices);

			AuxVertices.clear();
			AuxIndices.clear();

			// Aliens
			for (int i = 0; i < TodosAliens.size(); i++) {

				AuxVertices.push_back(TodosAliens[i].Vertices);
				AuxIndices.push_back(TodosAliens[i].Indices);

				if (TodosAliens[i].hasBomb) {
					gameState.AlienComABomba = i;
				}
			}

			bufferVertices.push_back(AuxVertices);
			bufferIndices.push_back(AuxIndices);

			AuxVertices.clear();
			AuxIndices.clear();


			//Misseis
			for (auto& Missil : TodosMisseis) {
				AuxVertices.push_back(Missil.Vertices);
				AuxIndices.push_back(Missil.Indices);
			}

			bufferVertices.push_back(AuxVertices);
			bufferIndices.push_back(AuxIndices);

			AuxVertices.clear();
			AuxIndices.clear();

			// PowerUps
			for (auto& powerUp : TodosPowerUp) {
				AuxVertices.push_back(powerUp.Vertices);
				AuxIndices.push_back(powerUp.Indices);
			}

			bufferVertices.push_back(AuxVertices);
			bufferIndices.push_back(AuxIndices);

			AuxVertices.clear();
			AuxIndices.clear();

			// Estrelas
			for (auto& estrela : TodasStars) {
				AuxVertices.push_back(estrela.Vertices);
				AuxIndices.push_back(estrela.Indices);
			}

			bufferVertices.push_back(AuxVertices);
			bufferIndices.push_back(AuxIndices);

			AuxVertices.clear();
			AuxIndices.clear();

			// Lifes
			for (auto& life : TodasLifes) {
				AuxVertices.push_back(life.Vertices);
				AuxIndices.push_back(life.Indices);
			}

			bufferVertices.push_back(AuxVertices);
			bufferIndices.push_back(AuxIndices);

			AuxVertices.clear();
			AuxIndices.clear();

			// Fuma�as
			for (auto& smoke : TodasSmokes) {
				AuxVertices.push_back(smoke.Vertices);
				AuxIndices.push_back(smoke.Indices);
			}

			bufferVertices.push_back(AuxVertices);
			bufferIndices.push_back(AuxIndices);

			AuxVertices.clear();
			AuxIndices.clear();

			// Se a bomba estiver em game, desenha ela.
			if (gameState.AlienComABomba != -1) {
				AuxVertices.push_back(TodosAliens[gameState.AlienComABomba].bomba.Vertices);
				AuxIndices.push_back(TodosAliens[gameState.AlienComABomba].bomba.Indices);
			}

			bufferVertices.push_back(AuxVertices);
			bufferIndices.push_back(AuxIndices);

			AuxVertices.clear();
			AuxIndices.clear();

			// Light Cube
			AuxVertices.push_back(LightCube.Vertices);
			AuxIndices.push_back(LightCube.Indices);

			bufferVertices.push_back(AuxVertices);
			bufferIndices.push_back(AuxIndices);

			AuxVertices.clear();
			AuxIndices.clear();

			// Generates Vertex Array Object and binds it
			std::vector< std::vector<VAO>> VAOS;
			std::vector< std::vector<VBO>> VBOS;
			std::vector< std::vector<EBO>> EBOS;

			for (int i = 0; i < bufferVertices.size(); i ++) {

				// Adiciona um vetor vazio na posi��o i de VAOS, VBOS e EBOS
				VAOS.push_back(std::vector<VAO>());
				VBOS.push_back(std::vector<VBO>());
				EBOS.push_back(std::vector<EBO>());

				for (int j = 0; j < bufferVertices[i].size(); j++) {

					VAO VAOObject;
					VAOS[i].push_back(VAOObject);
					VAOS[i][j].Bind();

					// Generates Vertex Buffer Object and links it to vertices
					VBO VBOObject(bufferVertices[i][j], bufferVertices[i][j].size() * sizeof(Vertex));
					VBOS[i].push_back(VBOObject);
					// Generates Element Buffer Object and links it to indices
					EBO EBOObject(bufferIndices[i][j], bufferIndices[i][j].size() * sizeof(glm::ivec3));
					EBOS[i].push_back(EBOObject);

					// Links VBO attributes such as coordinates and colors to VAO
					VAOS[i][j].LinkAttrib(VBOS[i][j], 0, 4, GL_FLOAT, false, sizeof(Vertex), nullptr);
					VAOS[i][j].LinkAttrib(VBOS[i][j], 1, 4, GL_FLOAT, true, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, Color)));
					VAOS[i][j].LinkAttrib(VBOS[i][j], 2, 2, GL_FLOAT, true, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, UV)));
					VAOS[i][j].LinkAttrib(VBOS[i][j], 3, 2, GL_FLOAT, true, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, Normal)));

					// Unbind all to prevent accidentally modifying them
					VAOS[i][j].Unbind();
					VBOS[i][j].Unbind();
					EBOS[i][j].Unbind();
				}
			}

			// Model Matrix
			glm::mat4 ModelMatrix = glm::identity<glm::mat4>();
			glm::mat4 ViewProjectionMatrix = Camera.GetViewProjection();
			glm::mat4 ModelViewProjection = ViewProjectionMatrix * ModelMatrix;

			glm::vec4 lightColor = LightCube.Cor;
			glm::vec4 lightPos = LightCube.Centro;
			//std::cout << glm::to_string(lightPos.y) << std::endl;

			// Ativa o Shader de luz
			glUseProgram(LightShaderId);
			glUniformMatrix4fv(glGetUniformLocation(LightShaderId, "ModelViewProjection"), 1, GL_FALSE, glm::value_ptr(ModelViewProjection));
			glUniform4f(glGetUniformLocation(LightShaderId, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);

			// Ativar o programa de Shader
			glUseProgram(ProgramId);
			glUniformMatrix4fv(glGetUniformLocation(ProgramId, "ModelViewProjection"), 1, GL_FALSE, glm::value_ptr(ModelViewProjection));
			glUniform4f(glGetUniformLocation(ProgramId, "lightColor"), lightColor.x, lightColor.y, lightColor.z, lightColor.w);
			glUniform4f(glGetUniformLocation(ProgramId, "lightPos"), lightPos.x, lightPos.y, lightPos.z, lightPos.w);
			glUniform4f(glGetUniformLocation(ProgramId, "camPos"), Camera.Location.x, Camera.Location.y, Camera.Location.z, Camera.Location.w);

			// Desenha a nave
			VAOS[0][0].Bind();

			if (nave1.intangivel && nave1.piscando) { // Se ela estiver intang�vel
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			}
			else { // Se n�o estiver intang�vel, desenha normalmente
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			}
			glDrawElements(GL_TRIANGLES, bufferIndices[0][0].size() * 3, GL_UNSIGNED_INT, nullptr);

			VAOS[0][0].Unbind();
			VAOS[0][0].Delete();

			// Desenha Misseis, Estrelas, Fuma�as, PoweUps, LightCubes e Lifes
			for (int i = 2; i < bufferVertices.size() - 1; i++) {
				for (int j = 0; j < bufferVertices[i].size(); j++) {
					VAOS[i][j].Bind();

					glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
					glDrawElements(GL_TRIANGLES, bufferIndices[i][j].size() * 3, GL_UNSIGNED_INT, nullptr);

					VAOS[i][j].Unbind();
					VAOS[i][j].Delete();

				}
			}

			// Desenha os inimigos
			for (int j = 0; j < bufferVertices[1].size(); j++) {

				VAOS[1][j].Bind();

				// Se o Alien Tiver sido atingido e estar no estado "Apagado" ao piscar, desenha como linhas
				if (TodosAliens[j].intangivel && TodosAliens[j].piscando) { // Se o inimigo estiver intang�vel (foi acertado)
					glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
				}
				else {// Se o Alien n�o estiver intang�vel ou n�o estiver em estado apagado, desenha ele normalmente
					glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
				}
				glDrawElements(GL_TRIANGLES, bufferIndices[1][j].size() * 3, GL_UNSIGNED_INT, nullptr);

				VAOS[1][j].Unbind();
				VAOS[1][j].Delete();
			}

			// Desabilitar o programa ativo
			//glUseProgram(0);

			// Usa Shader de ilumin~��o
			glUseProgram(LightShaderId);

			// Desenha o Light Cube
			int PosicaoDosLightCubes = bufferVertices.size() - 1;
			for (int j = 0; j < bufferVertices[PosicaoDosLightCubes].size(); j++) {

				VAOS[PosicaoDosLightCubes][j].Bind();

				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
				glDrawElements(GL_TRIANGLES, bufferIndices[PosicaoDosLightCubes][j].size() * 3, GL_UNSIGNED_INT, nullptr);

				VAOS[PosicaoDosLightCubes][j].Unbind();
				VAOS[PosicaoDosLightCubes][j].Delete();
			}
			
			glUseProgram(0);

			// Processa todos os eventos na fila de eventos do GLFW
			// Eventos: Teclado, mouse, gamepad
			glfwPollEvents();

			// Envia o conte�do do framebuffer da janela para ser desenhado na tela
			glfwSwapBuffers(Window);

			// Processa os inputs do teclado

			if (glfwGetKey(Window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
				gameState.ApertaEsc();
			}

			if (glfwGetKey(Window, GLFW_KEY_ESCAPE) == GLFW_RELEASE) {
				gameState.SoltaEsc();
			}

			if (glfwGetKey(Window, GLFW_KEY_F1) == GLFW_PRESS) {
				gameState.ApertaF1();
			}

			if (glfwGetKey(Window, GLFW_KEY_F1) == GLFW_RELEASE) {
				gameState.SoltaF1();
			}

			// Printa o estado atual do jogo
			if (gameState.PrintaEstadoDoJogo) {
				std::cout << "Nave:  x->" << nave1.NaveCentro.x << " y->" << nave1.NaveCentro.y << std::endl;
				for (auto& alien : TodosAliens) {
					std::cout << "Alien:  x->" << alien.Centro.x << " y->" << alien.Centro.y << std::endl;
					if (alien.hasBomb) {
						std::cout << "Bomba:  x->" << alien.bomba.Centro.x << " y->" << alien.bomba.Centro.y << std::endl;
					}
				}
				for (auto& missil : TodosMisseis) {
					if (missil.NaveOuAlien) {
						std::cout << "Missil Aliado:  x->" << missil.Centro.x << " y->" << missil.Centro.y << std::endl;
					}
					else {
						std::cout << "Missil Inimigo:  x->" << missil.Centro.x << " y->" << missil.Centro.y << std::endl;
					}
				}
				for (auto& PowerUp : TodosPowerUp) {
					std::cout << "PowerUP:  x->" << PowerUp.Centro.x << " y->" << PowerUp.Centro.y << std::endl;
				}
				gameState.PrintaEstadoDoJogo = false;
			}


			// Se o game estiver pausado, n�o processa nada para baixo
			if (gameState.pausedGame) {
				continue;
			}

			if (glfwGetKey(Window, GLFW_KEY_W) == GLFW_PRESS) {
				gameState.ApertaW();
			}

			if (glfwGetKey(Window, GLFW_KEY_W) == GLFW_RELEASE) {
				gameState.SoltaW();
			}

			if (glfwGetKey(Window, GLFW_KEY_S) == GLFW_PRESS) {
				gameState.ApertaS();
			}

			if (glfwGetKey(Window, GLFW_KEY_S) == GLFW_RELEASE) {
				gameState.SoltaS();
			}

			if (glfwGetKey(Window, GLFW_KEY_D) == GLFW_PRESS) {
				gameState.ApertaD();
			}

			if (glfwGetKey(Window, GLFW_KEY_D) == GLFW_RELEASE) {
				gameState.SoltaD();
			}

			if (glfwGetKey(Window, GLFW_KEY_A) == GLFW_PRESS) {
				gameState.ApertaA();
			}

			if (glfwGetKey(Window, GLFW_KEY_A) == GLFW_RELEASE) {
				gameState.SoltaA();
			}

			if (glfwGetKey(Window, GLFW_KEY_Q) == GLFW_PRESS) {
				exit(EXIT_FAILURE);
			}

			if (glfwGetKey(Window, GLFW_KEY_R) == GLFW_PRESS) {
				gameState.gameOver = true;
			}

			// Anda com o Light Cube
			LightCube.moveFoward(DeltaTime, gameState.velocidadeDeDescidaDoPowerUp);
			if (LightCube.Centro.y <= -5.0f) {
				glm::vec3 FatorDeTranslacaoLightCube{ -LightCube.Centro.x + (rng / 2500) - 2.0f, -LightCube.Centro.y + 5.0f, 0.0f };
				LightCube.translada(FatorDeTranslacaoLightCube);
			}

			// Aplica Power Ups
			gameState.AplicaPowerUps(DeltaTime);

			// Mexe a nave lateralmente
			double X, Y;
			glfwGetCursorPos(Window, &X, &Y);
			double XNormalizado = ((X / Width) - 0.5f) * 4;
			nave1.MoveNaveLateralmente(XNormalizado, gameState.VelocidadeLateralNave);

			// Verifica se nave est� atirando
			if (gameState.NaveAtira) {
				if (ContadorDeDelayDeTiros <= 0.0) {
					ContadorDeDelayDeTiros = gameState.CadenciaDeTirosNave;
					Missil missil = nave1.Atira(gameState.VelocidadeDoTiroNave * DeltaTime);
					TodosMisseis.push_back(missil);
					for (int i = 0; i < 5; i++) {
						Smoke fumaca(glm::vec4{ missil.Centro.x, missil.Centro.y + 0.1f ,missil.Centro.z , 1.0f}, missil.Up);
						TodasSmokes.push_back(fumaca);
					}
				}
				ContadorDeDelayDeTiros -= DeltaTime;
			}

			// Atualiza as fumacas
			for (auto& fumaca : TodasSmokes) {
				fumaca.moveFoward(DeltaTime);
			}

			for (int i = 0; i < TodasSmokes.size(); i++) {
				if (TodasSmokes[i].tempoDeVida <= 0.0f) {
					TodasSmokes.erase(TodasSmokes.begin() + i);
				}
			}

			// Verifica se Inimigo est� atirando (DEBUG)
			if (gameState.InimigoAtira) {
				Missil missil = TodosAliens[0].Atira(1.5f * DeltaTime);
				TodosMisseis.push_back(missil);
			}

			// Verifica se vamos rotacionar a nave
			if (gameState.rotacionaNaveParaDireita) {
				nave1.MoveRight(-150.0f * DeltaTime);
			}
			if (gameState.rotacionaNaveParaEsquerda) {
				nave1.MoveRight(150.0f * DeltaTime);
			}

			// Pisca quando atingido
			if (nave1.intangivel) {
				nave1.pisca(gameState.TempoDePiscadaAoSerAtingido, DeltaTime);
			}

			for (auto& Alien : TodosAliens) {
				if (Alien.intangivel) {
					Alien.pisca(gameState.TempoDePiscadaAoSerAtingido, DeltaTime);
				}
			}

			glm::vec3 fatorDeTranslacaoEsquadrao{ 0.0f, -1.0f * gameState.velocidadeDosAlien * DeltaTime, 0.0f };
			glm::vec3 fatorDeTranslacaoEsquadraoSobe{ 0.0f, 0.0f, gameState.velocidadeSubidaEDescidaInimigos * DeltaTime };

			// Operacoes com Alien
			for (auto& Alien: TodosAliens) {
				// Move o Alien lateralmente
				Alien.MoveAlienLateralmente(gameState.AlienMoveLeft, gameState.velocidadeDosAlien, DeltaTime);

				// Desce com o Alien se ele estiver atacando
				if (Alien.ataca) {
					Alien.AtacaEmEsquadrao(gameState.localDeSobrevooDosAliens, fatorDeTranslacaoEsquadrao, fatorDeTranslacaoEsquadraoSobe, gameState.alturaDoPlaneta);
				}

				// Sobe com o Alien se ele estiver recuando
				if (Alien.recua) {
					Alien.RecuaEmEsquadrao(fatorDeTranslacaoEsquadrao, fatorDeTranslacaoEsquadraoSobe, gameState.localDeSobrevooDosAliens);
				}

				// Atualiza tempo de intangilibidade
				if (Alien.intangivel) {
					Alien.AtualizaTempoDeTangibilidade(DeltaTime, gameState.tempoDeIntangibilidadeAlien);
				}

				// Se o Alien tiver uma bomba
				if (Alien.hasBomb) {
					Alien.AtualizaEstadoDaBomba(DeltaTime, fatorDeTranslacaoEsquadrao, gameState.intensidadePiscadaBombaDropada, gameState.velocidadeDePiscadaBombaDropada);

					// Se a bomba tiver explodidado, Game Over
					if (Alien.bomba.CountDown <= 0.0f) {
						gameState.gameOver = true;
					}
				}

				// Troca skin dos aliens
				Alien.TrocaSkin(DeltaTime, gameState.velocidadeDosAlien, gameState.hasPowerUp1, gameState.hasPowerUp2, gameState.congela);
		

				// Desce um pouquinho com cada Alien
				float fatorDeDescida = -0.02f * DeltaTime;
				glm::vec3 vetorDeDescida{ 0.0f, fatorDeDescida, 0.0f };
				Alien.transladaOAlien(vetorDeDescida);
				Alien.yOriginal += fatorDeDescida;
				if (Alien.hasBomb) {
					Alien.bomba.translada(vetorDeDescida);
				}
				
				// Verifica se os Alien Chegaram ao planeta durante a descida
				if (Alien.Centro.y <= -2.1) {
					gameState.gameOver = true;
				}
			}

			// Tira o cogelamento causado pelo powerUp2
			gameState.congela = false;

			gameState.localDeSobrevooDosAliens = std::min(gameState.localDeSobrevooDosAliens, TodosAliens[TodosAliens.size()-1].yOriginal - 0.2f);

			// Verifica se os Aliens atiram m�sseis		
			if (rng > 10000 - gameState.chanceDeInimigoAtirar) {
				int AlienQueAtira = rng % TodosAliens.size();
				Missil missil = TodosAliens[AlienQueAtira].Atira(gameState.VelocidadeDoTiroAlien * DeltaTime*2);
				TodosMisseis.push_back(missil);
			}

			// Verifica se algum alien vai carregar a bomba
			if (gameState.AlienComABomba == -1) {
				if (rng > 10000 - gameState.chanceDeInimigoTentarDroparBomba) {
					// Define qual Alien vai carregar a bomba
					int AlienQueCarregaABomba = rng % TodosAliens.size();
					if (!TodosAliens[AlienQueCarregaABomba].ataca && !TodosAliens[AlienQueCarregaABomba].recua && !TodosAliens[AlienQueCarregaABomba].hasBomb) {
						TodosAliens[AlienQueCarregaABomba].CarregaBomba(gameState.TempoParaBombaExplodirBombaDropada);
						// Chama esquadr�o para atacar junto
						if (rng > 10000 - gameState.chanceDeFormarEsquadrao) {
							std::vector<int> vizinhos;
							vizinhos.push_back(AlienQueCarregaABomba - gameState.NumeroDeColunasDeInimigos - 1);
							vizinhos.push_back(AlienQueCarregaABomba - gameState.NumeroDeColunasDeInimigos);
							vizinhos.push_back(AlienQueCarregaABomba - gameState.NumeroDeColunasDeInimigos + 1);
							vizinhos.push_back(AlienQueCarregaABomba - 1);
							vizinhos.push_back(AlienQueCarregaABomba + 1);
							vizinhos.push_back(AlienQueCarregaABomba + gameState.NumeroDeColunasDeInimigos - 1);
							vizinhos.push_back(AlienQueCarregaABomba + gameState.NumeroDeColunasDeInimigos);
							vizinhos.push_back(AlienQueCarregaABomba + gameState.NumeroDeColunasDeInimigos + 1);
							// Verifica os membros v�lidos do esquadr�o
							for (int i = 0; i < vizinhos.size(); i++) {
								if (vizinhos[i] < 0)
									continue;
								else if (vizinhos[i] >= TodosAliens.size())
									continue;
								else if (TodosAliens[vizinhos[i]].recua == true || TodosAliens[vizinhos[i]].ataca == true)
									continue;
								TodosAliens[vizinhos[i]].ataca = true;
							}
						}
					}
				}
			}

			//Anda com todos Power Ups
			for (int i = 0; i < TodosPowerUp.size(); i++) {
				TodosPowerUp[i].moveOPowerUp(DeltaTime, gameState.velocidadeDeDescidaDoPowerUp);
				if (TodosPowerUp[i].Centro.y > 2.0f || TodosPowerUp[i].Centro.y < -2.0f) {
					TodosPowerUp.erase(TodosPowerUp.begin() + i);
				}
			}

			// Cria Esrelas
			if(TodasStars.size() == 0 || TodasStars[TodasStars.size()-1].Centro.y <= 3.90f ){//< gameState.QuantidadeDeEstrelas) {
				float Profundidade = -1.0f * (static_cast<float>(rng % 1500) / 100.0f) - 2.0f;
				float EixoXDaEstrelha = ((static_cast<float>(rng % 400) / 100.0f) - 2.0f) * (-1.0f * Profundidade);
				float BrilhoEstrela = (static_cast<float>(rng % 100) / 50.0f);				
				Stars estrela(EixoXDaEstrelha, BrilhoEstrela, Profundidade);
				TodasStars.push_back(estrela);
			}

			// Anda com as Estrelas
			for (int i = 0; i < TodasStars.size(); i++) {
				TodasStars[i].moveFoward(DeltaTime, gameState.velocidadeDeDescidaDoPowerUp);
				if (TodasStars[i].Centro.y < -4.5f || TodasStars[i].Centro.y > 4.0f) {
					TodasStars.erase(TodasStars.begin() + i);
				}
			}

			// Anda com os misseis e Verifica colis�o

			// Verifica tangibilidade
			if (nave1.intangivel) {
				nave1.AtualizaTempoDeTangibilidade(DeltaTime, gameState.tempoDeIntangibilidadeNave);
			}

			GLuint AlienAtingido = -1;
			GLuint MissilAtingido = -1;
			GLuint PowerUpAtingido = -1;
			bool atingiu = false;

			for (int i = 0; i < TodosMisseis.size(); i++) {
				if (
					TodosMisseis[i].Centro.x > 2.0f ||
					TodosMisseis[i].Centro.x < -2.0f ||
					TodosMisseis[i].Centro.y < -2.0f ||
					TodosMisseis[i].Centro.y > 2.0f
					) {
					TodosMisseis.erase(TodosMisseis.begin() + i);
					continue;
				}
				TodosMisseis[i].moveFoward();

				// Adiciona fuma�a no rastro de cada tiro
				//for (int j = 0; j < 20; j++) {
				//	Smoke fumaca(glm::vec4{ TodosMisseis[i].Centro.x, TodosMisseis[i].Centro.y + 0.12f ,TodosMisseis[i].Centro.z , 1.0f }, TodosMisseis[i].Up);
				//	fumaca.tempoDeVida = 0.4f;
				//	TodasSmokes.push_back(fumaca);
				//}
				


				if (!atingiu) { // Se nenhum missil atingiu ningu�m neste frame
					if (TodosMisseis[i].NaveOuAlien == false) { // Se for um missil de Alien
						if (nave1.intangivel) {
							continue;
						}
						auto distanciaTiroNave = glm::length(nave1.NaveCentro - TodosMisseis[i].Centro); // Calcula a dist�ncia do tiro para o centro da nave

						if (distanciaTiroNave <= 0.3f) { // Se a dist�ncia for menor que x
							nave1.life -= 1; // Tira 1 de life da nave
							TodasLifes.erase(TodasLifes.begin() + TodasLifes.size() - 1); // Tira um cora��o
							nave1.intangivel = true;
							MissilAtingido = i; // Salve o valor do missil que atingiu a nave
							atingiu = true;
							continue;
						}
					}
					else { // Se for um m�ssil da Nave
						for (int j = 0; j < TodosAliens.size(); j++) { // Para cada um dos aliens
							if (TodosAliens[j].intangivel) {
								continue;
							}
							auto distanciaTiroAlien = glm::length(TodosAliens[j].Centro - TodosMisseis[i].Centro); // Calcula a dist�ncia do tiro para o centro do alien

							if (distanciaTiroAlien <= 0.20f) { // Se a dist�ncia for menor que x
								AlienAtingido = j; // Salva qual Alien foi atingido
								MissilAtingido = i; // Salva qual tiro que atingiu
								atingiu = true;
								break;
							}
						}
					}
				}
			}

			// Verifica se a nave bateu em algum Alien
			for (int i = 0; i < TodosAliens.size(); i++) {
				if (TodosAliens[i].Centro.y > -1.4f) {
					continue;
				}
				if (TodosAliens[i].intangivel) {
					continue;
				}
				if (nave1.intangivel) {
					break;
				}
				auto distanciaNaveAlien = glm::length(TodosAliens[i].Centro - nave1.NaveCentro); // Calcula a dist�ncia do Alien para a nave
				if (distanciaNaveAlien <= 0.3) {
					AlienAtingido = i;
					nave1.life -= 1; // Tira 1 de life da nave
					TodasLifes.erase(TodasLifes.begin() + TodasLifes.size() - 1); // Tira um cora��o
					nave1.intangivel = true;
					atingiu = true;
					break;
				}
			}

			// Verifica se a nave pegou algum PowerUp
			for (int i = 0; i < TodosPowerUp.size(); i++) {
				if (TodosPowerUp[i].Centro.y > -1.3f) {
					continue;
				}
				auto distanciaNavePowerUp = glm::length(TodosPowerUp[i].Centro - nave1.NaveCentro); // Calcula a dist�ncia do Alien para a nave
				if (distanciaNavePowerUp <= 0.3) {
					PowerUpAtingido = i;
					gameState.getPowerUp(TodosPowerUp[i].tipo);
					atingiu = true;
					break;
				}
			}


			if (AlienAtingido != -1) { // Se algum algum Alien foi atingido
				TodosAliens[AlienAtingido].life -= 1; // Tira 1 de life do Alien
				TodosAliens[AlienAtingido].intangivel = true;
				if (rng > 10000 - gameState.ChanceDeDroparPowerUp) {
					int PowerUpNumber = rng % 3;
					TodosPowerUp.push_back(PowerUp(TodosAliens[AlienAtingido].Centro, PowerUpNumber));
				}
				if (TodosAliens[AlienAtingido].life <= 0) { // Se a vida do Alien chegar a 0

					// Gera explos�o ao alien morrer
					for (int j = 0; j < 10; j++) {
						Smoke fumaca(glm::vec4{ TodosAliens[AlienAtingido].Centro.x, TodosAliens[AlienAtingido].Centro.y + 0.12f ,TodosAliens[AlienAtingido].Centro.z , 1.0f }, TodosAliens[AlienAtingido].Up);
						fumaca.tempoDeVida = 2.0f;
						TodasSmokes.push_back(fumaca);
					}

					TodosAliens.erase(TodosAliens.begin() + AlienAtingido); // Mata o Alien
					if (TodosAliens.size() <= 0) {
						gameState.vitoria = true;
					}
				}
			}


			if (MissilAtingido != -1) { // Se Algum Missil atingiu algo
				TodosMisseis.erase(TodosMisseis.begin() + MissilAtingido); // Apaga o Missil
			}

			if (PowerUpAtingido != -1) { // Se a Nave pegou agum power up
				TodosPowerUp.erase(TodosPowerUp.begin() + PowerUpAtingido); // Apaga o Power Up
			}

			if (nave1.life <= 0) {
				gameState.gameOver = true;
			}
		}

		// Encerra GLFW
		glfwTerminate();
	}
	

	return 0;
}