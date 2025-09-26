cmake_minimum_required(VERSION 3.10)
project(argp C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
include_directories(. utils)
# Add source files
set(SOURCES 
    utils/getopt.h
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
add_executable(argp-test argp-test.c asprintf.h asprintf.c)
target_link_libraries(argp-test argp)
if(MSVC)
	target_compile_options(argp PRIVATE -D_CRT_SECURE_NO_WARNINGS)
	target_compile_options(argp-test PRIVATE -D_CRT_SECURE_NO_WARNINGS)
endif()


# Optional: Set output directory
set_target_properties(argp PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
set_target_properties(argp-test PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)
