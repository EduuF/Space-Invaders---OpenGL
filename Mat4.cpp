#include "Mat4.h"

Mat4::Mat4() {
    data.fill(0.0f);
}

Mat4::Mat4(const std::array<float, 16>& data) : data(data) {}

Mat4 Mat4::identity() {
    return Mat4{ {1.0f, 0.0f, 0.0f, 0.0f,
                  0.0f, 1.0f, 0.0f, 0.0f,
                  0.0f, 0.0f, 1.0f, 0.0f,
                  0.0f, 0.0f, 0.0f, 1.0f} };
}

Mat4 Mat4::translation(float x, float y, float z) {
    return Mat4{ {1.0f, 0.0f, 0.0f, x,
                  0.0f, 1.0f, 0.0f, y,
                  0.0f, 0.0f, 1.0f, z,
                  0.0f, 0.0f, 0.0f, 1.0f} };
}

Mat4 Mat4::scaling(float x, float y, float z) {
    return Mat4{ {x,    0.0f, 0.0f, 0.0f,
                  0.0f, y,    0.0f, 0.0f,
                  0.0f, 0.0f, z,    0.0f,
                  0.0f, 0.0f, 0.0f, 1.0f} };
}

Mat4::Mat4(float diagonal) {
    data.fill(0.0f);
    data[0] = diagonal;
    data[5] = diagonal;
    data[10] = diagonal;
    data[15] = diagonal;
}


