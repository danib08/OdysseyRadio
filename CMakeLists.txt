cmake_minimum_required(VERSION 3.17)
project(OdysseyRadio)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "/home/oscarmg310")

find_package(Qt5 COMPONENTS Core Widgets Gui Multimedia REQUIRED)

set(CMAKE_AUTOMOC ON)

add_executable(OdysseyRadio main.cpp CSVManaging/Reader.cpp CSVManaging/Reader.h Interface/widget.cpp Interface/widget.h Interface/widget.ui Lists/Node.cpp Lists/Node.h Lists/LinkedList.cpp Lists/LinkedList.h)
target_link_libraries(OdysseyRadio Qt5::Widgets Qt5::Core Qt5::Gui Qt5::Multimedia) 
