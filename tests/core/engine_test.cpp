#include <gtest/gtest.h>

#include "engine/core/engine.hpp"

using namespace engine::core;

TEST(EngineTest, CanCreateEngine) {
    Engine engine("Test", 800, 600);
    EXPECT_EQ(engine.getDeltaTime(), 0.0);
    EXPECT_EQ(engine.getFPS(), 0);
}

TEST(EngineTest, DeltaTimeStartsAtZero) {
    Engine engine("Test", 800, 600);
    EXPECT_DOUBLE_EQ(engine.getDeltaTime(), 0.0);
}
