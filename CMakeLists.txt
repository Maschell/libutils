cmake_minimum_required(VERSION 3.2)
project(utils)
include("${WUT_ROOT}/share/wut.cmake" REQUIRED)

file(GLOB_RECURSE SOURCE_FILES *.c *.cpp)
file(GLOB_RECURSE HEADER_FILES *.h)

add_library(utils STATIC ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(utils PUBLIC "include")

wut_enable_stdcpp(utils)
wut_default_malloc(utils)

target_include_directories(utils PUBLIC "include")


install(TARGETS utils
        ARCHIVE DESTINATION "${CMAKE_INSTALL_PREFIX}/lib")
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
        DESTINATION "${CMAKE_INSTALL_PREFIX}/include/libutils"
        FILES_MATCHING PATTERN "*.h*")