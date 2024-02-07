#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "glm/glm.hpp"

class ObjLoader {
public:
    ObjLoader(const std::string& filename) : filename(filename) {}

    bool load() {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Erro ao abrir o arquivo: " << filename << std::endl;
            return false;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string token;
            iss >> token;

            if (token == "v") {
                glm::vec3 vertex;
                iss >> vertex.x >> vertex.y >> vertex.z;
                vertices.push_back(vertex);
            } else if (token == "f") {
                std::vector<int> faceIndices;
                int index;
                while (iss >> index) {
                    faceIndices.push_back(index - 1);
                }
                faces.push_back(faceIndices);
            }
        }

        file.close();
        return true;
    }

    const std::vector<glm::vec3>& getVertices() const {
        return vertices;
    }

    const std::vector<std::vector<int>>& getFaces() const {
        return faces;
    }

    void printData() const {
        std::cout << "Vertices:\n";
        for (const auto& vertex : vertices) {
            std::cout << "v " << vertex.x << " " << vertex.y << " " << vertex.z << std::endl;
        }

        std::cout << "Faces:\n";
        for (const auto& face : faces) {
            std::cout << "f ";
            for (const auto& index : face) {
                std::cout << index + 1 << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    std::string filename;
    std::vector<glm::vec3> vertices;
    std::vector<std::vector<int>> faces;
};

int main() {
    ObjLoader objLoader("Modelo obj/plant_modeling.obj");
    if (objLoader.load()) {
        objLoader.printData();
    }

    return 0;
}
