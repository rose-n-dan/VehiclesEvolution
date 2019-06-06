#
# Created by SpiritStudio on 04.12.18.
#

cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 14)

set(GTEST_LIBRARIES "${PROJECT_SOURCE_DIR}/../lib/libgtest.a"
                    "${PROJECT_SOURCE_DIR}/../lib/libgtest_main.a")

include_directories(..)
include_directories(../include)

set(EXECUTABLE_NAME "runTests")
set(TEST_SOURCES "gtest.cpp" "src/Car.cpp" "src/Map.cpp" "src/Utils.cpp")

add_executable(${EXECUTABLE_NAME} ${TEST_SOURCES} ../src/Physics/Physics.cpp ../src/Physics/Car.cpp ../src/Physics/Map.cpp
        ../src/EvolutionaryAlgorithm/CarParameters.cpp ../src/Graphics/Graphics.cpp
        ../src/EvolutionaryAlgorithm/EvolutionaryAlgorithm.cpp ../src/Graphics/CarGraphics.cpp
        ../src/Graphics/MapGraphics.cpp ../src/Physics/CarBody.cpp ../src/Physics/Wheel.cpp
        ../src/Graphics/GraphicalUserInterface.cpp ../src/Utils.cpp)

set(TGUI_LIBRARIES "${PROJECT_SOURCE_DIR}/../lib/libtgui.so")

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/../cmake_modules" ${CMAKE_MODULE_PATH})
find_package(Box2D REQUIRED) # tested on 2.3.1
find_package(SFML 2 REQUIRED COMPONENTS system window graphics network audio) # tested on 2.4.2

target_link_libraries(${EXECUTABLE_NAME}
        ${GTEST_LIBRARIES}
        ${SFML_LIBRARIES}
        ${BOX2D_LIBRARIES} ${SFML_DEPENDENCIES}
        ${TGUI_LIBRARIES}
        pthread)
