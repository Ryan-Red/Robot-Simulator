cmake_minimum_required(VERSION 3.14)

set(TARGET_NAME AStarGenerator)

project(${TARGET_NAME})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")


# set(SOURCE_FILES src/main.cpp)

set(MODULES_DIR ${CMAKE_SOURCE_DIR}/src)

add_executable(${TARGET_NAME}
                ${MODULES_DIR}/main.cpp
                ${MODULES_DIR}/AStar.cpp
                ${MODULES_DIR}/CollisionChecker.cpp
                ${MODULES_DIR}/KNN.cpp
                ${MODULES_DIR}/node.cpp
                ${MODULES_DIR}/distance.cpp
                ${MODULES_DIR}/robot.cpp
                ${MODULES_DIR}/trajectoryRollout.cpp

)

include_directories(/usr/local/include)
include_directories(include)

find_package(SFML 2.6 COMPONENTS system window graphics network audio REQUIRED)
find_package(Eigen3 3.3 REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
include_directories(${EIGEN3_INCLUDE_DIRS})
# message("${SFML_INCLUDE_DIRS}")


target_link_libraries(${TARGET_NAME} 
                        sfml-system 
                        sfml-window 
                        sfml-graphics 
                        sfml-audio 
                        sfml-network
                        Eigen3::Eigen)


# add_executable(ColliderCheck src/CollisionChecker.cpp)