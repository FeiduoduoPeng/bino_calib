cmake_minimum_required( VERSION 2.8 )
project( mycalib )

# 添加c++ 11标准支持
set( CMAKE_CXX_FLAGS "-std=c++11" )

# 寻找OpenCV库
find_package( OpenCV REQUIRED )
# 添加头文件
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( cpp-example-calibration calibration.cpp )
add_executable( stereo_calib stereo_calib.cpp )
# 链接OpenCV库
target_link_libraries( cpp-example-calibration ${OpenCV_LIBS} )
target_link_libraries( stereo_calib ${OpenCV_LIBS} )
