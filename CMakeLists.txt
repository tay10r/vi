cmake_minimum_required(VERSION 3.14.7)

project(vi)

find_package(GTest REQUIRED)

add_library(vi INTERFACE)

target_include_directories(vi INTERFACE "${PROJECT_SOURCE_DIR}")

target_compile_features(vi INTERFACE cxx_std_17)

add_executable(vi_tests
   tests/bounding_box.cpp
   tests/split_lines.cpp
   tests/open_file.cpp)

target_compile_definitions(vi_tests PRIVATE PROJECT_SOURCE_DIR="\\\"${PROJECT_SOURCE_DIR}\\\"")

target_link_libraries(vi_tests PRIVATE vi GTest::GTest GTest::Main)

add_test(NAME vi_unit_tests COMMAND $<TARGET_FILE:vi_tests>)

enable_testing()
