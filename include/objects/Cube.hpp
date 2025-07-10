//
// Created by Anton on 03.07.2025.
//
#pragma once
#include "Mesh.hpp"
#include "Shapes.hpp"
#include "../../include/core/ResourceManager.hpp"

class Cube : public Shapes {
public:
    Cube(const std::vector<Texture>& textures = {}) {
        mesh = std::make_shared<Mesh>(
                GetVertices(),
                GetIndices(),
                textures.empty() ? GetDefaultTextures() : textures
        );
    }
private:
    static std::vector<Texture> GetDefaultTextures() {
        std::vector<Texture> textures;
        // Diffuse-Textur
        Texture diffuse;
        diffuse.id = ResourceManager::GetTexture("resources/images/container2.png");
        diffuse.type = "texture_diffuse";
        diffuse.path = "resources/images/container2.png";
        textures.push_back(diffuse);

        // Specular-Textur
        Texture specular;
        specular.id = ResourceManager::GetTexture("resources/images/container2_specular.png");
        specular.type = "texture_specular";
        specular.path = "resources/images/container2_specular.png";
        textures.push_back(specular);

        return textures;
    }

    static std::vector<Vertex> GetVertices() {
        static const float rawVertices[] = {
                // Position         // Normal        // TexCoords
                0.5f, -0.5f, -0.5f,  0, 0,-1,  0.0f, 1.0f,
                -0.5f, -0.5f, -0.5f,  0, 0,-1,  1.0f, 1.0f,
                -0.5f,  0.5f, -0.5f,  0, 0,-1,  1.0f, 0.0f,
                0.5f,  0.5f, -0.5f,  0, 0,-1,  0.0f, 0.0f,
                -0.5f, -0.5f,  0.5f,  0, 0, 1,  0.0f, 1.0f,
                0.5f, -0.5f,  0.5f,  0, 0, 1,  1.0f, 1.0f,
                0.5f,  0.5f,  0.5f,  0, 0, 1,  1.0f, 0.0f,
                -0.5f,  0.5f,  0.5f,  0, 0, 1,  0.0f, 0.0f,
                -0.5f, -0.5f, -0.5f, -1, 0, 0,  0.0f, 1.0f,
                -0.5f, -0.5f,  0.5f, -1, 0, 0,  1.0f, 1.0f,
                -0.5f,  0.5f,  0.5f, -1, 0, 0,  1.0f, 0.0f,
                -0.5f,  0.5f, -0.5f, -1, 0, 0,  0.0f, 0.0f,
                0.5f, -0.5f,  0.5f,  1, 0, 0,  0.0f, 1.0f,
                0.5f, -0.5f, -0.5f,  1, 0, 0,  1.0f, 1.0f,
                0.5f,  0.5f, -0.5f,  1, 0, 0,  1.0f, 0.0f,
                0.5f,  0.5f,  0.5f,  1, 0, 0,  0.0f, 0.0f,
                -0.5f, -0.5f, -0.5f,  0,-1, 0,  0.0f, 1.0f,
                0.5f, -0.5f, -0.5f,  0,-1, 0,  1.0f, 1.0f,
                0.5f, -0.5f,  0.5f,  0,-1, 0,  1.0f, 0.0f,
                -0.5f, -0.5f,  0.5f,  0,-1, 0,  0.0f, 0.0f,
                -0.5f,  0.5f,  0.5f,  0, 1, 0,  0.0f, 1.0f,
                0.5f,  0.5f,  0.5f,  0, 1, 0,  1.0f, 1.0f,
                0.5f,  0.5f, -0.5f,  0, 1, 0,  1.0f, 0.0f,
                -0.5f,  0.5f, -0.5f,  0, 1, 0,  0.0f, 0.0f
        };
        std::vector<Vertex> vertices;
        for (size_t i = 0; i < 24; ++i) {
            Vertex v;
            v.position = glm::vec3(rawVertices[i * 8 + 0], rawVertices[i * 8 + 1], rawVertices[i * 8 + 2]);
            v.normal   = glm::vec3(rawVertices[i * 8 + 3], rawVertices[i * 8 + 4], rawVertices[i * 8 + 5]);
            v.texCoords= glm::vec2(rawVertices[i * 8 + 6], rawVertices[i * 8 + 7]);
            vertices.push_back(v);
        }
        return vertices;
    }

    static std::vector<unsigned int> GetIndices() {
        static const unsigned int idx[] = {
                0, 1, 2, 0, 2, 3,    // Rückseite
                4, 5, 6, 4, 6, 7,    // Vorderseite
                8, 9,10, 8,10,11,    // Links
                12,13,14,12,14,15,   // Rechts
                16,17,18,16,18,19,   // Unten
                20,21,22,20,22,23    // Oben
        };
        return std::vector<unsigned int>(idx, idx + 36);
    }
};
