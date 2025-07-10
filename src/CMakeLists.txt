cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(JSON_BuildTests OFF CACHE INTERNAL "")
#include_directories(${nlohmann_json})



#include_directories(${MY_INCLUDE_DIR})



set(enable-threads posix)


#set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

#add_executable(search_engine src/main.cpp 
#${MY_INCLUDE_DIR}/help.h  ${MY_INCLUDE_DIR}/converterjson.h  ${MY_INCLUDE_DIR}/readsettings.h ${MY_INCLUDE_DIR}/search.h ${MY_INCLUDE_DIR}/test.h 
#src/help.cpp src/readsettings.cpp src/search.cpp src/test.cpp)

#target_link_libraries(search_engine PRIVATE nlohmann_json::nlohmann_json)
#target_include_directories(search_engine PUBLIC ${MY_INCLUDE_DIR})

