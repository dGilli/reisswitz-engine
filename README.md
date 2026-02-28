# Reisswitz Engine

A minimal C++ 2D top-down game engine for desktop platforms.

## Building

```bash
# Configure
mkdir -p build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release

# Build
cmake --build . -j$(nproc)

# Run
./reisswitz_engine
```

## Testing

```bash
# All tests
ctest --output-on-failure

# Single test
ctest -R EntityTest --output-on-failure
```

## Roadmap

### Phase 1: Core Foundation
- [ ] Window management (GLFW)
- [ ] OpenGL context and basic rendering
- [ ] 2D sprite rendering system
- [ ] Basic input handling (keyboard, mouse)
- [ ] Delta time and game loop

### Phase 2: ECS Architecture
- [ ] Entity Component System basics
- [ ] Transform components
- [ ] Sprite components
- [ ] Movement systems
- [ ] Simple collision detection

### Phase 3: Top-Down Features
- [ ] Tilemap rendering
- [ ] Camera system with pan/zoom
- [ ] Orthographic projection
- [ ] Basic lighting (optional)
- [ ] Sprite sorting by Y-position

### Phase 4: Polish
- [ ] Asset loading (textures, spritesheets)
- [ ] Animation system
- [ ] Audio support
- [ ] Debug visualization

## Project Structure

```
reisswitz-engine/
├── include/engine/     # Public headers
├── src/               # Implementation
├── tests/             # Unit tests
├── examples/          # Example projects
├── assets/            # Default assets
└── build/             # Build output (gitignored)
```

## Dependencies

- CMake 3.14+
- C++20 compiler (GCC 10+, Clang 12+, MSVC 2019+)
- OpenGL 3.3+
- GLFW3
- GLM
- GTest (for tests)

## License

MIT
