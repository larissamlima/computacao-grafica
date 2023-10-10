#include <iostream>
#include <cmath>

int main() {
    // Image
    int image_width = 256;
    int image_height = 256;

    // Centro do círculo
    double center_x = image_width / 2.0;
    double center_y = image_height / 2.0;

    // Raio do círculo
    double radius = std::min(center_x, center_y) - 10; // 10 pixels de margem

    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; ++j) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;

        for (int i = 0; i < image_width; ++i) {
            // Calcular a distância do ponto (i, j) ao centro do círculo
            double distance = std::sqrt((i - center_x) * (i - center_x) + (j - center_y) * (j - center_y));

            if (distance <= radius) {
                // Ponto dentro do círculo, atribuir uma cor
                auto r = (i - center_x) / radius; // Coordenada x normalizada
                auto g = (j - center_y) / radius; // Coordenada y normalizada
                auto b = 0.5; // Cor azul constante

                int ir = static_cast<int>(255.999 * r);
                int ig = static_cast<int>(255.999 * g);
                int ib = static_cast<int>(255.999 * b);

                std::cout << ir << ' ' << ig << ' ' << ib << '\n';
            } else {
                // Ponto fora do círculo, atribuir uma cor de fundo (por exemplo, preto)
                std::cout << "100 0 0\n";
            }
        }
    }
    std::clog << "\rDone.                 \n";
}
