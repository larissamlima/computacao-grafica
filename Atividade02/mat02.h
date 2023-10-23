#ifndef MAT2_H
#define MAT2_H

#include <cmath>
#include <iostream>

using std::sqrt;

class mat2 {
   public:
    double m[2][2];

    mat2() {
        m[0][0] = 1.0;
        m[0][1] = 0.0;
        m[1][0] = 0.0;
        m[1][1] = 1.0;
    }

    mat2(double a, double b, double c, double d) {
        m[0][0] = a;
        m[0][1] = b;
        m[1][0] = c;
        m[1][1] = d;
    }

    mat2& operator*=(double t) {
        m[0][0] *= t;
        m[1][0] *= t;
        m[0][1] *= t;
        m[1][1] *= t;
        return *this;
    }

    mat2& operator/=(double t) {
        if (t == 0.0) {
            throw std::runtime_error("Divisão inválida.");
        }

        m[0][0] /= t;
        m[1][0] /= t;
        m[0][1] /= t;
        m[1][1] /= t;
        return *this;
    }
};

#endif