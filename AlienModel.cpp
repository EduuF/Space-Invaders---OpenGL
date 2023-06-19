#include "Alien.h"
#include "GameState.h"

std::vector<Vertex> Alien::getAlienVertices(bool hasPowerUp1, bool hasPowerUp2) {

    //Cores
    glm::vec4 Cor{ 0.10f, 0.60f, 0.05f, 1.0f };
    if (hasPowerUp1) {
        Cor = glm::vec4{ 1.0f, 0.0f, 1.0f, 1.0f };
        
    }
    if (hasPowerUp2) {
        Cor = glm::vec4{ 0.35f, 0.35f, 0.8f, 1.0f };
        
    }
    
    //Modela o Alien
    std::vector<Vertex> Vertices{
        Vertex{ glm::vec4{ -0.2f, -0.6f,  +0.0f, 1.0f }, Cor }, // A 0
        Vertex{ glm::vec4{ -0.6f, -0.6f,  +0.0f, 1.0f }, Cor }, // B 1
        Vertex{ glm::vec4{ -0.2f, -0.4f,  +0.0f, 1.0f }, Cor }, // C 2 
        Vertex{ glm::vec4{ -0.6f, -0.4f,  +0.0f, 1.0f }, Cor }, // D 3 
        Vertex{ glm::vec4{ -0.8f, -0.4f,  +0.0f, 1.0f }, Cor }, // E 4 
        Vertex{ glm::vec4{ -0.8f, 0.6f, +0.0f, 1.0f }, Cor }, // F 5
        Vertex{ glm::vec4{ -0.6f, 0.6f,  +0.0f, 1.0f }, Cor }, // G 6
        Vertex{ glm::vec4{ -0.8f, 0.0f,  +0.0f, 1.0f }, Cor }, // H 7
        Vertex{ glm::vec4{ -1.2f, 0.0f, +0.0f, 1.0f }, Cor }, // I 8
        Vertex{ glm::vec4{ -1.2f, 0.2f, +0.0f, 1.0f }, Cor }, // J 9
        Vertex{ glm::vec4{ -0.8f, 0.2f,  +0.0f, 1.0f }, Cor }, // K 10
        Vertex{ glm::vec4{ -1.2f, -0.4f,  +0.0f, 1.0f }, Cor }, // L 11
        Vertex{ glm::vec4{ -1.0f, 0.0f,  +0.0f, 1.0f }, Cor }, // M 12
        Vertex{ glm::vec4{ -1.00f, -0.4f,  +0.0f, 1.0f }, Cor }, // N 13
        Vertex{ glm::vec4{ -1.0f, 0.2f, +0.0f, 1.0f }, Cor }, // O 14
        Vertex{ glm::vec4{ -1.0f, 0.4f,  +0.0f, 1.0f }, Cor }, // P 15
        Vertex{ glm::vec4{ -0.8f, 0.4f,  +0.0f, 1.0f }, Cor }, // Q 16 
        Vertex{ glm::vec4{ -0.6f, 0.4f, +0.0f, 1.0f }, Cor }, // R 17
        Vertex{ glm::vec4{ -0.6f, 0.8f,  +0.0f, 1.0f }, Cor }, // S 18
        Vertex{ glm::vec4{ -0.4f, 0.8f,  +0.0f, 1.0f }, Cor }, // T 19
        Vertex{ glm::vec4{ -0.4f, 0.4f,  +0.0f, 1.0f }, Cor }, // U 20
        Vertex{ glm::vec4{ -0.8f, 0.8f,  +0.0f, 1.0f }, Cor }, // V 21
        Vertex{ glm::vec4{ -0.6f, 1.0f,  +0.0f, 1.0f }, Cor }, // W 22
        Vertex{ glm::vec4{ -0.8f, 1.0f, +0.0f, 1.0f }, Cor }, // Z 23
        Vertex{ glm::vec4{ -0.6f, -0.2f,  +0.0f, 1.0f }, Cor }, // H1 24
        Vertex{ glm::vec4{ -0.6f, 0.2f, +0.0f, 1.0f }, Cor }, // F1 25
        Vertex{ glm::vec4{ -0.4f, 0.2f,  +0.0f, 1.0f }, Cor }, // G1 26
        Vertex{ glm::vec4{ -0.4f, -0.2f,  +0.0f, 1.0f }, Cor }, // D1 27
        Vertex{ glm::vec4{ -0.4f, 0.6f,  +0.0f, 1.0f }, Cor }, // A1 28
        Vertex{ glm::vec4{ 0.0f, 0.6f,  +0.0f, 1.0f }, Cor }, // B1 29
        Vertex{ glm::vec4{ 0.0f, -0.2f,  +0.0f, 1.0f }, Cor }, // E1 30
        Vertex{ glm::vec4{ 0.2f, -0.6f,  +0.0f, 1.0f }, Cor }, // AntiA 31
        Vertex{ glm::vec4{ 0.6f, -0.6f,  +0.0f, 1.0f }, Cor }, // AntiB 32
        Vertex{ glm::vec4{ 0.2f, -0.4f,  +0.0f, 1.0f }, Cor }, // AntiC 33 
        Vertex{ glm::vec4{ 0.6f, -0.4f,  +0.0f, 1.0f }, Cor }, // AntiD 34
        Vertex{ glm::vec4{ 0.8f, -0.4f,  +0.0f, 1.0f }, Cor }, // AntiE 35
        Vertex{ glm::vec4{ 0.8f, 0.6f, +0.0f, 1.0f }, Cor }, // AntiF 36
        Vertex{ glm::vec4{ 0.6f, 0.6f,  +0.0f, 1.0f }, Cor }, // AntiG 37
        Vertex{ glm::vec4{ 0.8f, 0.0f,  +0.0f, 1.0f }, Cor }, // AntiH 38
        Vertex{ glm::vec4{ 1.2f, 0.0f, +0.0f, 1.0f }, Cor }, // AntiI 39
        Vertex{ glm::vec4{ 1.2f, 0.2f, +0.0f, 1.0f }, Cor }, // AntiJ 40
        Vertex{ glm::vec4{ 0.8f, 0.2f,  +0.0f, 1.0f }, Cor }, // AntiK 41
        Vertex{ glm::vec4{ 1.2f, -0.4f,  +0.0f, 1.0f }, Cor }, // AntiL 42
        Vertex{ glm::vec4{ 1.0f, 0.0f,  +0.0f, 1.0f }, Cor }, // AntiM 43
        Vertex{ glm::vec4{ 1.00f, -0.4f,  +0.0f, 1.0f }, Cor }, // AntiN 44
        Vertex{ glm::vec4{ 1.0f, 0.2f, +0.0f, 1.0f }, Cor }, // AntiO 45
        Vertex{ glm::vec4{ 1.0f, 0.4f,  +0.0f, 1.0f }, Cor }, // AntiP 46
        Vertex{ glm::vec4{ 0.8f, 0.4f,  +0.0f, 1.0f }, Cor }, // AntiQ 47
        Vertex{ glm::vec4{ 0.6f, 0.4f, +0.0f, 1.0f }, Cor }, // AntiR 48
        Vertex{ glm::vec4{ 0.6f, 0.8f,  +0.0f, 1.0f }, Cor }, // AntiS 49
        Vertex{ glm::vec4{ 0.4f, 0.8f,  +0.0f, 1.0f }, Cor }, // AntiT 50
        Vertex{ glm::vec4{ 0.4f, 0.4f,  +0.0f, 1.0f }, Cor }, // AntiU 51
        Vertex{ glm::vec4{ 0.8f, 0.8f,  +0.0f, 1.0f }, Cor }, // AntiV 52
        Vertex{ glm::vec4{ 0.6f, 1.0f,  +0.0f, 1.0f }, Cor }, // AntiW 53
        Vertex{ glm::vec4{ 0.8f, 1.0f, +0.0f, 1.0f }, Cor }, // AntiZ 54
        Vertex{ glm::vec4{ 0.6f, -0.2f,  +0.0f, 1.0f }, Cor }, // AntiH1 55 
        Vertex{ glm::vec4{ 0.6f, 0.2f, +0.0f, 1.0f }, Cor }, // AntiF1 56
        Vertex{ glm::vec4{ 0.4f, 0.2f,  +0.0f, 1.0f }, Cor }, // AntiG1 57
        Vertex{ glm::vec4{ 0.4f, -0.2f,  +0.0f, 1.0f }, Cor }, // AntiD1 58
        Vertex{ glm::vec4{ 0.4f, 0.6f,  +0.0f, 1.0f }, Cor }, // AntiA1 59
        Vertex{ glm::vec4{ 0.0f, 0.6f,  +0.0f, 1.0f }, Cor }, // AntiB1 60
        Vertex{ glm::vec4{ 0.0f, -0.2f,  +0.0f, 1.0f }, Cor }, // AntiE1 61

        // Pose 2
        Vertex{ glm::vec4{ -1.6f, 0.2f,  +0.0f, 1.0f }, Cor }, // L Pose2 62
        Vertex{ glm::vec4{ -1.6f, 0.0f,  +0.0f, 1.0f }, Cor }, // N Pose2 63
        Vertex{ glm::vec4{ 1.6f, 0.2f,  +0.0f, 1.0f }, Cor }, // AntiL Pose2 64
        Vertex{ glm::vec4{ 1.6f, 0.0f,  +0.0f, 1.0f }, Cor }, // AntiN Pose2 65

        // Pose 3
        Vertex{ glm::vec4{ -1.0f, 0.6f,  +0.0f, 1.0f }, Cor }, // L Pose3 66
        Vertex{ glm::vec4{ -1.2f, 0.6f,  +0.0f, 1.0f }, Cor }, // N Pose3 67
        Vertex{ glm::vec4{ 1.0f, 0.6f,  +0.0f, 1.0f }, Cor }, // AntiL Pose3 68
        Vertex{ glm::vec4{ 1.2f, 0.6f,  +0.0f, 1.0f }, Cor }, // AntiN Pose3 69
    };
    return Vertices;
        
}

