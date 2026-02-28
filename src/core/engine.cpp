#include "engine/core/engine.hpp"
#include "engine/core/window.hpp"

#include <iostream>
#include <chrono>

namespace engine {
namespace core {

Engine::Engine(const std::string& title, uint32_t width, uint32_t height)
    : m_window(std::make_unique<Window>(title, width, height))
{
}

Engine::~Engine() {
    shutdown();
}

bool Engine::initialize() {
    if (!m_window || !m_window->initialize()) {
        std::cerr << "Failed to initialize window\n";
        return false;
    }
    
    m_running = true;
    return true;
}

void Engine::shutdown() {
    m_running = false;
    if (m_window) {
        m_window->shutdown();
    }
}

void Engine::run() {
    using Clock = std::chrono::high_resolution_clock;
    using Duration = std::chrono::duration<double>;
    
    auto lastTime = Clock::now();
    double accumulatedTime = 0.0;
    uint32_t frameCount = 0;
    
    while (m_running && !m_window->shouldClose()) {
        auto currentTime = Clock::now();
        m_deltaTime = std::chrono::duration<double>(currentTime - lastTime).count();
        lastTime = currentTime;
        
        accumulatedTime += m_deltaTime;
        frameCount++;
        
        if (accumulatedTime >= 1.0) {
            m_fps = frameCount;
            frameCount = 0;
            accumulatedTime -= 1.0;
        }
        
        processInput();
        update(m_deltaTime);
        render();
        
        m_window->swapBuffers();
        m_window->pollEvents();
    }
}

void Engine::stop() {
    m_running = false;
}

double Engine::getDeltaTime() const noexcept {
    return m_deltaTime;
}

uint32_t Engine::getFPS() const noexcept {
    return m_fps;
}

void Engine::processInput() {
    // TODO: Implement input processing
}

void Engine::update(double deltaTime) {
    (void)deltaTime;
    // TODO: Implement game update logic
}

void Engine::render() {
    // TODO: Implement rendering
}

} // namespace core
} // namespace engine
