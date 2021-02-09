cmake_minimum_required(VERSION 3.1  FATAL_ERROR)

project(qnetworktoy CXX)

# Find Qt 5, turn on some conveniences
find_package(Qt5 COMPONENTS Widgets Network)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Use modern C++
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Build a simple project
set(sources main.cpp mainwindow.cpp network.cpp)
add_executable(qnetworktoy ${sources})
target_link_libraries(qnetworktoy Qt5::Widgets Qt5::Network)
