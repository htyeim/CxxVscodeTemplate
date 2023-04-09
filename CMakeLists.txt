cmake_minimum_required(VERSION 3.20.0)
# conan install . --output-folder=build --build=missing -s build_type=Release
# conan install . --output-folder=build --build=missing -s build_type=Debug
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 11)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
    message("Setting default build type to Release")
endif()

project(my_project_name VERSION 0.0.1 LANGUAGES C CXX)

include_directories(${PROJECT_SOURCE_DIR}/include)
set(MY_LIB mylib)
add_subdirectory(./src)

add_subdirectory(./test)

add_subdirectory(./example)
