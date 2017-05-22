cmake_minimum_required(VERSION 3.5)
project(ed)

SET(CMAKE_C_COMPILER "g++")
set(CMAKE_CXX_STANDARD 11)

include_directories(./include /usr/include)
link_libraries("/usr/lib/x86_64-linux-gnu/librt.so")
link_libraries("/usr/lib/x86_64-linux-gnu/libcrypto.a")
link_directories(/lib/x86_64-linux-gnu)

set(SOURCE_FILES main.cpp)
add_executable(ed ${SOURCE_FILES})