cmake_minimum_required(VERSION 3.20.0)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE
        "$ENV{HOME}/vcpkg/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")
endif()


set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 11)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
    message("Setting default build type to Release")
endif()

project(my_project_name VERSION 0.0.1 LANGUAGES C CXX)

find_package(BehaviorTreeV3 CONFIG REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/include)
set(MY_LIB mylib)
add_subdirectory(./src)

add_subdirectory(./test)

add_subdirectory(./example)
