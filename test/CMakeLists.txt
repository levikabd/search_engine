cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(gootest VERSION 0.1.0 LANGUAGES C CXX)

#add_subdirectory(googletest)
#target_include_directories(src ./include)

include(FetchContent)
FetchContent_Declare(
googletest
URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip)

#target_link_libraries(search_engine GTest::gtest_main)
#target_link_libraries(search_engine PRIVATE Gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(gootest)

#include_directories(${MY_INCLUDE_DIR})

set(gtest_SOURCE_DIR ${CMAKE_SOURCE_DIR}/googletest)
set(GOOGLETESTDIR ${gtest_SOURCE_DIR}/googletest/include)
#include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


set(gtest_disable_pthreads on)
set(enable-threads posix)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

#set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_library(gootest SHARED test/test.h test/test.cpp)
target_include_directories(gootest PRIVATE ${gtest_SOURCE_DIR}/include)
target_link_libraries(gootest PRIVATE gtest gtest_main)
#target_include_directories(gtest PUBLIC ${MY_INCLUDE_DIR})

string(COMPARE EQUAL "${CMAKE_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}" is_top_level)

set(DOWNLOAD_EXTRACT_TIMESTAMP true)

#include(CTest)
enable_testing()

set_target_properties(${TARGET} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
