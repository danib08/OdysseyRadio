cmake_minimum_required(VERSION 3.17)
project(OdysseyRadio)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_PREFIX_PATH "/home/dani/Qt/5.15.1/gcc_64/cmake")

find_package(Qt5 COMPONENTS Core Widgets Gui REQUIRED)

set(CMAKE_AUTOMOC ON)

add_executable(OdysseyRadio main.cpp "CSV Managing/Reader.cpp" "CSV Managing/Reader.h")
target_link_libraries(OdysseyRadio Qt5::Widgets Qt5::Core Qt5::Gui)