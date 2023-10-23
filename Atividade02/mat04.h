#ifndef MAT4_H
#define MAT4_H

#include <cmath>
#include <iostream>
#include <stdexcept>

using std::sqrt;

class mat4 {
   public:
    double m[4][4];

    mat4() {
        m[0][0] = 1.0;
        m[0][1] = 0.0;
        m[0][2] = 0.0;
        m[0][3] = 0.0;
        m[1][0] = 0.0;
        m[1][1] = 1.0;
        m[1][2] = 0.0;
        m[1][3] = 0.0;
        m[2][0] = 0.0;
        m[2][1] = 0.0;
        m[2][2] = 1.0;
        m[2][3] = 0.0;
        m[3][0] = 0.0;
        m[3][1] = 0.0;
        m[3][2] = 0.0;
        m[3][3] = 1.0;

    }

    mat4(double a, double b, double c, double d, double e, double f, double g, double h, double i, double j, double k, double l, double n,double o,double p,double q) {
        m[0][0] = a;
        m[0][1] = b;
        m[0][2] = c;
        m[0][3] = d;
        m[1][0] = e;
        m[1][1] = f;
        m[1][2] = g;
        m[1][3] = h;
        m[2][0] = i;
        m[2][1] = j;
        m[2][2] = k;
        m[2][3] = l;
        m[3][0] = n;
        m[3][1] = o;
        m[3][2] = p;
        m[3][3] = q;
    }

    mat4& operator*=(double t) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                m[i][j] *= t;
            }
        }
        return *this;
    }

    mat4& operator/=(double t) {
        if (t == 0.0) {
            throw std::runtime_error("Divisão inválida.");
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                m[i][j] /= t;
            }
        }
        return *this;
    }
};

    mat4 operator+(const mat4& A, const mat4& B) {
        mat4 result;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                result.m[i][j] = A.m[i][j] + B.m[i][j];
            }
        }
    return result;
    }

    mat4 operator-(const mat4& A, const mat4& B) {
        mat4 result;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                result.m[i][j] = A.m[i][j] - B.m[i][j];
            }
        }
        return result;
    }

    mat4 operator*(const mat4& A, const mat4& B) {
        mat4 result;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                result.m[i][j] = 0.0;
                for (int k = 0; k < 4; k++) {
                    result.m[i][j] += A.m[i][k] * B.m[k][j];
                }
            }
        }
        return result;
    }

#endif