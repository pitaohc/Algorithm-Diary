cmake_minimum_required(VERSION 3.5)
set(PROJECT_NAME LC-58)
project(${PROJECT_NAME} CXX)

# 引用上级目录中的utils中的头文件
set(UTILS_DIR ../utils)
include_directories(${UTILS_DIR})
# 包含utils_dir中的所有.h和.cpp文件
file(GLOB_RECURSE UTILS_FILES ${UTILS_DIR}/*.cpp ${UTILS_DIR}/*.h)

# 包含当前目录中的所有.h和.cpp文件
file(GLOB_RECURSE LOCAL_FILES ${PROJECT_NAME}.cpp ${PROJECT_NAME}.h)
# 输出LOCAL_FILES
message(STATUS "LOCAL_FILES: ${LOCAL_FILES}")
# 导入fmt库
find_package(fmt CONFIG REQUIRED)

# 编译项目
add_executable(${PROJECT_NAME} ${LOCAL_FILES} ${UTILS_FILES})

# 链接fmt库
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)
