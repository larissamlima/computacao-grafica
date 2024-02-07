#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "glm/glm.hpp"
#include "modelo_obj.cpp"
#include <cassert>

// Teste para verificar se o arquivo .obj é aberto com sucesso
void testFileOpen() {
    ObjLoader objLoader("Modelo obj/plant_modeling.obj");
    bool result = objLoader.load();
    assert(result == true);
}

// Teste para verificar se os vértices são carregados corretamente
void testVertexLoading() {
    ObjLoader objLoader("Modelo obj/plant_modeling.obj");
    objLoader.load();
    const std::vector<glm::vec3>& vertices = objLoader.getVertices();
    assert(vertices.size() > 0);
}

// Teste para verificar se as faces são carregadas corretamente
void testFaceLoading() {
    ObjLoader objLoader("Modelo obj/plant_modeling.obj");
    objLoader.load();
    const std::vector<std::vector<int>>& faces = objLoader.getFaces();
    assert(faces.size() > 0);
}

