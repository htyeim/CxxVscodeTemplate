
set(MY_TEST_LIB "")
file(GLOB_RECURSE all_imp_srcs CONFIGURE_DEPENDS *.cpp)
list(FILTER all_imp_srcs EXCLUDE REGEX "test_*.cpp$")
if(all_imp_srcs)
set(MY_TEST_LIB my_test_lib)
add_library(${MY_TEST_LIB} SHARED ${all_imp_srcs} )
endif()

# for each "test/test_x.cpp", generate target "test_x"
file(GLOB_RECURSE all_tests test_*.cpp)
foreach(v ${all_tests})
    string(REGEX MATCH "test/.*" relative_path ${v})
    # message(${relative_path})
    string(REGEX REPLACE "test/" "" target_name ${relative_path})
    string(REGEX REPLACE ".cpp" "" target_name ${target_name})

    add_executable(${target_name} ${v})
endforeach()

# manual target (not start with "atest_")
find_package(GTest CONFIG REQUIRED)

add_executable(g_test g_test.cpp)
target_link_libraries(g_test GTest::gtest ${MY_LIB} ${MY_TEST_LIB})
