#include "Nave.h"

std::vector<Vertex> Nave::getNaveVertices() {

    glm::vec4 Laranja{ 0.49f, 0.32f, 0.17f, 1.0f };
    glm::vec4 Palha{ 0.48f, 0.42f, 0.42f, 1.0f };
    glm::vec4 AzulClaro{ 0.13f, 0.40f, 0.43f, 1.0f };
    glm::vec4 Cinza{ 0.47f, 0.20f, 0.20f, 1.0f };

    std::vector<Vertex> Vertices{
        Vertex{ glm::vec4{ 0.0f,  1.00f,  0.0f, 1.0f }, AzulClaro, glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f}}, // A 0
        Vertex{ glm::vec4{ -0.22f, 0.9f,  0.0f, 1.0f }, AzulClaro, glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f} }, // B 1
        Vertex{ glm::vec4{ 0.0f,  0.9f,  0.0f, 1.0f }, AzulClaro, glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f} }, // C 2
        Vertex{ glm::vec4{ -0.35f, 0.7f,  0.0f, 1.0f }, Palha, glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f} }, // D 3
        Vertex{ glm::vec4{ 0.0f,  0.7f,   0.0f, 1.0f }, Palha, glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f} }, // E 4
        Vertex{ glm::vec4{ -0.35f,  -0.8f,   0.0f, 1.0f }, Palha, glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f} }, // F 5
        Vertex{ glm::vec4{ 0.0f, -0.8f,  0.0f, 1.0f }, Palha, glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f} }, // G 6
        Vertex{ glm::vec4{ -0.08f, -1.0f,  0.0f, 1.0f }, Laranja, glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f} }, // H 7
        Vertex{ glm::vec4{ -0.12f, -0.7f,  0.0f, 1.0f }, Laranja, glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f} }, // I 8
        Vertex{ glm::vec4{ -0.4f,-0.7f,  0.0f, 1.0f }, Laranja , glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f}}, // J 9
        Vertex{ glm::vec4{ -0.45f,  -1.0f,  0.0f, 1.0f }, Laranja, glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f} }, // K 10
        Vertex{ glm::vec4{ -0.35f, 0.25f,  0.0f, 1.0f }, AzulClaro, glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f} }, // L 11
        Vertex{ glm::vec4{ -0.6f, 0.0f,  0.0f, 1.0f }, AzulClaro, glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f} }, // M 12
        Vertex{ glm::vec4{ -0.35f, 0.0f,  0.0f, 1.0f }, AzulClaro, glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f} }, // N 13
        Vertex{ glm::vec4{ -1.9f,-0.4f,  0.0f, 1.0f }, AzulClaro, glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f} }, // O 14
        Vertex{ glm::vec4{ -0.35f, -0.56f,   0.0f, 1.0f }, AzulClaro, glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f} }, // P 15
        Vertex{ glm::vec4{ -2.0f, -0.6f,   0.0f, 1.0f }, Laranja , glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f}}, // Q 16
        Vertex{ glm::vec4{ -1.18f, -0.19f,  0.0f, 1.0f }, Cinza , glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f}}, // R 17
        Vertex{ glm::vec4{ -1.15f, 0.05f,  0.0f, 1.0f }, Cinza , glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f}}, // S 18
        Vertex{ glm::vec4{ -1.02f, -0.14f,  0.0f, 1.0f }, Cinza, glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f} }, // T 19
        Vertex{ glm::vec4{ -1.04f, 0.05f,  0.0f, 1.0f }, Cinza , glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f}}, // U 20
        Vertex{ glm::vec4{ -1.18f, -0.55f,  0.0f, 1.0f }, Cinza , glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f}}, // V 21
        Vertex{ glm::vec4{ -1.18f,  -0.68f,  0.0f, 1.0f }, Cinza, glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f} }, // W 22
        Vertex{ glm::vec4{ -1.02f,  -0.68f,  0.0f, 1.0f }, Cinza , glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f}}, // Z 23
        Vertex{ glm::vec4{ -1.02f, -0.57f,  0.0f, 1.0f }, Cinza , glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f}}, // A1 24
        Vertex{ glm::vec4{ 0.0f,  1.00f,  0.0f, 1.0f }, AzulClaro, glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f} }, // AntiA 25
        Vertex{ glm::vec4{ 0.22f, 0.9f,  0.0f, 1.0f }, AzulClaro , glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f}}, // AntiB 26
        Vertex{ glm::vec4{ 0.0f,  0.9f,  0.0f, 1.0f }, AzulClaro , glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f}}, // AntiC 27
        Vertex{ glm::vec4{ 0.35f, 0.7f,  0.0f, 1.0f }, Palha , glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f}}, // AntiD 28
        Vertex{ glm::vec4{ 0.0f,  0.7f,   0.0f, 1.0f }, Palha, glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f} }, // AntiE 29
        Vertex{ glm::vec4{ 0.35f,  -0.8f,   0.0f, 1.0f }, Palha, glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f} }, // AntiF 30
        Vertex{ glm::vec4{ 0.0f, -0.8f,  0.0f, 1.0f }, Palha , glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f}}, // AntiG 31
        Vertex{ glm::vec4{ 0.08f, -1.0f,  0.0f, 1.0f }, Laranja , glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f}}, // AntiH 32
        Vertex{ glm::vec4{ 0.12f, -0.7f,  0.0f, 1.0f }, Laranja, glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f} }, // AntiI 33
        Vertex{ glm::vec4{ 0.4f,-0.7f,  0.0f, 1.0f }, Laranja , glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f}}, // AntiJ 34
        Vertex{ glm::vec4{ 0.45f,  -1.0f,  0.0f, 1.0f }, Laranja , glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f}}, // AntiK 35
        Vertex{ glm::vec4{ 0.35f, 0.25f,  0.0f, 1.0f }, AzulClaro , glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f}}, // AntiL 36
        Vertex{ glm::vec4{ 0.6f, 0.0f,  0.0f, 1.0f }, AzulClaro , glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f}}, // AntiM 37
        Vertex{ glm::vec4{ 0.35f, 0.0f,  0.0f, 1.0f }, AzulClaro , glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f}}, // AntiN 38
        Vertex{ glm::vec4{ 1.9f,-0.4f,  0.0f, 1.0f }, AzulClaro , glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f}}, // AntiO 39
        Vertex{ glm::vec4{ 0.35f, -0.56f,   0.0f, 1.0f }, AzulClaro, glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f} }, // AntiP 40
        Vertex{ glm::vec4{ 2.0f, -0.6f,   0.0f, 1.0f }, Laranja , glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f}}, // AntiQ 41
        Vertex{ glm::vec4{ 1.18f, -0.19f,  0.0f, 1.0f }, Cinza, glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f} }, // AntiR 42
        Vertex{ glm::vec4{ 1.15f, 0.05f,  0.0f, 1.0f }, Cinza , glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f}}, // AntiS 43
        Vertex{ glm::vec4{ 1.02f, -0.14f,  0.0f, 1.0f }, Cinza , glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f}}, // AntiT 44
        Vertex{ glm::vec4{ 1.04f, 0.05f,  0.0f, 1.0f }, Cinza , glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f}}, // AntiU 45
        Vertex{ glm::vec4{ 1.18f, -0.55f,  0.0f, 1.0f }, Cinza , glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f}}, // AntiV 46
        Vertex{ glm::vec4{ 1.18f,  -0.68f,  0.0f, 1.0f }, Cinza , glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f}}, // AntiW 47
        Vertex{ glm::vec4{ 1.02f,  -0.68f,  0.0f, 1.0f }, Cinza, glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f} }, // AntiZ 48
        Vertex{ glm::vec4{ 1.02f, -0.57f,  0.0f, 1.0f }, Cinza, glm::vec2{1.0f, 1.0f,}, glm::vec4{1.0f, 1.0f, 1.0f, 0.0f} }, // AntiA1 49
    };

    return Vertices;
}

