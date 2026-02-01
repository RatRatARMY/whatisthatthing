cmake_minimum_required(VERSION 4.2)
project(whatisthatthing)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(whatisthatthing main.cpp
        home.cpp
        home.hpp
        home.ui
        sdl3game1_desc.cpp
        sdl3game1_desc.hpp
        sdl3game1_desc.ui
        sdl3game2_desc.cpp
        sdl3game2_desc.hpp
        sdl3game2_desc.ui
        sdl3game3_desc.cpp
        sdl3game3_desc.hpp
        sdl3game3_desc.ui
        sdl3game4_desc.cpp
        sdl3game4_desc.hpp
        sdl3game4_desc.ui
        sdl3game5_desc.cpp
        sdl3game5_desc.hpp
        sdl3game5_desc.ui
        sdl3game6_desc.cpp
        sdl3game6_desc.hpp
        sdl3game6_desc.ui
        login.cpp
        login.hpp
        login.ui
        register.cpp
        register.hpp
        register.ui)
target_link_libraries(whatisthatthing
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

