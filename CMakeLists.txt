cmake_minimum_required(VERSION 3.14)
project(ReisswitzEngine VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Build options
option(BUILD_TESTS "Build tests" ON)
option(BUILD_EXAMPLES "Build examples" ON)

# Find packages
find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(glm REQUIRED)

# Library
add_library(reisswitz_engine STATIC
    src/core/engine.cpp
    src/core/window.cpp
    src/graphics/renderer.cpp
    src/graphics/shader.cpp
    src/graphics/texture.cpp
    src/graphics/sprite.cpp
    src/ecs/entity.cpp
    src/ecs/system.cpp
    src/math/transform.cpp
    src/input/input_manager.cpp
)

target_include_directories(reisswitz_engine PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(reisswitz_engine PUBLIC
    OpenGL::GL
    glfw
    glm::glm
)

# Main executable
add_executable(reisswitz_engine_exe src/main.cpp)
target_link_libraries(reisswitz_engine_exe PRIVATE reisswitz_engine)
set_target_properties(reisswitz_engine_exe PROPERTIES OUTPUT_NAME reisswitz_engine)

# Tests
if(BUILD_TESTS)
    enable_testing()
    find_package(GTest REQUIRED)
    add_subdirectory(tests)
endif()

# Examples
if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

# Installation
install(TARGETS reisswitz_engine reisswitz_engine_exe
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    RUNTIME DESTINATION bin
)

install(DIRECTORY include/ DESTINATION include)
