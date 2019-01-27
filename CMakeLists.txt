cmake_minimum_required(VERSION 3.13)
project(untitled)

set(CMAKE_CXX_STANDARD 14)
include_directories(.)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
set(SDL2_PATH "C:/Program Files (x86)/mingw-w64/i686-8.1.0-posix-dwarf-rt_v6-rev0/mingw32")


find_package(SDL2 REQUIRED)

include_directories("C:/Program Files (x86)/mingw-w64/i686-8.1.0-posix-dwarf-rt_v6-rev0/mingw32/include")
#
#link_directories("C:/Program Files (x86)/mingw-w64/i686-8.1.0-posix-dwarf-rt_v6-rev0/mingw32/lib")

add_executable(untitled main.cpp window.h loader.h variables.h game_functions.h timer.h)
TARGET_LINK_LIBRARIES(untitled "C:/Program Files (x86)/mingw-w64/i686-8.1.0-posix-dwarf-rt_v6-rev0/mingw32/lib")

#target_link_libraries(untitled ${SDL2_LIBRARIES})
