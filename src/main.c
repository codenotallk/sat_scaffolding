#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

#include <templates.h>

#define SAT_SCAFFOLDING_PROJECT_NAME_INDEX      1
#define SAT_SCAFFOLDING_BINARY_NAME_INDEX       2
#define SAT_SCAFFOLDING_PATH_INDEX              3


static bool sat_scaffolding_create_directories (const char *path, const char *project_name);


int main (int argc, char *argv [])
{
    bool status = false;

    if (argc != 4)
    {
        fprintf (stderr, "Cannot create project.\nUsage.: %s <project name> <binary name> <path>\n", argv [0]);
        return EXIT_FAILURE;
    }

    char *project_name = argv [SAT_SCAFFOLDING_PROJECT_NAME_INDEX];
    char *binary_name  = argv [SAT_SCAFFOLDING_BINARY_NAME_INDEX];
    char *path         = argv [SAT_SCAFFOLDING_PATH_INDEX];

    do 
    {
        if (sat_scaffolding_create_directories (path, project_name) == false)
            break;

        if (sat_scaffolding_create_cmake_template (project_name, binary_name) == false)
            break;

        if (sat_scaffolding_create_dockerfile_template () == false)
            break;

        if (sat_scaffolding_create_gitignore_template () == false)
            break;

        if (sat_scaffolding_create_docker_compose_template (project_name) == false)
            break;

        if (sat_scaffolding_create_application_header_template (binary_name) == false)
            break;

        if (sat_scaffolding_create_application_source_template (binary_name) == false)
            break;

        if (sat_scaffolding_create_main_template (binary_name) == false)
            break;

        status = true;

    } while (false);

    return status == true ? EXIT_SUCCESS : EXIT_FAILURE;
}

static bool sat_scaffolding_create_directories (const char *path, const char *project_name)
{
    bool status = false;

    char folder [1024] = {0};
    snprintf (folder, 1023, "%s/%s", path, project_name);

    do
    {
        if (mkdir (folder, 0755) != 0)
            break;

        if (chdir (folder) != 0)
            break;

        if (mkdir ("build", 0755) != 0)
            break;

        if (mkdir ("src", 0755) != 0)
            break;

        if (mkdir ("include", 0755) != 0)
            break;

        status = true;
    } while (false);

    fprintf (stderr, "%s\n", strerror (errno));

    return status;
}