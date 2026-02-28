cmake_minimum_required(VERSION 3.14)

enable_testing()

find_package(GTest REQUIRED)

add_executable(engine_tests
    test_main.cpp
    ecs/entity_test.cpp
    core/engine_test.cpp
)

target_link_libraries(engine_tests PRIVATE
    reisswitz_engine
    GTest::gtest
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(engine_tests)
