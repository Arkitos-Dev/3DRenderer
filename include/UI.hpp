#pragma once
#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "Mesh.hpp"
#include "Level.hpp"
#include <map>

class UI {
public:
    UI(GLFWwindow* window);
    ~UI();

    void beginFrame();
    void endFrame();
    void draw(const std::vector<Mesh*>& meshes, const Level& level);

    static const char* typeToString(LevelObject::Type type);
private:
    // ggf. Membervariablen, falls benötigt
};