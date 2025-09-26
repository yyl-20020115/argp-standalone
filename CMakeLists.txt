cmake_minimum_required(VERSION 3.10)
project(argp C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

option(USE_TESTS "Enable test program" ON)
set(USE_TESTS ON)
include_directories(.)
# Add source files
set(SOURCES 
    argp-util.h
    argp-util.c
    argp-ba.c
    argp-eexst.c
    argp-fmtstream.c
    argp-fmtstream.h
    argp-help.c
    argp-namefrob.h
    argp-parse.c
    argp-pv.c
    argp-pvh.c
    argp.h
)

add_library(argp STATIC ${SOURCES})

if(MSVC)
	target_compile_options(argp PRIVATE -D_CRT_SECURE_NO_WARNINGS)
    target_include_directories(argp PRIVATE utils)
endif()


# Optional: Set output directory
set_target_properties(argp PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
if(USE_TESTS)
add_executable(ex1 testsuite/ex1.c)
add_executable(ex3 testsuite/ex3.c)
add_executable(ex4 testsuite/ex4.c)
add_executable(argp-test argp-test.c asprintf.h asprintf.c)

target_link_libraries(ex1 argp)
target_link_libraries(ex3 argp)
target_link_libraries(ex4 argp)
target_link_libraries(argp-test argp)

set_target_properties(ex1 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
set_target_properties(ex3 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
set_target_properties(ex4 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
set_target_properties(argp-test PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

if(MSVC)
	target_compile_options(ex1 PRIVATE -D_CRT_SECURE_NO_WARNINGS)
	target_compile_options(ex3 PRIVATE -D_CRT_SECURE_NO_WARNINGS)
	target_compile_options(ex4 PRIVATE -D_CRT_SECURE_NO_WARNINGS)
	target_compile_options(argp-test PRIVATE -D_CRT_SECURE_NO_WARNINGS)
endif()
endif()