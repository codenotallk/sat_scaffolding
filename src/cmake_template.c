#include <templates.h>
#include <stdio.h>

#define CMAKELISTS_FILENAME     "CMakeLists.txt"

static const char *content =
{
    "cmake_minimum_required(VERSION 3.7.0)\n"
    "project (%s)\n\n"
    "set (CMAKE_C_FLAGS \"-D_GNU_SOURCE -Wall -std=c99\")\n"
    "set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)\n"
    "set (LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)\n"
    "set (CMAKE_BUILD_TYPE Debug)\n\n"
    "add_executable (%s \"\")\n"
    "target_link_libraries (%s PUBLIC sat)\n\n"
    "target_sources (%s\n"
    "  PUBLIC\n"
    "  ${CMAKE_CURRENT_LIST_DIR}/src/application.c\n"
    "  ${CMAKE_CURRENT_LIST_DIR}/src/main.c\n"
    ")\n\n"
    "target_include_directories (%s\n"
    "  PUBLIC\n"
    "  ${CMAKE_CURRENT_LIST_DIR}/include\n"
    ")\n\n"
    "install (TARGETS %s DESTINATION bin)"
};

bool sat_scaffolding_create_cmake_template (const char *project_name, const char *binary_name)
{
    bool status = false;

    FILE *file = fopen (CMAKELISTS_FILENAME, "w");

    if (file != NULL)
    {
        fprintf (file, content, project_name,
                                binary_name,
                                binary_name,
                                binary_name,
                                binary_name,
                                binary_name);
        fclose (file);
        status = true;
    }

    return status;
}