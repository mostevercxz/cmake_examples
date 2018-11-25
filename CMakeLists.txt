# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)
enable_language(CXX)

SET(CMAKE_CXX_STANDARD 11)

SET(HELLO_WORLD_MAJOR 1)
SET(HELLO_WORLD_MINOR 1)

include (CheckFunctionExists)
check_function_exists (log HAVE_LOG)
check_function_exists (exp HAVE_EXP)

project ("CMakeProject1")

include_directories("${PROJECT_BINARY_DIR}")

# 更改该选项的值之后,需要在vs CMake --> Cache --> Delete Cache folders
# 重新生成缓存没用,需要删除缓存目录
option (USE_MYMATH
"Use my own math implementation" ON)


configure_file (
	"${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
	"${PROJECT_BINARY_DIR}/TutorialConfig.h"
)

if (USE_MYMATH)
  include_directories("${PROJECT_SOURCE_DIR}/MathFunctions")
  add_subdirectory("MathFunctions")
  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)

# 包含子项目。
add_subdirectory ("CMakeProject1")

install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h"
        DESTINATION include)