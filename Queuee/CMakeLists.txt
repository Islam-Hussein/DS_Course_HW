cmake_minimum_required(VERSION 3.0)

# mygcc.cmake 
# toolchain file
set(CMAKE_CXX_COMPILER "C:/MinGW/bin/g++.exe" )
set(CMAKE_C_COMPILER "C:/MinGW/bin/gcc.exe" )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")


project(queuee_HW)

add_executable(${PROJECT_NAME} main.cpp)

target_link_directories(${PROJECT_NAME} PUBLIC queuee LinkedList)

add_subdirectory(queuee)
add_subdirectory(LinkedList)

target_link_libraries(${PROJECT_NAME} queuee Singly_LS)