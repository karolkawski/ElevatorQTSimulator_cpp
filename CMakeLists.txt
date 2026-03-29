cmake_minimum_required(VERSION 3.16)

if(WIN32 AND NOT CMAKE_CXX_COMPILER)
    set(CMAKE_CXX_COMPILER "cl" CACHE STRING "" FORCE)
    set(CMAKE_C_COMPILER   "cl" CACHE STRING "" FORCE)
endif()

project(ElevatorQTSimulator_cpp LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(ElevatorQTSimulator_cpp
    src/main.cpp
    src/Passenger.cpp
)
target_include_directories(ElevatorQTSimulator_cpp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(ElevatorQTSimulator_cpp PRIVATE Qt6::Widgets)