cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(field VERSION 1.0)

find_package(SFML COMPONENTS system window graphics network audio)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(${PROJECT_NAME} ${SRC_FILES})
target_link_libraries(${PROJECT_NAME} sfml-graphics sfml-window sfml-system)
target_include_directories(${PROJECT_NAME} PUBLIC include)
