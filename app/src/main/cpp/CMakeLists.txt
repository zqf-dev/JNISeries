#于指定CMake的最低版本信息，不加入会收到警告
cmake_minimum_required(VERSION 3.10.2)
#工程名
project("jniseries")

# 打印日志
message("------------>>>")
message("当前CMake的路径是：${CMAKE_SOURCE_DIR}")
message("当前 CMAKE_ANDROID_ARCH_ABI 的路径是：${CMAKE_ANDROID_ARCH_ABI}")
message("当前 ANDROID_API 的路径是：${ANDROID_API}")

# 批量引入源文件
#file(GLOB allCpp *.cpp)

#添加源文件或库
add_library( # Sets the name of the library.
        native-lib
        # Sets the library as a shared library.
        SHARED
        # Provides a relative path to your source file(s).
        # 修改为批量引入
        native-lib.cpp
        #${allCpp}
        )
#添加外部的动态so库
#target_include_directories()
#add_library(bridge SHARED IMPORTED)
#导如头文件
#target_include_directories(bridge
#        PRIVATE
#        ${CMAKE_SOURCE_DIR}/src/main/cpp/include)
# 开始真正的导入
#set_target_properties(
#        bridge
#        PROPERTIES IMPORTED_LOCATION
#        ${CMAKE_SOURCE_DIR}/../../../libs/${ANDROID_API}/libbridge.so
#)

# 导入动态库
add_library(test_so SHARED IMPORTED)
# 早起的cmake ANDROID_ABI == 当前CPU平台
set_target_properties(test_so PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/../jniLibs/${CMAKE_ANDROID_ARCH_ABI}/libTest.so)

# 只能找系统库的
find_library( # Sets the name of the path variable.
        log-lib
        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

message("当前的log路径在哪里啊 >>>>>>>>>>>>>>>>> ${log-lib}")

#开始链接指定的库
target_link_libraries( # Specifies the target library.
        native-lib
        # Links the target library to the log library
        # included in the NDK.
        ${log-lib}
#        test_so
        )