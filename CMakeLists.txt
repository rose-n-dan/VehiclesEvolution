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

add_executable(${EXECUTABLE_NAME}
        src/main.cpp src/Physics/Physics.cpp src/Physics/Car.cpp src/Physics/Map.cpp
        src/EvolutionaryAlgorithm/CarParameters.cpp src/Graphics/Graphics.cpp
        src/EvolutionaryAlgorithm/EvolutionaryAlgorithm.cpp src/Graphics/CarGraphics.cpp src/Graphics/MapGraphics.cpp
        src/Physics/CarBody.cpp src/Physics/Wheel.cpp src/Graphics/GraphicalUserInterface.cpp src/Utils.cpp)

set(SFML_LIBRARIES "${PROJECT_SOURCE_DIR}/lib/libsfml-graphics.so"
                   "${PROJECT_SOURCE_DIR}/lib/libsfml-window.so"
                   "${PROJECT_SOURCE_DIR}/lib/libsfml-system.so")
set(BOX2D_LIBRARIES "${PROJECT_SOURCE_DIR}/lib/libBox2D.a")
set(TGUI_LIBRARIES "${PROJECT_SOURCE_DIR}/lib/libtgui.so")
set(GTEST_LIBRARIES "${PROJECT_SOURCE_DIR}/lib/libgtest.a"
                    "${PROJECT_SOURCE_DIR}/lib/libgtest_main.a")

target_link_libraries(${EXECUTABLE_NAME}
                      ${SFML_LIBRARIES}
                      ${BOX2D_LIBRARIES}
                      ${TGUI_LIBRARIES}
                      ${GTEST_LIBRARIES})



