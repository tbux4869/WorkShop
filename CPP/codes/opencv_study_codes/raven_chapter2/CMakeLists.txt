cmake_minimum_required( VERSION 2.8 )
project( raven2 )

# 添加c++ 11标准支持
set( CMAKE_CXX_FLAGS "-std=c++11" )

# 寻找OpenCV库
find_package( OpenCV REQUIRED )

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# 添加头文件
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( raven2_1 raven2_1.cpp )
add_executable( raven2_2 raven2_2.cpp )
add_executable( raven2_3 raven2_3.cpp )
# 链接OpenCV库
target_link_libraries( raven2_1 ${OpenCV_LIBS} )
target_link_libraries( raven2_2 ${OpenCV_LIBS} )
target_link_libraries( raven2_3 ${OpenCV_LIBS} )
