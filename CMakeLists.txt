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

add_executable(exec)
set_target_properties(exec PROPERTIES OUTPUT_NAME keyper)

add_subdirectory(src)

target_link_libraries(exec keyper)
