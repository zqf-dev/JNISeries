#于指定CMake的最低版本信息，不加入会收到警告
cmake_minimum_required(VERSION 3.10.2)
#工程名
project("jniseries")
#添加源文件或库
add_library( # Sets the name of the library.
        native-lib
        # Sets the library as a shared library.
        SHARED
        # Provides a relative path to your source file(s).
        native-lib.cpp)
# 添加外部新的so库
#target_include_directories()
#add_library(bridge SHARED IMPORTED)
#
#target_include_directories(bridge
#        PRIVATE
#        ${CMAKE_SOURCE_DIR}/src/main/cpp/include)
#
#set_target_properties(
#        bridge
#        PROPERTIES IMPORTED_LOCATION
#        ${CMAKE_SOURCE_DIR}/../../../libs/${ANDROID_API}/libbridge.so
#)

find_library( # Sets the name of the path variable.
        log-lib
        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

target_link_libraries( # Specifies the target library.
        native-lib
        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})