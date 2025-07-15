cmake_minimum_required(VERSION 3.31.6)
project(EuropaModdingTool LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. First create the executable target
add_executable(EuropaModdingTool
    "${PROJECT_SOURCE_DIR}/src/main.cpp"
)

# 2. THEN configure its properties
target_compile_options(EuropaModdingTool PRIVATE -pthread -Wall -Wextra -pedantic)

target_include_directories(EuropaModdingTool PRIVATE
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/include
)

# FTXUI dependency
include(FetchContent)
FetchContent_Declare(ftxui
    GIT_REPOSITORY https://github.com/ArthurSonzogni/FTXUI
    GIT_TAG v6.1.9
)
FetchContent_MakeAvailable(ftxui)

target_link_libraries(EuropaModdingTool PRIVATE
    m
    ftxui::screen
    ftxui::dom
    ftxui::component
)
