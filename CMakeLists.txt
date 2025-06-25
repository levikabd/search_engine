cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(search_engine VERSION 0.1.0 LANGUAGES C CXX)

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(src)
add_subdirectory(res)
add_subdirectory(include)

add_subdirectory(nlohmann_json)
#add_subdirectory(googletest)

#include_directories(${nlohmann_json})
#target_include_directories(src ./include)

#include(FetchContent)
#FetchContent_Declare(
#googletest
#URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
#)

add_executable(search_engine src/main.cpp src/help.cpp src/readsettings.cpp src/search.cpp src/test.cpp ${MY_INCLUDE_DIR}/help.h  ${MY_INCLUDE_DIR}/converterjson.h  ${MY_INCLUDE_DIR}/readsettings.h ${MY_INCLUDE_DIR}/search.h ${MY_INCLUDE_DIR}/test.h)

target_link_libraries(search_engine PRIVATE nlohmann_json::nlohmann_json gtest gtest_main)
#target_link_libraries(search_engine GTest::gtest_main)
#target_link_libraries(search_engine PRIVATE nlohmann_json::nlohmann_json Gtest gtest_main)
#target_link_libraries(search_engine Gtest::gtest_main)

include(GoogleTest)
gtest_discover_tests(search_engine)

include_directories(${MY_INCLUDE_DIR})

set(gtest_SOURCE_DIR ${CMAKE_SOURCE_DIR}/googletest)
set(GOOGLETESTDIR ${gtest_SOURCE_DIR}/googletest/include)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(gtest_disable_pthreads on)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

#include(CTest)
enable_testing()
