cmake_minimum_required(VERSION 3.5)
set(PROJECT_NAME NEW-LeetCode)
project(${PROJECT_NAME} CXX)

# 输出项目根目录
message(STATUS "PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")

# 获得项目根目录下包含CMakeLists.txt目录,并添加subdirectory调用
file(GLOB ProjectDirs ${PROJECT_SOURCE_DIR}/*)
foreach (ProjectDir ${ProjectDirs})
    message(STATUS "ProjectDir: ${ProjectDir}")
    get_filename_component(ProjectName ${ProjectDir} NAME)
    message(STATUS "ProjectName: ${ProjectName}")
    # 判断该目录是否存在CMakeLists.txt
    if (NOT EXISTS ${ProjectDir}/CMakeLists.txt)
        message(STATUS "ProjectDir: ${ProjectDir} not exist CMakeLists.txt")
        continue()
    endif ()
    add_subdirectory(${ProjectName})
endforeach (ProjectDir)