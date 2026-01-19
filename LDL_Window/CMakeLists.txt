cmake_minimum_required(VERSION 3.31)

project(LDL_Window LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(LDL_Window)

target_sources(LDL_Window PUBLIC FILE_SET CXX_MODULES FILES
    "LDL.BaseWindow.ixx"
    "LDL.Context.ixx"
    "LDL.ContextMode.ixx"
    "LDL.Enums.ixx"
    "LDL.Eventer.ixx"
    "LDL.Events.ixx"
    "LDL.Formatter.ixx"
    "LDL.IWindow.ixx"
    "LDL.KeyMap.ixx"
    "LDL.KeyMapping.ixx"
    "LDL.Result.ixx"
    "LDL.RingBuffer.ixx"
    "LDL.UtfConverter.ixx"
    "LDL.Vec2.ixx"
    "LDL.Vec2d.ixx"
    "LDL.Vec2f.ixx"
    "LDL.Vec2i.ixx"
    "LDL.Vec2u.ixx"
    "LDL.Window.ixx"
    "LDL.WindowMode.ixx")

if (WIN32)
    target_sources(LDL_Window PUBLIC FILE_SET CXX_MODULES FILES
        "LDL.WinNT.CreateWindow.ixx"
        "LDL.WinNT.KeyMapper.ixx"
        "LDL.WinNT.MainWindow.ixx"
        "LDL.WinNT.WindowError.ixx"
        "LDL.WinNT.WindowSoftware.ixx")

    target_link_libraries(LDL_Window PUBLIC winmm)
elseif (UNIX AND NOT APPLE)
    target_sources(LDL_Window PUBLIC FILE_SET CXX_MODULES FILES
        "LDL.X11.CreateWindow.ixx"
        "LDL.X11.KeyMapper.ixx"
        "LDL.X11.MainWindow.ixx"
        "LDL.X11.WindowSoftware.ixx")

    target_link_libraries(LDL_Window PUBLIC X11 dl)
endif()