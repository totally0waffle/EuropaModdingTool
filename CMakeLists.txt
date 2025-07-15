cmake_minimum_required(VERSION 3.31.6)
project(project_name CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

include_directories("${PROJECT_SOURCE_DIR}")

add_executable(EuropaModdingTool
    "${PROJECT_SOURCE_DIR}/main.cpp"
)

target_link_libraries(EuropaModdingTool PRIVATE m)
