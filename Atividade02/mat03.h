#ifndef MAT3_H
#define MAT3_H

#include <cmath>
#include <iostream>

using std::sqrt;

class mat3 {
   public:
    double m[3][3];

    mat3() {
        m[0][0] = 1.0;
        m[0][1] = 0.0;
        m[0][2] = 0.0;
        m[1][0] = 0.0;
        m[1][1] = 1.0;
        m[1][2] = 0.0;
        m[2][0] = 0.0;
        m[2][1] = 0.0;
        m[2][2] = 1.0;
    }

    mat3(double a, double b, double c, double d, double e, double f, double g, double h, double i) {
        m[0][0] = a;
        m[0][1] = b;
        m[0][2] = c;
        m[1][0] = d;
        m[1][1] = e;
        m[1][2] = f;
        m[2][0] = g;
        m[2][1] = h;
        m[2][2] = i;
    }

    mat3& operator*=(double t) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                m[i][j] *= t;
            }
        }
        return *this;
    }

    mat3& operator/=(double t) {
        if (t == 0.0) {
            throw std::runtime_error("Divisão inválida.");
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                m[i][j] /= t;
            }
        }
        return *this;
    }

    inline mat3 operator+(const mat3& A, const mat3& B) {
    mat3 result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.m[i][j] = A.m[i][j] + B.m[i][j];
        }
    }
    return result;
    }

    inline mat3 operator-(const mat3& A, const mat3& B) {
    mat3 result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.m[i][j] = A.m[i][j] - B.m[i][j];
        }
    }
    return result;
    }

    inline mat3 operator*(const mat3& A, const mat3& B) {
    mat3 result;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.m[i][j] = 0.0;
            for (int k = 0; k < 3; k++) {
                result.m[i][j] += A.m[i][k] * B.m[k][j];
            }
        }
    }
    return result;
    }
};

#endif