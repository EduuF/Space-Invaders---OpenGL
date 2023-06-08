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

#include <random>
#include <vector>

const int Width = 1280;
const int Height = 1280;
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
	float alfa = 0.015f;
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
	glm::vec3 fatorDeEscalaNave{ 1.5f, 3.0f, 0.0f };
	nave1.ajustaEscalaDaNave(fatorDeEscalaNave);
	glm::vec3 fatorDeTranslacaoNave{ -0.5f, -1.6f, 0.0f };
	nave1.transladaANave(fatorDeTranslacaoNave);

	// Cria inimigos
	const GLuint NumeroDeLinhasDeInimigos = 5;
	const GLuint NumeroDeColunasDeInimigos = 7;
	const GLuint NumeroTotalDeInimigos = NumeroDeLinhasDeInimigos * NumeroDeColunasDeInimigos;
	const float LarguraAlien = 0.15f;
	const float LarguraIntervalo = 0.1f;
	const float LarguraJanela = (LarguraAlien * NumeroDeColunasDeInimigos) + (LarguraIntervalo * (NumeroDeColunasDeInimigos - 1));
	const float WidthGap = ((4 - LarguraJanela) / 2) - 2;

	std::vector<Alien> TodosAliens;
	for (int i = 0; i < NumeroTotalDeInimigos; i++) {
		GLuint linha = i / NumeroDeColunasDeInimigos;
		GLuint coluna = i % NumeroDeColunasDeInimigos;
		TodosAliens.push_back(Alien(glm::vec4{ WidthGap + (coluna *LarguraIntervalo) + (coluna * LarguraAlien), 1.8f - (linha * 0.3),  0.0f, 1.0f }));
		TodosAliens[i].yOriginal = 1.8f - (linha * 0.3);
	}

	
	glm::vec3 fatorDeTranslacaoAlien{ 0.8,0.4,0.0 };
	glm::vec3 fatorDeEscalaAlien{ 0.7f, 1.0f, 0.0f };
	for (int i = 0; i < TodosAliens.size(); i++) {
		TodosAliens[i].ajustaEscalaDoAlien(fatorDeEscalaAlien);
	}

	//TodosAliens[0].transladaOAlien(fatorDeTranslacaoAlien);
	//TodosAliens[1].transladaOAlien(fatorDeTranslacaoAlien);
	float angleRotacaoAlien = 45;
	//TodosAliens[0].rotacionaOAlien(angleRotacaoAlien);

	std::vector<Missil> TodosMisseis;

	// Copiar os vértices do triangulo para a memória da GPU
	GLuint VertexBuffer;

	// Pedir para o OpenGL gerar o identificador do VertexBuffer
	glGenBuffers(1, &VertexBuffer);

	// Definir cor de fundo da janela
	glClearColor(0.99f, 0.85f, 0.98f, 1.0f); // Azul escuro

	// Guarda o tempo do frame anterior
	double PreviousTime = glfwGetTime();

	//Delay de tiros
	double ContadorDeDelayDeTiros = 0;

	// Algum Alien tem a bomba?
	//int AlienQueCarregaABomba = 0;

	// Pica a bomba quando dropada
	float velocidadeDePiscada = 2.5f;
	float intensidadeDePiscada = 1.3f;

	// Velocidade dos inimigos
	float velocidadeInimigos = 0.15f;
	float velocidadeSubidaEDescidaInimigos = 1.2f;
	bool moveLeft = true;

	// Altura do planeta
	float alturaDoPlaneta = -1.8f;

	// Chance de o inimigo atirar x em 10000
	int chanceDeInimigoAtirar = 500;

	// Chance de algum inimigo tentar dropar uma bomba x em 10000
	int chanceDeInimigoTentarDroparBomba = 100;

	// Cadencia de tiros da nave
	float CadenciaDeTiros = 0.3f;
	

	// Rendeiza apenas a face da frente
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	// Loop de eventos da aplicação
	while (!glfwWindowShouldClose(Window)){

		if (TodosAliens.size() == 0) {
			break;
		}

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
		const int tamanhoDaBomba = 6;

		GLuint AlienComBomba = -1;

		std::vector<Vertex> bufferData; // Cria um vetor de triangulos
		for (auto triangulo: nave1.modeloDaNave) {
			bufferData.insert(bufferData.end(), triangulo.begin(), triangulo.end());
		}

		std::cout << "TodosAliens.size(): " << TodosAliens.size() << std::endl;

		for (int i = 0; i < TodosAliens.size(); i++) {
			for (auto triangulo: TodosAliens[i].modeloDoInimigo) {
				bufferData.insert(bufferData.end(), triangulo.begin(), triangulo.end());
			}
			if (TodosAliens[i].hasBomb) {
				AlienComBomba = i;
			}
		}
	
		for (int i = 0; i < TodosMisseis.size(); i++) {
			for (auto triangulo: TodosMisseis[i].modelo) {
				bufferData.insert(bufferData.end(), triangulo.begin(), triangulo.end());
			}
		}

		// Se a bomba estiver em game, desenha ela.
		if (AlienComBomba != -1) {
			for (auto triangulo: TodosAliens[AlienComBomba].bomba.Model) {
				bufferData.insert(bufferData.end(), triangulo.begin(), triangulo.end());
			}
		}

		// Copiar os dados dos triângulos para a memória de vídeo
		// Carregue os dados de todos os triângulos no buffer da GPU.
		// (Buffer ativado, quantos bytes serão copiados, ponteiro para os dados, tipo de uso do buffer)
		glBufferData(GL_ARRAY_BUFFER, bufferData.size() * sizeof(Vertex), bufferData.data(), GL_STATIC_DRAW);


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
		//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		//glDrawArrays(GL_TRIANGLES, (tamanhoDaNave - 2) * 3, 6);

		// Desenha os inimigos
		for (int i = 0; i < TodosAliens.size(); i++) {
			
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glDrawArrays(GL_TRIANGLES, ((tamanhoDaNave) * 3) + ((tamanhoDoAlien) * 3 * i) , ((tamanhoDoAlien - 2) * 3));

			// Desenha Bouding Box dos inimigos
			//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			//glDrawArrays(GL_TRIANGLES, (tamanhoDaNave + (tamanhoDoAlien * (i+1)) - 2) * 3, 6);
		}

		// Desenha os tiros
		for (int i = 0; i < TodosMisseis.size(); i++) {

			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glDrawArrays(GL_TRIANGLES, ((tamanhoDaNave + (tamanhoDoAlien * TodosAliens.size())) * 3) + (tamanhoDoMissil * 3 * i), (tamanhoDoMissil - 2) * 3);

			// Desenha Bouding Box dos tiros
			//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			//glDrawArrays(GL_TRIANGLES, (tamanhoDaNave + (tamanhoDoAlien * TodosAliens.size()) + (tamanhoDoMissil * (i+1)) -2 )* 3, 6);
		}

		// Desenha a bomba (se houver)
		if (AlienComBomba != -1) {
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glDrawArrays(GL_TRIANGLES, (tamanhoDaNave + (tamanhoDoAlien * TodosAliens.size()) + (tamanhoDoMissil * TodosMisseis.size()))*3, (tamanhoDaBomba - 2) * 3);
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

		// Nave Atira
		if (glfwGetKey(Window, GLFW_KEY_W) == GLFW_PRESS) {
			if (ContadorDeDelayDeTiros <= 0.0) {
				ContadorDeDelayDeTiros = CadenciaDeTiros;
				double velocidade = 1.0 * DeltaTime;
				Missil missil = nave1.Atira(velocidade);
				TodosMisseis.push_back(missil);
			}
			ContadorDeDelayDeTiros -= DeltaTime;
		}

		// Alien Atira (DEBUG)
		if (glfwGetKey(Window, GLFW_KEY_S) == GLFW_PRESS) {
			float velocidade = 1.5f * DeltaTime;
			Missil missil = TodosAliens[0].Atira(velocidade);
			TodosMisseis.push_back(missil);
		}

		if (glfwGetKey(Window, GLFW_KEY_D) == GLFW_PRESS) {
			nave1.MoveRight(-150.0f * DeltaTime);
		}

		if (glfwGetKey(Window, GLFW_KEY_A) == GLFW_PRESS) {
			nave1.MoveRight(150.0f * DeltaTime);
		}

		// Move os Aliens lateralmente
		for (auto& Alien : TodosAliens) {
			glm::vec3 fatorDeTranslacaoLateral;
			if (moveLeft) {
				fatorDeTranslacaoLateral = glm::vec3{ -1.0f * velocidadeInimigos * DeltaTime, 0.0f , 0.0f }; // Move para a esquerda
			}
			else {
				fatorDeTranslacaoLateral = glm::vec3{ 1.0f * velocidadeInimigos * DeltaTime, 0.0f , 0.0f }; // Move para a direita
			}

			Alien.transladaOAlien(fatorDeTranslacaoLateral); // Translada o Alien

			if (Alien.hasBomb && !Alien.bomba.Dropada) { // Se o Alien tiver bomba e a bomba não estiver dropada
				Alien.bomba.translada(fatorDeTranslacaoLateral); // Move a bomba
			}
			
			if (Alien.Centro.x < -1.8f) { // Se algum alien alcançar a parede esquerda, move pra direita
				moveLeft = false;
			}
			else if (Alien.Centro.x > 1.8f) {// Se algum alien alcançar a parede direita, move pra esquerda
				moveLeft = true;
			}

		}
		// Anda com o esquadrão
		glm::vec3 fatorDeTranslacaoEsquadrão{ 0.0f, -1.0f * velocidadeInimigos * DeltaTime, 0.0f };
		glm::vec3 fatorDeTranslacaoEsquadraoSobe{ 0.0f, 0.0f, velocidadeSubidaEDescidaInimigos * DeltaTime };
		glm::vec3 fatorDeTranslacaoEsquadraoDesce{ 0.0f, 0.0f, -1.0f * velocidadeSubidaEDescidaInimigos * DeltaTime };

		for (int i = 0; i < TodosAliens.size(); i++) {
			if (TodosAliens[i].ataca) { // Move os Aliens do esquadrão que está atacando
				float localDeSobrevoo = 2.0f - (NumeroDeLinhasDeInimigos * 0.3); // Define a area onde o inimigo deve sobrevoar outros inimigos

				if (TodosAliens[i].Centro.y > localDeSobrevoo && TodosAliens[i].Centro.z < 0.7f) { // Sobe Z
					TodosAliens[i].transladaOAlien(fatorDeTranslacaoEsquadraoSobe); 
					if (TodosAliens[i].hasBomb && !TodosAliens[i].bomba.Dropada) { // Se for o alien com bomba
						TodosAliens[i].bomba.translada(fatorDeTranslacaoEsquadraoSobe); // Sobe a bomba
					}
				}

				if (TodosAliens[i].Centro.y < localDeSobrevoo && TodosAliens[i].Centro.z > 0.0f) { // Desce Z
					TodosAliens[i].transladaOAlien(fatorDeTranslacaoEsquadraoDesce);
					if (TodosAliens[i].hasBomb && !TodosAliens[i].bomba.Dropada) { // Se for o Alien com bomba
						TodosAliens[i].bomba.translada(fatorDeTranslacaoEsquadraoDesce); // Desce a bomba
					}
				}

				TodosAliens[i].transladaOAlien(fatorDeTranslacaoEsquadrão); // Anda ele rumo ao planeta				

				if (TodosAliens[i].Centro.y < alturaDoPlaneta) { // Se o Alien chegar ao planeta
					TodosAliens[i].recua = true; // Manda recuar
					TodosAliens[i].ataca = false;
					if (TodosAliens[i].hasBomb) { // Se for o Alien que carrega a bomba
						TodosAliens[i].bomba.Dropada = true; // Dropa a bomba
					}
				}
			}
			
			if (TodosAliens[i].recua) {
				if (TodosAliens[i].Centro.y > 0.5f && TodosAliens[i].Centro.y < TodosAliens[i].yOriginal && TodosAliens[i].Centro.z < 1.0f) { // Sobe Z
					TodosAliens[i].transladaOAlien(fatorDeTranslacaoEsquadraoSobe);
				}

				if (TodosAliens[i].Centro.y >= TodosAliens[i].yOriginal && TodosAliens[i].Centro.z > -0.1f) { // Desce Z
					TodosAliens[i].transladaOAlien(fatorDeTranslacaoEsquadraoDesce);
				}

				if (TodosAliens[i].Centro.z < 0.0f) { // Se a nave tiver descido demais quando foi retornar
					TodosAliens[i].transladaOAlien(glm::vec3{ 0.0f, 0.0f, 0.0f - TodosAliens[i].Centro.z }); // conserta sua posição
				}

				if (TodosAliens[i].Centro.y < TodosAliens[i].yOriginal) {
					TodosAliens[i].transladaOAlien(-1.0f * fatorDeTranslacaoEsquadrão); // Retorna ele para a posição original
				}

				if (TodosAliens[i].Centro.y >= TodosAliens[i].yOriginal && TodosAliens[i].Centro.z == 0.0f) {
					TodosAliens[i].recua = false;
					TodosAliens[i].transladaOAlien(glm::vec3{ 0.0f, TodosAliens[i].yOriginal - TodosAliens[i].Centro.y, 0.0f - TodosAliens[i].Centro.z });
				}
			}

		}

		if (AlienComBomba != -1) {
			if (!TodosAliens[AlienComBomba].bomba.Dropada) { // Verifica se ela não foi dropada no planeta
				TodosAliens[AlienComBomba].bomba.translada(fatorDeTranslacaoEsquadrão); // Anda com a bomba
			}
			else {
				if (TodosAliens[AlienComBomba].bomba.Centro.z != 0.0f) {
					TodosAliens[AlienComBomba].bomba.translada(glm::vec3{ 0.0f, 0.0f, 0.0f - TodosAliens[AlienComBomba].bomba.Centro.z });
				}

				if (TodosAliens[AlienComBomba].bomba.escala.x >= intensidadeDePiscada) {
					TodosAliens[AlienComBomba].bomba.Aumentando = false;
				}
				if (TodosAliens[AlienComBomba].bomba.escala.x <= 0.9f) {
					TodosAliens[AlienComBomba].bomba.Aumentando = true;
				}

				if (TodosAliens[AlienComBomba].bomba.Aumentando) {
					TodosAliens[AlienComBomba].bomba.ajustaEscala(glm::vec3{ 1 + DeltaTime * velocidadeDePiscada, 1 + DeltaTime * velocidadeDePiscada, 0.0f });
					//std::cout << glm::to_string(TodosAliens[AlienQueCarregaABomba].bomba.Centro) << std::endl;
				}
				else {
					TodosAliens[AlienComBomba].bomba.ajustaEscala(glm::vec3{ 1 - DeltaTime * velocidadeDePiscada, 1 - DeltaTime * velocidadeDePiscada, 0.0f });
					//std::cout << glm::to_string(TodosAliens[AlienQueCarregaABomba].bomba.Centro) << std::endl;
				}
			}
		}
		
		// Verifica se os Aliens atiram mísseis
		std::random_device AlienAtira;
		std::uniform_int_distribution<int> dist(1, 10000);

		if (dist(AlienAtira) > 10000 - chanceDeInimigoAtirar) {
			int AlienQueAtira = dist(AlienAtira) % TodosAliens.size();
			
			float velocidade = 1.5f * DeltaTime;
			Missil missil = TodosAliens[AlienQueAtira].Atira(velocidade);
			TodosMisseis.push_back(missil);
		}

		// Verifica se algum alien vai carregar a bomba
		if (AlienComBomba == -1) {
			std::random_device randomBomb;
			std::uniform_int_distribution<int> distBombaNormal(1, 10000);

			int rng = (distBombaNormal(randomBomb));

			if (rng > 10000 - chanceDeInimigoTentarDroparBomba) {
				int candidatoAAlieQueCarregaABomba = rng % TodosAliens.size();

				if (!TodosAliens[candidatoAAlieQueCarregaABomba].ataca && !TodosAliens[candidatoAAlieQueCarregaABomba].recua && !TodosAliens[candidatoAAlieQueCarregaABomba].hasBomb) {
					GLuint AlienQueCarregaABomba = candidatoAAlieQueCarregaABomba;
					TodosAliens[AlienQueCarregaABomba].hasBomb = true;
					TodosAliens[AlienQueCarregaABomba].CarregaBomba();
					TodosAliens[AlienQueCarregaABomba].ataca = true;
					// Chama esquadrão para atacar junto

					if (rng > 9000) {
						std::vector<int> vizinhos;

						vizinhos.push_back(AlienQueCarregaABomba - NumeroDeColunasDeInimigos - 1);
						vizinhos.push_back(AlienQueCarregaABomba - NumeroDeColunasDeInimigos);
						vizinhos.push_back(AlienQueCarregaABomba - NumeroDeColunasDeInimigos + 1);
						vizinhos.push_back(AlienQueCarregaABomba - 1);
						vizinhos.push_back(AlienQueCarregaABomba + 1);
						vizinhos.push_back(AlienQueCarregaABomba + NumeroDeColunasDeInimigos - 1);
						vizinhos.push_back(AlienQueCarregaABomba + NumeroDeColunasDeInimigos);
						vizinhos.push_back(AlienQueCarregaABomba + NumeroDeColunasDeInimigos + 1);
						// Verifica os membros válidos do esquadrão
						for (int i = 0; i < 8; i++) {
							if (vizinhos[i] < 0) {
								continue;
							}
							else if (vizinhos[i] > TodosAliens.size()) {
								continue;
							}
							else if (TodosAliens[vizinhos[i]].recua == true || TodosAliens[vizinhos[i]].ataca == true) {
								continue;
							}
							// Coloca esquadrão em posição de ataque
							TodosAliens[vizinhos[i]].ataca = true;
						}
					}
				}
			}
		}
		// Anda com os misseis e Verifica colisão
		GLuint NaveAtingida = -1;
		GLuint MissilAtingido = -1;
		bool atingiu = false;

		for (int i = 0; i < TodosMisseis.size(); i++) {
			if (
				TodosMisseis[i].modelo[0][0].Position.x > 2.0f ||
				TodosMisseis[i].modelo[0][0].Position.x < -2.0f ||
				TodosMisseis[i].modelo[0][0].Position.y < -2.0f ||
				TodosMisseis[i].modelo[0][0].Position.y > 2.0f
				) {
				TodosMisseis.erase(TodosMisseis.begin() + i);
				continue;
			}
			TodosMisseis[i].moveFoward();

			// Verifica colisão dos tiros
			if (TodosMisseis[i].NaveOuAlien == false) {
				continue;
			}

			if (!atingiu) {
				for (int j = 0; j < TodosAliens.size(); j++) {
					auto distanciaTiroAlien = glm::length(TodosAliens[j].Centro - TodosMisseis[i].Centro);

					if (distanciaTiroAlien <= 0.1f) {
						NaveAtingida = j;
						MissilAtingido = i;
						atingiu = true;
						break;
					}
				}
			}

		}
		if (NaveAtingida != -1) {
			std::cout << "NaveAtingida: " << NaveAtingida << std::endl;
			TodosAliens.erase(TodosAliens.begin() + NaveAtingida);
		}
		if (MissilAtingido != -1) {
			std::cout << "MissilAtingido: " << MissilAtingido << std::endl;
			TodosMisseis.erase(TodosMisseis.begin() + MissilAtingido);
		}
	}
	// Desalocar o VertexBuffer
	glDeleteBuffers(1, &VertexBuffer);

	

	// Encerra GLFW
	glfwTerminate();

	return 0;
}