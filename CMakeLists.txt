cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(search_engine VERSION 0.1.0 LANGUAGES C CXX)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(src)
add_subdirectory(res)

add_subdirectory(nlohmann_json)

#gtest
add_subdirectory(test)

#target_include_directories(src ./include)

#include_directories(${MY_INCLUDE_DIR})

set(enable-threads posix)


set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable(search_engine main.cpp 
${MY_INCLUDE_DIR}/help.h  ${MY_INCLUDE_DIR}/converterjson.h  ${MY_INCLUDE_DIR}/readsettings.h ${MY_INCLUDE_DIR}/search.h ${MY_INCLUDE_DIR}/search_engine.h 
src/help.cpp src/readsettings.cpp src/search.cpp src/search_engine.cpp
)

target_link_libraries(search_engine PRIVATE nlohmann_json::nlohmann_json)
target_include_directories(search_engine PUBLIC ${MY_INCLUDE_DIR})

#include(CTest)

enable_testing()

set_target_properties(${TARGET} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
