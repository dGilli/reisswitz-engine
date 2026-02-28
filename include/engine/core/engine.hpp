#pragma once

#include <cstdint>
#include <memory>
#include <string>

namespace engine {
namespace core {

class Window;

class Engine {
public:
    Engine(const std::string& title, uint32_t width, uint32_t height);
    ~Engine();

    // Non-copyable
    Engine(const Engine&) = delete;
    Engine& operator=(const Engine&) = delete;

    // Movable
    Engine(Engine&&) noexcept = default;
    Engine& operator=(Engine&&) noexcept = default;

    [[nodiscard]] bool initialize();
    void shutdown();

    void run();
    void stop();

    [[nodiscard]] double getDeltaTime() const noexcept;
    [[nodiscard]] uint32_t getFPS() const noexcept;

private:
    void processInput();
    void update(double deltaTime);
    void render();

    std::unique_ptr<Window> m_window;
    bool m_running = false;
    double m_deltaTime = 0.0;
    uint32_t m_fps = 0;
};

} // namespace core
} // namespace engine
