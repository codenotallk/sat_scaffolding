cmake_minimum_required (VERSION 3.7.0)

project (SAT_SCAFFOLDING)

set (CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c99")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set (LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_BUILD_TYPE Debug)

add_executable (sat_scaffolding "")
target_sources (sat_scaffolding
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/src/main.c
    ${CMAKE_CURRENT_LIST_DIR}/src/application_header_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/application_source_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/cmake_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/docker_compose_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/dockerfile_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/gitignore_template.c
    ${CMAKE_CURRENT_LIST_DIR}/src/main_template.c
)
target_include_directories (sat_scaffolding
    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/include
)

install (TARGETS sat_scaffolding DESTINATION ${CMAKE_INSTALL_BINDIR})