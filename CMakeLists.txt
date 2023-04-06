cmake_minimum_required(VERSION 3.25)
project(AndroidC)

set(CMAKE_CXX_STANDARD 11)
#执行文件输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

add_executable(AndroidC  src/c/c1_data_type/x1_data_type.c)
add_executable(x1_data_type  src/c/c1_data_type/x1_data_type.c)
