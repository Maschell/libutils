cmake_minimum_required(VERSION 3.2)
project(utilswut)
include("${WUT_ROOT}/share/wut.cmake" REQUIRED)

file(GLOB_RECURSE SOURCE_FILES *.c *.cpp)
file(GLOB_RECURSE HEADER_FILES *.h)

add_library(utilswut STATIC ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(utilswut PUBLIC "include")

wut_enable_stdcpp(utilswut)
wut_default_malloc(utilswut)

target_include_directories(utilswut PUBLIC "include")


install(TARGETS utilswut
        ARCHIVE DESTINATION "${CMAKE_INSTALL_PREFIX}/lib")
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
        DESTINATION "${CMAKE_INSTALL_PREFIX}/include/libutilswut"
        FILES_MATCHING PATTERN "*.h*")