cmake_minimum_required(VERSION 3.5)

SET(CMAKE_C_COMPILER "g++")
set(CMAKE_CXX_STANDARD 11)

include_directories(../include /usr/include)
link_libraries("/usr/lib/x86_64-linux-gnu/librt.so")
link_libraries("/usr/lib/x86_64-linux-gnu/libcrypto.a")
link_directories(/lib/x86_64-linux-gnu)

message("${CMAKE_SOURCE_DIR}")

set(SOURCE_FILES test_bloom.cpp )

foreach(TEST_FILE ${SOURCE_FILES})
    get_filename_component(TEST_FILE_WE ${TEST_FILE} NAME_WE)
    set(TEST_FILE ${TEST_FILE} ../src/bloom_func.cpp ../include/bloom_func.h)
    add_executable(${TEST_FILE_WE} ${TEST_FILE})
endforeach()