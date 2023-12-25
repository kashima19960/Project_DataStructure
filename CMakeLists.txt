cmake_minimum_required(VERSION 3.10)
set(CMAKE_GENERATOR "MinGW Makefiles")
project(DataStructure_Project)

file(GLOB SRC_FILE 
${PROJECT_SOURCE_DIR}/src/*.cpp
${PROJECT_SOURCE_DIR}/*.cpp
${PROJECT_SOURCE_DIR}/include/*.h
${PROJECT_SOURCE_DIR}/include/*.hpp
)
include_directories(./include)

add_executable(${PROJECT_NAME} ${SRC_FILE})