cmake_minimum_required(VERSION 3.17)
project(PruebaQT)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "/home/oscarmg310")

find_package(Qt5 COMPONENTS Core Widgets Gui Multimedia REQUIRED)

set(CMAKE_AUTOMOC ON)

add_executable(OdysseyRadio main.cpp "CSV Managing/Reader.cpp" "CSV Managing/Reader.h" Interface/main.cpp Interface/widget.cpp Interface/widget.h Interface/widget.ui)
target_link_libraries(OdysseyRadio Qt5::Widgets Qt5::Core Qt5::Gui Qt5::Multimedia) 
