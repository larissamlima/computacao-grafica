#include <iostream>
#include <cmath>

int main() {
    const int image_width = 512;
    const int image_height = 512;

    // Coordenadas dos vértices do triângulo
    int x0 = 256, y0 = 100;
    int x1 = 100, y1 = 400;
    int x2 = 412, y2 = 400;

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; ++j) {

        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;

        for (int i = 0; i < image_width; ++i) {
            // Calcular a distância do ponto (i, j) ao centro do círculo

            double detT = (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);
            double alpha = ((y2 - y0) * (i - x0) + (x0 - x2) * (j - y0)) / detT;
            double beta = ((y0 - y1) * (i - x0) + (x1 - x0) * (j - y0)) / detT;
            double gamma = 1 - alpha - beta;

            if (alpha >= 0 && beta >= 0 && gamma >= 0) {
                // Ponto dentro do triângulo, atribuir uma cor
                auto r = 1.0; // Cor vermelha constante
                auto g = 0.5; // Cor verde constante
                auto b = 0.0; // Cor azul constante

                int ir = static_cast<int>(255.999 * r);
                int ig = static_cast<int>(255.999 * g);
                int ib = static_cast<int>(255.999 * b);

            } else {
                // Ponto fora do triângulo, atribuir uma cor de fundo (por exemplo, preto)
                std::cout << "0 0 0\n";

            }
        }
    }

    std::clog << "\rDone.                 \n";
}
