#include "color.h"
#include "vec04.h"
#include <vector>

#include <iostream>

// Classe genérica que representa uma matriz ou vetor
template <typename T, int Rows, int Cols>
class GenericMatrix {
private:
    std::vector<std::vector<T>> data;

public:
    GenericMatrix() {
        data.resize(Rows, std::vector<T>(Cols, T(0)));
    }

    GenericMatrix(T initialValue) {
        data.resize(Rows, std::vector<T>(Cols, initialValue));
    }

    void set(int row, int col, T value) {
        data[row][col] = value;
    }

    T get(int row, int col) const {
        return data[row][col];
    }

    int numRows() const {
        return Rows;
    }

    int numCols() const {
        return Cols;
    }

    GenericMatrix<T, Rows, Cols> operator+(const GenericMatrix<T, Rows, Cols>& other) const {
        GenericMatrix<T, Rows, Cols> result;

        for (int i = 0; i < Rows; i++) {
            for (int j = 0; j < Cols; j++) {
                result.set(i, j, data[i][j] + other.get(i, j));
            }
        }

        return result;
    }

    GenericMatrix<T, Rows, Cols> operator-(const GenericMatrix<T, Rows, Cols>& other) const {
        GenericMatrix<T, Rows, Cols> result;

        for (int i = 0; i < Rows; i++) {
            for (int j = 0; j < Cols; j++) {
                result.set(i, j, data[i][j] - other.get(i, j));
            }
        }

        return result;
    }

    GenericMatrix<T, Rows, Cols> operator*(T scalar) const {
        GenericMatrix<T, Rows, Cols> result;

        for (int i = 0; i < Rows; i++) {
            for (int j = 0; j < Cols; j++) {
                result.set(i, j, data[i][j] * scalar);
            }
        }

        return result;
    }

    void print() const {
        for (int i = 0; i < Rows; i++) {
            for (int j = 0; j < Cols; j++) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {

    // Image

    int image_width = 256;
    int image_height = 256;

    // Inicialização de uma matriz 2x2
    GenericMatrix<double, 2, 2> matrix2x2(1.0);

    // Inicialização de uma matriz 4x4
    GenericMatrix<double, 4, 4> matrix4x4(0.0);

    // Inicialização de um vetor 3D (matriz 3x1)
    GenericMatrix<double, 3, 1> vector3D(0.0);


    // Render

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; ++j) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            auto pixel_color = color(double(i)/(image_width-1), double(j)/(image_height-1), 0);
            write_color(std::cout, pixel_color);
        }
    }

    std::clog << "\rDone.                 \n";
}