cmake_minimum_required(VERSION 2.8.3)

#生成测试文件
project(Proto_test)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
include_directories(./protobuf)
add_executable(test test.cpp ./protobuf/Persion.pb.cc ./protobuf/Info.pb.cc)
target_link_libraries(test protobuf)

