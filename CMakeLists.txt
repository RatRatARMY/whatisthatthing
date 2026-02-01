cmake_minimum_required(VERSION 4.2)
project(whatisthatthing)
option(VENDOR_LIBS_MODE "Use vendor libs instead of system libs" ON)
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
if(VENDOR_LIBS_MODE)
    add_subdirectory(vendor/SDL EXCLUDE_FROM_ALL)
    add_subdirectory(vendor/SDL_image EXCLUDE_FROM_ALL)
    add_subdirectory(vendor/SDL_ttf EXCLUDE_FROM_ALL)
    add_subdirectory(vendor/SDL_mixer EXCLUDE_FROM_ALL)
else()
    find_package(SDL3 REQUIRED)
    find_package(SDL3_image REQUIRED)
    find_package(SDL3_ttf REQUIRED)
    find_package(SDL3_mixer REQUIRED)
endif()
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
add_library(games SHARED
        sdl3game1.cpp
        sdl3game1.hpp
        sdl3game2.cpp
        sdl3game2.hpp
        sdl3game3.cpp
        sdl3game3.hpp
        sdl3game4.cpp
        sdl3game4.hpp
        sdl3game5.cpp
        sdl3game5.hpp
        sdl3game6.cpp
        sdl3game6.hpp
)
target_link_libraries(games PRIVATE
        SDL3::SDL3
        SDL3_image::SDL3_image
        SDL3_ttf::SDL3_ttf
        SDL3_mixer::SDL3_mixer
)
target_link_libraries(whatisthatthing
        Qt::Core
        Qt::Gui
        Qt::Widgets
        games
)

