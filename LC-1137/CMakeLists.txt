project(LC-1137 CXX)

# 添加头文件组到项目中，解决vs中不显示头文件的问题
file(GLOB_RECURSE CURRENT_HEADERS *.h *.hpp)
source_group("Include" FILES ${CURRENT_HEADERS})

file(GLOB_RECURSE CURRENT_RESOURCES *.md)
source_group("Resource" FILES ${CURRENT_RESOURCES})

# 设置需要编译的头文件
set(SRC_LIST main.cpp Solution.cpp)

add_executable(lc-1137 ${SRC_LIST} ${CURRENT_HEADERS} ${CURRENT_RESOURCES})
