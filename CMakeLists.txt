cmake_minimum_required(VERSION 3.11.3)

set(CMAKE_CXX_STANDARD 17)

project(Membot)

 # Google Test 
include(FetchContent)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.12.0)

FetchContent_GetProperties(googletest)

if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR})
endif()


find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

file(GLOB project_SRCS src/*.cpp)

add_executable(membot ${project_SRCS})

target_link_libraries(membot ${wxWidgets_LIBRARIES})

target_include_directories(membot PRIVATE ${wxWidgets_INCLUDE_DIRS})

set(SOURCES_DIR src)

add_executable(TestRunner Tests/Tests.cpp ${project_SRCS})

target_compile_definitions(TestRunner PRIVATE TEST=1)

target_include_directories(TestRunner PRIVATE ${SOURCES_DIR} ${wxWidgets_INCLUDE_DIRS})

target_link_libraries(TestRunner gtest_main gmock_main ${wxWidgets_LIBRARIES})