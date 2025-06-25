cmake_minimum_required(VERSION 3.15)

project(UrnaEletronica VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_EXTENSIONS OFF)

file(GLOB SOURCES "src/*.cpp")

add_executable(urna_eletronica ${SOURCES})

target_include_directories(urna_eletronica PUBLIC include)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(urna_eletronica PRIVATE -Wall -Wextra -Wpedantic)
endif()

message(STATUS "Projeto '${PROJECT_NAME}' configurado para gerar o executável 'urna_eletronica'.")