std::vector<glm::ivec3> Nave::getNaveIndices() {

    std::vector<glm::ivec3> ElementsIndexesNave = {
        glm::ivec3{0, 1, 2}, //Bico
        glm::ivec3{2, 1, 4}, //Cabine1
        glm::ivec3{1, 3, 4}, //Cabine2
        glm::ivec3{4, 3, 6}, //Corpo1
        glm::ivec3{6, 3, 5}, //Corpo2
        glm::ivec3{7, 8, 9}, //Motor1
        glm::ivec3{7, 9, 10}, //Motor2
        glm::ivec3{11, 12, 13}, //Asa1
        glm::ivec3{13, 12, 15}, //Asa2
        glm::ivec3{12, 14, 15}, //Asa3
        glm::ivec3{14, 16, 15}, //Asa4
        glm::ivec3{20, 18, 19}, //Arma1
        glm::ivec3{18, 17, 19}, //Arma2
        glm::ivec3{24, 21, 23}, //Arma3
        glm::ivec3{21, 22, 23}, //Arma4
        glm::ivec3{25, 27, 26}, //AntiBico
        glm::ivec3{27, 29, 26}, //AntiCabine1
        glm::ivec3{26, 29, 28}, //AntiCabine2
        glm::ivec3{29, 31, 28}, //AntiCorpo1
        glm::ivec3{31, 30, 28}, //AntiCorpo2
        glm::ivec3{32, 34, 33}, //AntiMotor1
        glm::ivec3{32, 35, 34}, //AntiMotor2
        glm::ivec3{36, 38, 37}, //AntiAsa1
        glm::ivec3{38, 40, 37}, //AntiAsa2
        glm::ivec3{37, 40, 39}, //AntiAsa3
        glm::ivec3{39, 40, 41}, //AntiAsa4
        glm::ivec3{45, 44, 43}, //AntiArma1
        glm::ivec3{43, 44, 42}, //AntiArma2
        glm::ivec3{49, 48, 46}, //AntiArma3
        glm::ivec3{46, 48, 47} //AntiArma4
    };

    return ElementsIndexesNave;
}
