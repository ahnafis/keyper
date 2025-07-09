cmake_minimum_required(VERSION 4.0)

project(
  keyper
  VERSION 0.0.1
  DESCRIPTION "A tool to manage passwords."
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "-g")
set(CMAKE_EXPORT_COMPILE_COMMANDS True)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_library(keyper STATIC)

add_subdirectory(third_party/json)
set(JSON_BuildTests
    OFF
    CACHE INTERNAL "")

target_link_libraries(keyper PRIVATE nlohmann_json::nlohmann_json)

add_executable(exec)
set_target_properties(exec PROPERTIES OUTPUT_NAME keyper)
target_link_libraries(exec keyper)

include_directories(src)
add_subdirectory(src)

add_executable(test)
add_subdirectory(third_party/doctest)
add_subdirectory(tests)
target_link_libraries(test PRIVATE doctest::doctest keyper
                                   nlohmann_json::nlohmann_json)
