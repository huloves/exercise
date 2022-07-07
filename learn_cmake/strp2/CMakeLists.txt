cmake_minimum_required (VERSION 2.6)
project (Tutorial)

# 版本号 1.0
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

add_library(MathFunctions mysqrt.cxx)

# 配置一个头文件将一些 CMake 设置传入到源代码中
# 以 TutorialConfig.h.in 为模版，替换相关变量
# 以生成 TutorialConfig.h
configure_file (
	"${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
	"${PROJECT_BINARY_DIR}/TutorialConfig.h"
)

# 将构建目录添加到 include 的搜索路径中以便找到
# TutorialConfig.h 文件
include_directories("${PROJECT_BINARY_DIR}")
include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
add_subdirectory (MathFunctions)

# 是否使用我们自己的函数？
option (USE_MYMATH
		"Use tutorial provided math implementation" ON)
# add the MathFunctions library?
if (USE_MYMATH)
  include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
  add_subdirectory (MathFunctions)
  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)

# add the executable
add_executable (Tutorial tutorial.cxx)
target_link_libraries (Tutorial  ${EXTRA_LIBS})
