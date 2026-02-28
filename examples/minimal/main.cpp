#include "engine/core/engine.hpp"
#include <iostream>

int main() {
    std::cout << "Minimal example starting...\n";
    
    engine::core::Engine game("Minimal Example", 800, 600);
    
    if (!game.initialize()) {
        std::cerr << "Failed to initialize\n";
        return 1;
    }
    
    // Run for a few seconds then exit
    // TODO: Add actual example logic
    
    return 0;
}
