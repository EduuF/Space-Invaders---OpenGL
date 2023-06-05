#include "Vectors.h"
#include "Nave.h"
#include "Alien.h"
#include "Matrices.h"
#include "Triangle.h"
#include "Missil.h"

#include <iostream>
#include <fstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <array>

const int Width = 800;
const int Height = 800;
const float Speed = 1.0f;
const float Sensitivity = 0.1f;

std::string ReadFile(const char* FilePath) {

	std::string FileContents;
	if (std::ifstream FileStream{ FilePath, std::ios::in }) {
		// Vai ler dentro do FileContets o conteúdo do arquivo apontado por FilePath
		FileContents.assign(std::istreambuf_iterator<char>(FileStream), std::istreambuf_iterator<char>());
	}
	return FileContents;
}

void CheckShader(GLuint ShaderId) {
	// ShaderId tem que ser um identificador de um Shader já compilado

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

	// Ler o conteúdo dos arquivos de shaders
	std::string VertexShaderSource = ReadFile(VertexShaderFile);
	std::string FragmentShaderSource = ReadFile(FragmnetShaderFile);

	// Criar os identificadores do Vertex e Fragment Shaders
	GLuint VertexShaderId = glCreateShader(GL_VERTEX_SHADER);
	GLuint FragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);

	// Compilando os arquivos de Shaders
	const char* VertexShaderSourcePtr = VertexShaderSource.c_str();
	glShaderSource(VertexShaderId, 1, &VertexShaderSourcePtr, nullptr); // Podem haver mais de 1 shaders
	glCompileShader(VertexShaderId);

	// Verificar se a compilação do VertexShader deu certo
	CheckShader(VertexShaderId);

	// Compilando os arquivos de Shaders
	const char* FragmentShaderSourcePtr = FragmentShaderSource.c_str();
	glShaderSource(FragmentShaderId, 1, &FragmentShaderSourcePtr, nullptr); // Podem haver mais de 1 shaders
	glCompileShader(FragmentShaderId);

	// Verificar se a compilação do FragmentShader deu certo
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

	// Desacopla e deleta os shaders pois já estão carregados
	glDetachShader(ProgramId, VertexShaderId);
	glDetachShader(ProgramId, FragmentShaderId);

	glDeleteShader(VertexShaderId);
	glDeleteShader(FragmentShaderId);

	return ProgramId;
}


class FlyCamera {
public:

	void MoveFoward(float Amount) {
		Location += glm::normalize(Direction) * Amount * Speed;
	}

	void MoveRight(float Amount) {
		glm::vec3 Right = glm::normalize(glm::cross(Direction, Up));
		Location += Right * Amount * Speed;
	}


	glm::mat4 GetViewProjection() const {
		glm::mat4 View = glm::lookAt(Location, Location + Direction, Up);
		glm::mat4 Projection = glm::perspective(FieldOfView, AspectRatio, Near, Far);
		return Projection * View;
	}

	// Definição da Matriz de View
	glm::vec3 Location{ 0.0f, 0.0f, 5.0f };
	glm::vec3 Direction{ 0.0f, 0.0f, -1.0f };
	glm::vec3 Up{ 0.0f, 1.0f, 0.0f };

	// Definição da Matriz Projection
	float FieldOfView = glm::radians(45.0f);
	float AspectRatio = Width / Height;
	float Near = 0.01f;
	float Far = 1000.0f;
};

// Declara um objeto camera globalmente
FlyCamera Camera;
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

glm::vec3 MoveNave(double MouseXPos, glm::vec4 navePos) {
	float alfa = 0.035;
	MouseXPos = ((MouseXPos / Width) - 0.5f) * 4;
	float realSpeed = (MouseXPos - navePos.x) * alfa ;
	glm::vec3 fatorDeTransalacao{ realSpeed , 0.0f, 0.0f};

	return fatorDeTransalacao;

}

