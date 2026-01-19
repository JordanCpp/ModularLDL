cmake_minimum_required(VERSION 3.31)

project(SDL LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(SDL)

target_sources(SDL PUBLIC FILE_SET CXX_MODULES FILES
    "SDL.ixx"
    "SDL.Types.ixx" 
    "SDL.Init.ixx" 
    "SDL.Rect.ixx" 
    "SDL.Color.ixx" 
    "SDL.Palette.ixx" 
    "SDL.PixelFormat.ixx" 
    "SDL.Surface.ixx" 
    "SDL.Events.ixx" 
    "SDL.Key.ixx" 
    "SDL.Mod.ixx" 
    "SDL.Loader.ixx" 
    "SDL.Error.ixx")

target_link_libraries(SDL LDL_WinAPI)