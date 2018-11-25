# CMakeList.txt: CMakeProject1 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)


#include_directories("${PROJECT_BINARY_DIR}")
file(GLOB SOURCES "*.cpp")

# 将源代码添加到此项目的可执行文件。
add_executable (hello-world "CMakeProject1.h" ${SOURCES})
target_link_libraries(hello-world MathFunctions.dll)

# TODO: 如有需要，请添加测试并安装目标。

install(TARGETS hello-world DESTINATION bin)