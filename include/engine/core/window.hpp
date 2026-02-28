#pragma once

#include <cstdint>
#include <string>

struct GLFWwindow;

namespace engine {
namespace core {

class Window {
public:
    Window(const std::string& title, uint32_t width, uint32_t height);
    ~Window();

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;
    Window(Window&&) noexcept = default;
    Window& operator=(Window&&) noexcept = default;

    bool initialize();
    void shutdown();

    [[nodiscard]] bool shouldClose() const noexcept;
    void swapBuffers();
    void pollEvents();

    [[nodiscard]] uint32_t getWidth() const noexcept;
    [[nodiscard]] uint32_t getHeight() const noexcept;

private:
    GLFWwindow* m_handle = nullptr;
    std::string m_title;
    uint32_t m_width;
    uint32_t m_height;
};

} // namespace core
} // namespace engine
