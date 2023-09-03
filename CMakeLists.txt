cmake_minimum_required(VERSION 3.14)
project(HelloSFML)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(SOURCE_FILES src/main.cpp)
add_executable(HelloSFML ${SOURCE_FILES})
include_directories(/usr/local/include)
include_directories(include)

find_package(SFML 2.6 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
message("${SFML_INCLUDE_DIRS}")
target_link_libraries(HelloSFML sfml-system sfml-window sfml-graphics sfml-audio sfml-network)


add_executable(ColliderCheck src/CollisionChecker.cpp)