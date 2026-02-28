# Reisswitz Engine - Agent Guidelines

## Build Commands

```bash
# Configure (Release)
mkdir -p build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release

# Configure (Debug with tests)
cmake .. -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTS=ON

# Build all
cmake --build . -j$(nproc)

# Build specific target
cmake --build . --target reisswitz_engine

# Clean
cmake --build . --target clean
```

## Test Commands

```bash
# Run all tests
ctest --output-on-failure

# Run specific test by pattern
ctest -R EntityTest --output-on-failure

# Verbose test output
ctest -V

# Run from build directory
./tests/engine_tests --gtest_filter="Entity*"
```

## Code Style

### Formatting
- Indent: 4 spaces (no tabs)
- Max line length: 100 characters
- Braces: Allman style, always on new line
- Pointer/reference: `Type* name`, `Type& name` (left-aligned)

### Naming Conventions
- Types: PascalCase (`EntityManager`, `Vector2`)
- Functions/Methods: camelCase (`update`, `getComponent`)
- Variables: camelCase (`entityCount`, `isActive`)
- Member variables: `m_` prefix (`m_position`, `m_velocity`)
- Constants: `k` prefix or ALL_CAPS (`kMaxEntities`, `PI`)
- Macros: ALL_CAPS with namespace prefix (`REISSWITZ_ASSERT`)
- Namespaces: lowercase (`engine`, `graphics`)

### File Organization
- Headers: `include/engine/<module>/<name>.hpp`
- Implementation: `src/<module>/<name>.cpp`
- One class per file (mostly)
- Header guards: `#pragma once`

### Includes
- Order: related header, C++ std, third-party, project
- Use quotes for project headers: `#include "engine/core/engine.hpp"`
- Use angle brackets for external: `#include <GLFW/glfw3.h>`
- Prefer forward declarations in headers

### Types
- Use `std::` types explicitly (no `using namespace std`)
- Fixed-width integers: `int32_t`, `uint32_t` from `<cstdint>`
- Size type: `std::size_t` for container indices/sizes
- Floating point: `float` for graphics, `double` for physics when needed

### Error Handling
- Use exceptions for unrecoverable errors
- Return `std::optional<T>` or `std::expected<T, E>` for recoverable failures
- Assert preconditions with `REISSWITZ_ASSERT` or `assert()`
- Never silently fail - log errors

### Memory Management
- Prefer RAII and smart pointers (`std::unique_ptr`, `std::shared_ptr`)
- Avoid raw `new`/`delete`
- Use `std::make_unique`/`std::make_shared`

### Performance Guidelines
- Pass small types by value, large by const reference
- Mark override methods with `override` keyword
- Use `[[nodiscard]]` for functions returning important values
- Consider `noexcept` for move operations and simple getters

### Documentation
- Document public API in headers with brief descriptions
- Use `///` for Doxygen-style comments
- Document non-obvious algorithmic choices in implementation

## Module Guidelines

### Core
- Engine initialization and main loop
- Window and context management
- Timing and frame rate control

### Graphics
- OpenGL abstraction layer
- Shader management
- Texture loading
- 2D rendering (sprites, tilemaps)

### ECS
- Entity management
- Component storage
- System execution
- No virtual dispatch in hot paths

### Math
- Vector/matrix operations using GLM
- Transform calculations
- Collision primitives

### Input
- GLFW input polling
- Action mapping
- Input state tracking
