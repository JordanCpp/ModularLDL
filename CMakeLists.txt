cmake_minimum_required(VERSION 3.31)

project(SDL LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT Embedded)
set(CMAKE_EXE_LINKER_FLAGS_DEBUG          "/INCREMENTAL:NO")
set(CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO "/INCREMENTAL:NO")
set(CMAKE_EXE_LINKER_FLAGS_RELEASE        "/INCREMENTAL:NO")

set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT Embedded)
set(CMAKE_MSVC_RUNTIME_LIBRARY_DEFAULT "") 

if(MSVC)
    foreach(flag_var
        CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
        CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
        string(REPLACE "/RTC1" "" ${flag_var} "${${flag_var}}")
        string(REPLACE "/Od"   "" ${flag_var} "${${flag_var}}")
        string(REPLACE "/MDd"  "" ${flag_var} "${${flag_var}}")
        string(REPLACE "/MD"   "" ${flag_var} "${${flag_var}}")
        string(REPLACE "/MTd"  "" ${flag_var} "${${flag_var}}")
        string(REPLACE "/MT"   "" ${flag_var} "${${flag_var}}")
    endforeach()
endif()
set(CMAKE_GENERATOR_PLATFORM Win32)
set(CUSTOM_LINKER "${CMAKE_CURRENT_SOURCE_DIR}/make/link.exe")

set(BUILD_EXE
    SDL1
    GraphicsExample
    ExampleVector
    ExampleString
    main)

set(CMAKE_CXX_LINK_EXECUTABLE "\"${CUSTOM_LINKER}\" <CMAKE_CXX_LINK_FLAGS> <LINK_FLAGS> <OBJECTS> /OUT:<TARGET> <LINK_LIBRARIES>")

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/SDL/SDL.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)

foreach(BUILD_EXE ${BUILD_EXE})
add_executable(${BUILD_EXE} "${BUILD_EXE}.cpp")

include_directories("LDL_stdcpp/stdcpp")
include_directories("LDL_stdcpp/source")

target_sources(${BUILD_EXE} PUBLIC FILE_SET CXX_MODULES FILES
    "LDL_WinAPI/LDL.WinAPI.ixx"
    "LDL_WinAPI/LDL.WinAPI.Types.ixx"
    "LDL_WinAPI/LDL.WinAPI.Kernel32.ixx"
    "LDL_WinAPI/LDL.WinAPI.User32.ixx")

target_sources(${BUILD_EXE} PUBLIC FILE_SET CXX_MODULES FILES
    "SDL/SDL.ixx"
    "SDL/SDL.Types.ixx" 
    "SDL/SDL.Init.ixx" 
    "SDL/SDL.Rect.ixx" 
    "SDL/SDL.Color.ixx" 
    "SDL/SDL.Palette.ixx" 
    "SDL/SDL.PixelFormat.ixx" 
    "SDL/SDL.Surface.ixx" 
    "SDL/SDL.Events.ixx" 
    "SDL/SDL.Key.ixx" 
    "SDL/SDL.Mod.ixx" 
    "SDL/SDL.Loader.ixx" 
    "SDL/SDL.Error.ixx")

target_sources(${BUILD_EXE} PUBLIC 
    "LDL_stdcpp/source/windows/system.cpp" 
    "LDL_stdcpp/source/memory.cpp" 
    "LDL_stdcpp/source/string.cpp" 
    "LDL_stdcpp/source/ostream.cpp")

target_sources(${BUILD_EXE} PUBLIC FILE_SET CXX_MODULES FILES 
    "Framework/Framework.ixx"
    "Framework/SDL1.Graphics.ixx"
    "Framework/SDL1.Events.ixx")


target_compile_options(${BUILD_EXE} PRIVATE /O2 /arch:IA32 /GS- /Zc:threadSafeInit- /GR- /EHa- /kernel /d2FH4-)

set_target_properties(${BUILD_EXE} PROPERTIES 
    MSVC_INCREMENTAL_LINKING OFF
    LINKER_LANGUAGE CXX)

target_link_options(${BUILD_EXE} PRIVATE 
    "/SUBSYSTEM:CONSOLE,4.0" 
    "/NODEFAULTLIB" 
    "/ENTRY:EntryPoint")

target_link_libraries(${BUILD_EXE} PRIVATE kernel32.lib user32.lib)
endforeach()