cmake_minimum_required(VERSION 3.5.0)


project(ytvscodecpp VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(ytvscodecpp logic.cpp)
add_executable(ytvscodecpp main.cpp)
add_executable(ytvscodecpp input.cpp)

set(CPACK_PROJECT_NAME $(PROJECT_NAME))
set(CPACK_PROJECT_VERSION $(PROJECT_VERSION))
include(CPack)