#pragma once

#include <array>

class Mat4 {
public:
    Mat4();
    Mat4(const std::array<float, 16>& data);
    Mat4(float diagonal);


    static Mat4 identity();
    static Mat4 translation(float x, float y, float z);
    static Mat4 scaling(float x, float y, float z);

    std::array<float, 16> data;

    static Mat4 orthographic(float left, float right, float bottom, float top, float near, float far) {
        Mat4 result(1.0f);
        result.data[0 + 0 * 4] = 2.0f / (right - left);
        result.data[1 + 1 * 4] = 2.0f / (top - bottom);
        result.data[2 + 2 * 4] = -2.0f / (far - near);

        result.data[0 + 3 * 4] = -(right + left) / (right - left);
        result.data[1 + 3 * 4] = -(top + bottom) / (top - bottom);
        result.data[2 + 3 * 4] = -(far + near) / (far - near);

        return result;
    }


};
