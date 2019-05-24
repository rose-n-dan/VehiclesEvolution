#
# Created by SpiritStudio on 04.12.18.
#

cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_STANDARD 14)

set(GTEST_LIBRARIES "${PROJECT_SOURCE_DIR}/../lib/libgtest.a"
                    "${PROJECT_SOURCE_DIR}/../lib/libgtest_main.a")

include_directories(..)
include_directories(../include)

set(EXECUTABLE_NAME "runTests")

add_executable(${EXECUTABLE_NAME} gtest.cpp ../src/Physics/Physics.cpp ../src/Physics/Car.cpp ../src/Physics/Map.cpp
        ../src/EvolutionaryAlgorithm/CarParameters.cpp ../src/Graphics/Graphics.cpp
        ../src/EvolutionaryAlgorithm/EvolutionaryAlgorithm.cpp ../src/Graphics/CarGraphics.cpp
        ../src/Graphics/MapGraphics.cpp ../src/Physics/CarBody.cpp ../src/Physics/Wheel.cpp
        ../src/Graphics/GraphicalUserInterface.cpp)

set(SFML_LIBRARIES "${PROJECT_SOURCE_DIR}/../lib/libsfml-graphics.so"
                   "${PROJECT_SOURCE_DIR}/../lib/libsfml-window.so"
                   "${PROJECT_SOURCE_DIR}/../lib/libsfml-system.so")
set(BOX2D_LIBRARIES "${PROJECT_SOURCE_DIR}/../lib/libBox2D.a")
set(TGUI_LIBRARIES "${PROJECT_SOURCE_DIR}/../lib/libtgui.so")

target_link_libraries(${EXECUTABLE_NAME}  ${GTEST_LIBRARIES} ${SFML_LIBRARIES}
        ${BOX2D_LIBRARIES}
        ${TGUI_LIBRARIES}
        pthread)
