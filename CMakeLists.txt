# CMake最低版本号要求
cmake_minimum_required(VERSION 3.20)


# 项目名称
set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 1)
set(PROJECT_CXX_VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH})
project(xcc-rundll VERSION ${PROJECT_CXX_VERSION})


# 输出提示信息
message(STATUS "Operation System : ${CMAKE_SYSTEM}")
message(STATUS "CMAKE_INSTALL_PREFIX : ${CMAKE_INSTALL_PREFIX}")
message(STATUS "CMAKE_C_COMPILER : ${CMAKE_C_COMPILER}")
message(STATUS "CMAKE_CXX_COMPILER : ${CMAKE_CXX_COMPILER}")


# 配置文件
configure_file("${CMAKE_SOURCE_DIR}/config/VersionInfo.rc.in" "${CMAKE_BINARY_DIR}/VersionInfo.rc")


# 设置模块搜索路径
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_INSTALL_PREFIX}/lib/cmake)
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${CMAKE_MODULE_PATH})
message(STATUS "CMAKE_MODULE_PATH : ${CMAKE_MODULE_PATH}")
message(STATUS "CMAKE_PREFIX_PATH : ${CMAKE_PREFIX_PATH}")


# 设置编译环境
if (MSVC)
	add_compile_options(/W4)
else()
	add_compile_options(-Wall)
endif()
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd /Od")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD /Od")
message(STATUS "CMAKE_CXX_FLAGS_DEBUG : ${CMAKE_CXX_FLAGS_DEBUG}")
message(STATUS "CMAKE_CXX_FLAGS_RELEASE : ${CMAKE_CXX_FLAGS_RELEASE}")


# 添加资源文件
set(WRC_SOURCE_FILES resources/XConsoleApplication.rc)


# 设置忽略路径
set(CMAKE_IGNORE_PATH ${CMAKE_INSTALL_PREFIX}/include/${PROJECT_NAME})
message(STATUS "CMAKE_IGNORE_PATH : ${CMAKE_IGNORE_PATH}")


# 项目依赖
include_directories(${PROJECT_SOURCE_DIR}/include)
find_package(xcc-posix REQUIRED)
find_package(xcc-core REQUIRED)


# C++支持
set(CMAKE_CXX_STANDARD 17)


# 设置宏
add_definitions(-D_CRT_NON_CONFORMING_SWPRINTFS)
add_definitions(-D_CRT_SECURE_NO_WARNINGS)
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	add_definitions(-DXANADU_BUILD_DEBUG)
else ()
	add_definitions(-DXANADU_BUILD_RELEASE)
endif ()


# 头文件搜索目录
include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PACKAGE_DIRECTORY_INCLUDE})
include_directories(${XCC_POSIX_INCLUDE})
include_directories(${XCC_CORE_INCLUDE})


# 链接库搜索目录
link_directories(${PACKAGE_DIRECTORY_LIBRARY})
link_directories(${XCC_POSIX_LIBRARY})
link_directories(${XCC_CORE_LIBRARY})


# 包含源文件
aux_source_directory(./source SRC)
if(MSVC)
	list(APPEND SRC ${CMAKE_BINARY_DIR}/VersionInfo.rc)
endif()


# 指定可执行程序输出目录
if(WIN32)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG $ENV{CXX_BINARY}/xcc/windows/debug)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE $ENV{CXX_BINARY}/xcc/windows/release)
elseif(APPLE)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG $ENV{CXX_BINARY}/xcc/darwin/debug)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE $ENV{CXX_BINARY}/xcc/darwin/release)
elseif(UNIX)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG $ENV{CXX_BINARY}/xcc/linux/debug)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE $ENV{CXX_BINARY}/xcc/linux/release)
endif()


# 链接库
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
	link_libraries(xcc-posix-d)
	link_libraries(xcc-core-d)
else ()
	link_libraries(xcc-posix)
	link_libraries(xcc-core)
endif ()
if (WIN32)
	link_libraries(Ws2_32.lib)
	link_libraries(Shlwapi.lib)
elseif (MINGW)
	link_libraries(Ws2_32)
	link_libraries(Shlwapi)
else ()
	link_libraries(pthread)
	link_libraries(dl)
	link_libraries(rt)
endif ()
if (APPLE)
	link_libraries(objc)
endif ()


# 设置Mac RPATH
if (APPLE)
	set(CMAKE_INSTALL_RPATH "@executable_path/../Frameworks")
	set(CMAKE_BUILD_WITH_INSTALL_RPATH ON)
endif ()


# 设置 Windows 链接标志
message(STATUS "CMAKE_EXE_LINKER_FLAGS : ${CMAKE_EXE_LINKER_FLAGS}")
if (WIN32)
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:CONSOLE")
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:\"mainCRTStartup\"")
	# set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /MANIFESTUAC:\"level='requireAdministrator' uiAccess='false'\"")
	set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /TSAWARE")
endif ()
message(STATUS "CMAKE_EXE_LINKER_FLAGS : ${CMAKE_EXE_LINKER_FLAGS}")


# 构建
add_executable(${PROJECT_NAME} ${SRC} ${QRC_SOURCE_FILES} ${WRC_SOURCE_FILES})


# 设置项目属性
set_target_properties(${PROJECT_NAME} PROPERTIES SOVERSION ${PROJECT_VERSION_MAJOR})
set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX -d)


# 设置安装文件(可执行文件)
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
