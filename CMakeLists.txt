cmake_minimum_required(VERSION 3.31)
project(3DRenderer)

set(CMAKE_CXX_STANDARD 20)


# Enable FetchContent
include(FetchContent)

# Fetch GLFW
FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG latest
)
FetchContent_MakeAvailable(glfw)

add_library(glad STATIC external/glad/src/glad.c)
target_include_directories(glad PUBLIC external/glad/include)

add_library(stb_image STATIC external/image/src/stb_image.cpp)
target_include_directories(stb_image PUBLIC external/image/include/stb_image.h)

# Fetch GLM
FetchContent_Declare(
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        GIT_TAG 0.9.9.8
)
FetchContent_MakeAvailable(glm)

# Fetch stb (header only, just needed as source dir)
FetchContent_Declare(
        stb
        GIT_REPOSITORY https://github.com/nothings/stb.git
)
FetchContent_MakeAvailable(stb)

set(IMGUI_SOURCES
        external/imgui/imgui.cpp
        external/imgui/imgui_draw.cpp
        external/imgui/imgui_widgets.cpp
        external/imgui/imgui_tables.cpp
        external/imgui/imgui_demo.cpp
        external/imgui/backends/imgui_impl_glfw.cpp
        external/imgui/backends/imgui_impl_opengl3.cpp
)

add_library(imgui STATIC ${IMGUI_SOURCES})
target_include_directories(imgui PUBLIC
        external/imgui
        external/imgui/backends
        ${glfw_SOURCE_DIR}/include
)

add_executable(3DRenderer
        src/main.cpp
        src/core/Window.cpp
        src/core/Shader.cpp
        src/objects/Mesh.cpp
        src/core/Scene.cpp
        src/core/Renderer.cpp
        src/core/Camera.cpp
        src/core/UI.cpp
        src/objects/Level.cpp
        src/core/ResourceManager.cpp
        src/core/ArkEngine.cpp
)

# Include directories
target_include_directories(3DRenderer PRIVATE
        ${glfw_SOURCE_DIR}/include
        ${glm_SOURCE_DIR}
        ${stb_SOURCE_DIR}
)

# Link libraries
target_link_libraries(3DRenderer
        glfw
        glad
        glm
        stb_image
        ${OPENGL_gl_LIBRARY}
        imgui
)

# On some systems, you may need to link OpenGL manually
find_package(OpenGL REQUIRED)
target_link_libraries(3DRenderer ${OPENGL_gl_LIBRARY})