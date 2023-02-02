
file(GLOB_RECURSE all_imp_srcs CONFIGURE_DEPENDS *.cpp)
list(FILTER all_imp_srcs EXCLUDE REGEX "app_.*.cpp$")
add_library(${MY_LIB} SHARED ${all_imp_srcs} )

# for each "src/app_x.cpp", generate target "app_x"
file(GLOB_RECURSE all_app_srcs CONFIGURE_DEPENDS app_*.cpp)
foreach(v ${all_app_srcs})
    string(REGEX MATCH "src/.*" relative_path ${v})
    # message(${relative_path})
    string(REGEX REPLACE "src/" "" target_name ${relative_path})
    string(REGEX REPLACE ".cpp" "" target_name ${target_name})

    add_executable(${target_name} ${v})
    TARGET_LINK_LIBRARIES(${target_name}  ${MY_LIB})
endforeach()
