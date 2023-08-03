cmake_minimum_required(VERSION 3.5)
set(PROJECT_NAME LC-34)
project(${PROJECT_NAME} CXX)

# 引用上级目录中的utils中的头文件
set(UTILS_DIR ../utils)
include_directories(${UTILS_DIR})
# 包含utils_dir中的所有.h和.cpp文件
file(GLOB_RECURSE UTILS_FILES ${UTILS_DIR}/*.cpp ${UTILS_DIR}/*.h)


# 编译项目
add_executable(${PROJECT_NAME} main.cpp ${UTILS_FILES})