std::vector<glm::ivec3> Alien::getAlienIndices(int pose) {

    std::vector<glm::ivec3> ElementsIndexesAlienPose1 = {
        glm::ivec3{27, 29, 28}, //Corpo1
        glm::ivec3{27, 30, 29}, //Corpo2
        glm::ivec3{17, 19, 18}, //Corpo3
        glm::ivec3{17, 20, 19}, //Corpo4
        glm::ivec3{24, 26, 25}, //Corpo5
        glm::ivec3{24, 27, 26}, //Corpo6
        glm::ivec3{1, 2, 3}, //Corpo7
        glm::ivec3{1, 0, 2}, //Corpo8
        glm::ivec3{21, 22, 23}, //Corpo9
        glm::ivec3{21, 18, 22}, //Corpo10
        glm::ivec3{4, 3, 5}, //Corpo11
        glm::ivec3{3, 6, 5}, //Corpo12
        glm::ivec3{14, 10, 16}, //Corpo13
        glm::ivec3{14, 16, 15}, //Corpo14
        glm::ivec3{8, 7, 9}, //Corpo15
        glm::ivec3{7, 10, 9}, //Corpo16
        glm::ivec3{11, 12, 8}, //Corpo17
        glm::ivec3{11, 12, 13}, //Corpo18
        glm::ivec3{58, 59, 60}, //AntiCorpo1
        glm::ivec3{58, 60, 61}, //AntiCorpo2
        glm::ivec3{48, 49, 50}, //AntiCorpo3
        glm::ivec3{48, 50, 51}, //AntiCorpo4
        glm::ivec3{55, 56, 57}, //AntiCorpo5
        glm::ivec3{55, 57, 58}, //AntiCorpo6
        glm::ivec3{32, 34, 33}, //AntiCorpo7
        glm::ivec3{32, 33, 31}, //AntiCorpo8
        glm::ivec3{52, 54, 53}, //AntiCorpo9
        glm::ivec3{52, 53, 49}, //AntiCorpo10
        glm::ivec3{35, 36, 34}, //AntiCorpo11
        glm::ivec3{34, 36, 37}, //AntiCorpo12
        glm::ivec3{45, 47, 41}, //AntiCorpo13
        glm::ivec3{45, 46, 47}, //AntiCorpo14
        glm::ivec3{39, 40, 38}, //AntiCorpo15
        glm::ivec3{38, 40, 41}, //AntiCorpo16
        glm::ivec3{42, 39, 43}, //AntiCorpo17
        glm::ivec3{42, 44, 43}, //AntiCorpo18
    };

    std::vector<glm::ivec3> ElementsIndexesAlienPose2 = {
        glm::ivec3{27, 29, 28}, //Corpo1
        glm::ivec3{27, 30, 29}, //Corpo2
        glm::ivec3{17, 19, 18}, //Corpo3
        glm::ivec3{17, 20, 19}, //Corpo4
        glm::ivec3{24, 26, 25}, //Corpo5
        glm::ivec3{24, 27, 26}, //Corpo6
        glm::ivec3{1, 2, 3}, //Corpo7
        glm::ivec3{1, 0, 2}, //Corpo8
        glm::ivec3{21, 22, 23}, //Corpo9
        glm::ivec3{21, 18, 22}, //Corpo10
        glm::ivec3{4, 3, 5}, //Corpo11
        glm::ivec3{3, 6, 5}, //Corpo12
        glm::ivec3{14, 10, 16}, //Corpo13
        glm::ivec3{14, 16, 15}, //Corpo14
        glm::ivec3{8, 7, 9}, //Corpo15
        glm::ivec3{7, 10, 9}, //Corpo16
        glm::ivec3{62, 12, 8}, //Corpo17
        glm::ivec3{62, 12, 63}, //Corpo18
        glm::ivec3{58, 59, 60}, //AntiCorpo1
        glm::ivec3{58, 60, 61}, //AntiCorpo2
        glm::ivec3{48, 49, 50}, //AntiCorpo3
        glm::ivec3{48, 50, 51}, //AntiCorpo4
        glm::ivec3{55, 56, 57}, //AntiCorpo5
        glm::ivec3{55, 57, 58}, //AntiCorpo6
        glm::ivec3{32, 34, 33}, //AntiCorpo7
        glm::ivec3{32, 33, 31}, //AntiCorpo8
        glm::ivec3{52, 54, 53}, //AntiCorpo9
        glm::ivec3{52, 53, 49}, //AntiCorpo10
        glm::ivec3{35, 36, 34}, //AntiCorpo11
        glm::ivec3{34, 36, 37}, //AntiCorpo12
        glm::ivec3{45, 47, 41}, //AntiCorpo13
        glm::ivec3{45, 46, 47}, //AntiCorpo14
        glm::ivec3{39, 40, 38}, //AntiCorpo15
        glm::ivec3{38, 40, 41}, //AntiCorpo16
        glm::ivec3{64, 39, 43}, //AntiCorpo17
        glm::ivec3{64, 65, 43}, //AntiCorpo18
    };

    std::vector<glm::ivec3> ElementsIndexesAlienPose3 = {
        glm::ivec3{27, 29, 28}, //Corpo1
        glm::ivec3{27, 30, 29}, //Corpo2
        glm::ivec3{17, 19, 18}, //Corpo3
        glm::ivec3{17, 20, 19}, //Corpo4
        glm::ivec3{24, 26, 25}, //Corpo5
        glm::ivec3{24, 27, 26}, //Corpo6
        glm::ivec3{1, 2, 3}, //Corpo7
        glm::ivec3{1, 0, 2}, //Corpo8
        glm::ivec3{21, 22, 23}, //Corpo9
        glm::ivec3{21, 18, 22}, //Corpo10
        glm::ivec3{4, 3, 5}, //Corpo11
        glm::ivec3{3, 6, 5}, //Corpo12
        glm::ivec3{14, 10, 16}, //Corpo13
        glm::ivec3{14, 16, 15}, //Corpo14
        glm::ivec3{8, 7, 9}, //Corpo15
        glm::ivec3{7, 10, 9}, //Corpo16
        glm::ivec3{66, 12, 8}, //Corpo17
        glm::ivec3{66, 12, 67}, //Corpo18
        glm::ivec3{58, 59, 60}, //AntiCorpo1
        glm::ivec3{58, 60, 61}, //AntiCorpo2
        glm::ivec3{48, 49, 50}, //AntiCorpo3
        glm::ivec3{48, 50, 51}, //AntiCorpo4
        glm::ivec3{55, 56, 57}, //AntiCorpo5
        glm::ivec3{55, 57, 58}, //AntiCorpo6
        glm::ivec3{32, 34, 33}, //AntiCorpo7
        glm::ivec3{32, 33, 31}, //AntiCorpo8
        glm::ivec3{52, 54, 53}, //AntiCorpo9
        glm::ivec3{52, 53, 49}, //AntiCorpo10
        glm::ivec3{35, 36, 34}, //AntiCorpo11
        glm::ivec3{34, 36, 37}, //AntiCorpo12
        glm::ivec3{45, 47, 41}, //AntiCorpo13
        glm::ivec3{45, 46, 47}, //AntiCorpo14
        glm::ivec3{39, 40, 38}, //AntiCorpo15
        glm::ivec3{38, 40, 41}, //AntiCorpo16
        glm::ivec3{68, 39, 43}, //AntiCorpo17
        glm::ivec3{68, 69, 43}, //AntiCorpo18
    };

    if (pose == 1) {
        return ElementsIndexesAlienPose1;
    } else if (pose == 2) {
        return ElementsIndexesAlienPose2;
    }
    return ElementsIndexesAlienPose3;
}