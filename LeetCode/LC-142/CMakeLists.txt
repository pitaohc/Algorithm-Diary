set(PROJECT_NAME LC-142)
project(${PROJECT_NAME} CXX)

# 添加头文件组到项目中，解决vs中不显示头文件的问题
file(GLOB_RECURSE CURRENT_HEADERS *.h *.hpp)
source_group("Include" FILES ${CURRENT_HEADERS})

file(GLOB_RECURSE CURRENT_RESOURCES *.md)
source_group("Resource" FILES ${CURRENT_RESOURCES})

# 设置需要编译的源文件
# file(GLOB_RECURSE CURRENT_SOURCES "*.c" "*.cpp")
# source_group("Source Files" FILES ${CURRENT_SOURCES })
# message(DEBUG CURRENT_SOURCES)
set(SRC_LIST main.cpp util.cpp List.cpp)

# 设置默认启动项
set_property ( DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME} )

add_executable(${PROJECT_NAME} ${SRC_LIST} ${CURRENT_HEADERS} ${CURRENT_RESOURCES})
