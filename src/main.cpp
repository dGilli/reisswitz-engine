#include "engine/core/engine.hpp"

#include <iostream>

int main() {
    engine::core::Engine game("Reisswitz Engine", 1280, 720);
    
    if (!game.initialize()) {
        std::cerr << "Failed to initialize engine\n";
        return 1;
    }
    
    std::cout << "Engine initialized successfully\n";
    std::cout << "Press ESC to exit\n";
    
    game.run();
    
    return 0;
}
