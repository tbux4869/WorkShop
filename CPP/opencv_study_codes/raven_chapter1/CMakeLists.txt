cmake_minimum_required( VERSION 2.8 )
project( raven_chapter1 )

# 添加c++ 11标准支持
set( CMAKE_CXX_FLAGS "-std=c++11" )

#set the default path for built executables to the "bin" directory
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# 寻找OpenCV库
find_package( OpenCV REQUIRED )
# 添加头文件
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( raven1 raven1.cpp )
add_executable( raven2 raven2.cpp )
add_executable( raven3 raven3.cpp )
add_executable( raven4 raven4.cpp )
# 链接OpenCV库
target_link_libraries( raven1 ${OpenCV_LIBS} )
target_link_libraries( raven2 ${OpenCV_LIBS} )
target_link_libraries( raven3 ${OpenCV_LIBS} )
target_link_libraries( raven4 ${OpenCV_LIBS} )
