#include <gtest/gtest.h>

#include <cstdint>

// Simple entity ID type for testing
using EntityId = uint32_t;
constexpr EntityId kInvalidEntity = 0;

TEST(EntityTest, EntityIdIsValidType) {
    EntityId entity = 1;
    EXPECT_GT(entity, kInvalidEntity);
}

TEST(EntityTest, InvalidEntityIsZero) {
    EXPECT_EQ(kInvalidEntity, 0);
}
