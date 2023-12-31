# test/CMakeLists.txt

cmake_minimum_required(VERSION 3.27.0)
project(test_hello_world)

# 将 gtest 添加到项目中
# 路径后跟了字符串 googletest，这是因为 googletest 的源码并不是 tests 目录的子目录，因此必须为googletest指定一个编译路径
# 这是cmake的规则
add_subdirectory(${CPP_PROJECT_PROJECT_ROOT}/thirdpart/googletest-1.14.0 googletest)

# test_hello **********************
# 添加一个可执行程序
add_executable(test_hello ${CMAKE_CURRENT_SOURCE_DIR}/test_hello.cc)
# 依赖googletest的头文件
target_include_directories(test_hello PUBLIC ${CPP_PROJECT_PROJECT_ROOT}/thirdpart/googletest-1.14.0/googletest/include)
# 要测试的是hello模块，因此也依赖hello模块，因此给出hello模块的父目录
target_include_directories(test_hello PUBLIC ${CPP_PROJECT_PROJECT_ROOT})
# 添加依赖库
# googletest有两个库：gtest 和 gtest_main
target_link_libraries(test_hello PUBLIC hellolib gtest gtest_main)
# 把测试添加到框架中去，添加此内容ctest才会有东西输出
add_test(NAME test_hello
         COMMAND test_hello)

# test_world **********************
add_executable(test_world ${CMAKE_CURRENT_SOURCE_DIR}/test_world.cc)

target_include_directories(test_world PUBLIC ${CPP_PROJECT_PROJECT_ROOT}/thirdpart/googletest-1.14.0/googletest/include)
target_include_directories(test_world PUBLIC ${CPP_PROJECT_PROJECT_ROOT})

target_link_libraries(test_world PUBLIC worldlib gtest gtest_main)

add_test(NAME test_world
         COMMAND test_world)