int main() {
	 
	// Inicializa GLFW
	glfwInit();

	// Criar uma janela
	GLFWwindow* Window = glfwCreateWindow(Width, Height, "Space Invaders - CG 2023/1 - Aluno: Eduardo Fiuza - Professor: Renato Ferreira", nullptr, nullptr);

	// Cria o Viewport
	//glViewport(0, 0, Width, Height);

	// Ajusta o Viewport dependendo se o usuário aumentou ou diminui a tela
	//glfwSetFramebufferSizeCallback(Window, framebuffer_size_callback);

	// Cadastrar as callbacks no GLFW
	glfwSetMouseButtonCallback(Window, MouseButtonCallback);
	glfwSetCursorPosCallback(Window, MouseMotionCallback);

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

	// Carrega os Shaders
	GLuint ProgramId = LoadShaders("triangle_vert.glsl", "triangle_frag.glsl");

	// Cria uma nave
	Nave nave1 = Nave(glm::vec4{0.0f, 0.0f, 0.0f, 1.0f}); // A quarta dimensão deve ser 1.0f pois é um ponto
	glm::vec3 fatorDeEscalaNave{ 1.0f, 3.0f, 0.0f };
	nave1.ajustaEscalaDaNave(fatorDeEscalaNave);
	glm::vec3 fatorDeTranslacaoNave{ -0.5f, -0.5f, 0.0f };
	nave1.transladaANave(fatorDeTranslacaoNave);
	float angleRotacaoNave = -30;
	//nave1.rotacionaANave(angleRotacaoNave);

	// Cria inimigos
	std::array<Alien, 3> TodosAliens;
	for (int i = 0; i < 3; i++) {
		TodosAliens[i] = Alien(glm::vec4{ -1.0f + ((i+1) * 0.5f), 0.8f, 0.0f, 1.0f });
	}
	glm::vec3 fatorDeTranslacaoAlien{ 0.8,0.4,0.0 };
	TodosAliens[0].transladaOAlien(fatorDeTranslacaoAlien);
	TodosAliens[1].transladaOAlien(fatorDeTranslacaoAlien);
	float angleRotacaoAlien = 45;
	//TodosAliens[0].rotacionaOAlien(angleRotacaoAlien);

	// Guarda os Misseis
	const GLuint numeroDeMisseis = 10;

	std::array<Missil, numeroDeMisseis> TodosMisseis;
	GLuint contadorDeMisseis = 0;

	// Copiar os vértices do triangulo para a memória da GPU
	GLuint VertexBuffer;

	// Pedir para o OpenGL gerar o identificador do VertexBuffer
	glGenBuffers(1, &VertexBuffer);

	// Definir cor de fundo da janela
	glClearColor(0.99f, 0.85f, 0.98f, 1.0f); // Azul escuro

	// Guarda o tempo do frame anterior
	double PreviousTime = glfwGetTime();

	// Rendeiza apenas a face da frente
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	// Loop de eventos da aplicação
	while (!glfwWindowShouldClose(Window)){

		// Calcula o tempo dos frames
		double CurrentTime = glfwGetTime();
		double DeltaTime = CurrentTime - PreviousTime;

		if (DeltaTime > 0.0) {
			PreviousTime = CurrentTime;
		}

		// Model Matrix
		glm::mat4 ModelMatrix = glm::identity<glm::mat4>();

		// Ativar o VertexBuffer como sendo o Buffer para onde vamos copiar os dados do triangulo
		glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);

		// Copiar os dados dos triangulos para a memória de vídeo
		// Carregue os dados de todos os triângulos no buffer da GPU.
		// (Buffer ativado, quantos bytes serão copiados, ponteiro para os dados, tipo de uso do buffer)
		const int tamanhoDaNave = 7; // A quantidade de triangulos na nave
		const int tamanhoDoAlien = 18; // A quantidade de triangulos do Alien
		const int tamanhoDoMissil = 4;

		std::array<std::array<Vertex, 3>, tamanhoDaNave + (tamanhoDoAlien * 3) + (tamanhoDoMissil * (TodosMisseis.size()))> bufferData; // Cria um vetor de triangulos

		std::copy(nave1.modeloDaNave.begin(), nave1.modeloDaNave.end(), bufferData.begin()); // Copia todos os triangulos da nave para o bufferData
		for (int i = 0; i < 3; i++) {
			std::copy(TodosAliens[i].modeloDoInimigo.begin(), TodosAliens[i].modeloDoInimigo.end(), bufferData.begin() + tamanhoDaNave + (i * tamanhoDoAlien)); // Copia todos os triangulos do Alien para o bufferData
		}
		for (int i = 0; i < TodosMisseis.size(); i++) {
			std::copy(TodosMisseis[i].modelo.begin(), TodosMisseis[i].modelo.end(), bufferData.begin() + tamanhoDaNave + (TodosAliens.size() * tamanhoDoAlien) + (i * tamanhoDoMissil));
		}

		// Copiar os dados dos triângulos para a memória de vídeo
		// Carregue os dados de todos os triângulos no buffer da GPU.
		// (Buffer ativado, quantos bytes serão copiados, ponteiro para os dados, tipo de uso do buffer)
		glBufferData(GL_ARRAY_BUFFER, sizeof(bufferData), bufferData.data(), GL_STATIC_DRAW);

		// Limpa o framebuffer. GL_COLOR_BUFFER_BIT limpa o buffer de cor e preenche com a cor definida em "glClearColor"
		// Para desenharmos objetos 3D na tela teremos que voltar ao glClear para limparmos o buffer de profundidade
		glClear(GL_COLOR_BUFFER_BIT);

		// Ativar o programa de Shader
		glUseProgram(ProgramId);


		glm::mat4 ViewProjectionMatrix = Camera.GetViewProjection();

		glm::mat4 ModelViewProjection = ViewProjectionMatrix * ModelMatrix;

		// Aloca cálculo da ModelViewProjection de cada vértice para a GPU
		GLint ModelViewProjectionLoc = glGetUniformLocation(ProgramId, "ModelViewProjection");
		glUniformMatrix4fv(ModelViewProjectionLoc, 1, GL_FALSE, glm::value_ptr(ModelViewProjection));

		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);

		// Diz ao OpenGL que o VertexBuffer vai ser o buffer ativo no momento
		glBindBuffer(GL_ARRAY_BUFFER, VertexBuffer);

		// Informa ao OpenGL onde, dentro do vertexBuffer, os vértices estão. 
		// No caso o array Triangles é contíguo na memória, então basta dizer quantos vértices vamos usar para desenhar o triangulo
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr); // 4 = cada vértice é representado por 4 valores de ponto flutuante
		glVertexAttribPointer(1, 4, GL_FLOAT, GL_TRUE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, Color)));
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_TRUE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, UV)));

		// Desenha a nave
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glDrawArrays(GL_TRIANGLES, 0, (tamanhoDaNave - 2) * 3);

		// Desenha a Bouding Box
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glDrawArrays(GL_TRIANGLES, (tamanhoDaNave - 2) * 3, 6);

		// Desenha os inimigos
		for (int i = 0; i < TodosAliens.size(); i++) {
			
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glDrawArrays(GL_TRIANGLES, ((tamanhoDaNave) * 3) + ((tamanhoDoAlien) * 3 * i) , ((tamanhoDoAlien - 2) * 3));

			// Desenha Bouding Box dos inimigos
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			glDrawArrays(GL_TRIANGLES, (tamanhoDaNave + (tamanhoDoAlien * (i+1)) - 2) * 3, 6);
		}

		// Desenha os tiros
		for (int i = 0; i < numeroDeMisseis; i++) {

			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glDrawArrays(GL_TRIANGLES, ((tamanhoDaNave + (tamanhoDoAlien * TodosAliens.size())) * 3) + (tamanhoDoMissil * 3 * i), (tamanhoDoMissil - 2) * 3);

			// Desenha Bouding Box dos tiros
			//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			//glDrawArrays(GL_TRIANGLES, (tamanhoDaNave + (tamanhoDoAlien * TodosAliens.size()) + (tamanhoDoMissil * (i+1)) -2 )* 3, 6);
		}

		// Reverte o estado que nós criamos
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		glDisableVertexAttribArray(2);

		// Desabilitar o programa ativo
		glUseProgram(0);

		// Processa todos os eventos na fila de eventos do GLFW
		// Eventos: Teclado, mouse, gamepad
		glfwPollEvents();

		// Envia o conteúdo do framebuffer da janela para ser desenhado na tela
		glfwSwapBuffers(Window);

		glm::vec4 naveXPos = nave1.NaveCentro;
		double X, Y;
		glfwGetCursorPos(Window, &X, &Y);
		nave1.transladaANave(MoveNave(X, naveXPos));
		
		// Processa os inputs do teclado
		if (glfwGetKey(Window, GLFW_KEY_W) == GLFW_PRESS) {
			float velocidade = 1.0f * DeltaTime;
			Missil missil = nave1.Atira(velocidade);
			GLuint posicaoDoMissel = contadorDeMisseis % numeroDeMisseis;
			TodosMisseis[posicaoDoMissel] = missil;
			contadorDeMisseis = posicaoDoMissel + 1;			
		}

		if (glfwGetKey(Window, GLFW_KEY_S) == GLFW_PRESS) {
			Camera.MoveFoward(-1.0f * DeltaTime);
		}

		if (glfwGetKey(Window, GLFW_KEY_D) == GLFW_PRESS) {
			nave1.MoveRight(-150.0f * DeltaTime);
		}

		if (glfwGetKey(Window, GLFW_KEY_A) == GLFW_PRESS) {
			nave1.MoveRight(150.0f * DeltaTime);
		}

		for (int i = 0; i < TodosMisseis.size(); i++) {
			TodosMisseis[i].moveFoward();
		}
	}
	// Desalocar o VertexBuffer
	glDeleteBuffers(1, &VertexBuffer);

	

	// Encerra GLFW
	glfwTerminate();

	return 0;
}