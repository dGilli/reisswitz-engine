#include "engine/core/window.hpp"

#include <GLFW/glfw3.h>
#include <stdexcept>

namespace engine {
namespace core {

Window::Window(const std::string& title, uint32_t width, uint32_t height)
    : m_title(title)
    , m_width(width)
    , m_height(height)
{
}

Window::~Window() {
    shutdown();
}

bool Window::initialize() {
    if (!glfwInit()) {
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_handle = glfwCreateWindow(
        static_cast<int>(m_width),
        static_cast<int>(m_height),
        m_title.c_str(),
        nullptr,
        nullptr
    );

    if (!m_handle) {
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(m_handle);
    return true;
}

void Window::shutdown() {
    if (m_handle) {
        glfwDestroyWindow(m_handle);
        m_handle = nullptr;
    }
    glfwTerminate();
}

bool Window::shouldClose() const noexcept {
    return m_handle ? glfwWindowShouldClose(m_handle) : true;
}

void Window::swapBuffers() {
    if (m_handle) {
        glfwSwapBuffers(m_handle);
    }
}

void Window::pollEvents() {
    glfwPollEvents();
}

uint32_t Window::getWidth() const noexcept {
    return m_width;
}

uint32_t Window::getHeight() const noexcept {
    return m_height;
}

} // namespace core
} // namespace engine
