cmake_minimum_required(VERSION 3.16)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

project(MiniRT)

file(GLOB SRC *.cpp)
add_library(verdant ${SRC})
target_include_directories(verdant PUBLIC .)
# Include vmmlib from MetalRay
target_include_directories(verdant PUBLIC ../include)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(verdant PUBLIC Threads::Threads)
