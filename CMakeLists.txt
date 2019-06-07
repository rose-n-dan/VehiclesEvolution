#
# Created by SpiritStudio on 28.11.18.
#

cmake_minimum_required(VERSION 2.6)
project(VehiclesEvolution)

include_directories(.)
include_directories(include)

set(CMAKE_CXX_STANDARD 14)

# Define sources and executable
set(EXECUTABLE_NAME "VehiclesEvolution")

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(Box2D REQUIRED) # tested on 2.3.1
find_package(SFML 2 REQUIRED COMPONENTS system window graphics network audio) # tested on 2.4.2
find_package(TGUI 0.8 REQUIRED) # tested on 0.8.5

include_directories(${SFML_INCLUDE_DIR} ${TGUI_INCLUDE_DIR})

add_executable(${EXECUTABLE_NAME}
        src/main.cpp src/Physics/Physics.cpp src/Physics/Car.cpp src/Physics/Map.cpp
        src/EvolutionaryAlgorithm/CarParameters.cpp src/Graphics/Graphics.cpp
        src/EvolutionaryAlgorithm/EvolutionaryAlgorithm.cpp src/Graphics/CarGraphics.cpp src/Graphics/MapGraphics.cpp
        src/Physics/CarBody.cpp src/Physics/Wheel.cpp src/Graphics/GraphicalUserInterface.cpp src/Utils.cpp)

target_link_libraries(${EXECUTABLE_NAME}
                      ${SFML_LIBRARIES} ${SFML_DEPENDENCIES}
                      ${BOX2D_LIBRARIES}
                      ${TGUI_LIBRARY}
                      ${GTEST_LIBRARIES})
