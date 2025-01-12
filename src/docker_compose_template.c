#include <templates.h>
#include <stdio.h>

#define DOCKER_COMPOSE_FILENAME "docker-compose.yaml"

static const char *content =
{
    "version: \"3\"\n"
    "services:\n"
    "  development:\n"
    "    #build: .\n"
    "    image: solidcris/development\n"
    "    container_name: %s\n"
    "    volumes:\n"
    "    - .:/development\n"
    "    ports:\n"
    "    - \"1234:1234\""
};


bool sat_scaffolding_create_docker_compose_template (const char *project_name)
{
    bool status = false;

    FILE *file = fopen (DOCKER_COMPOSE_FILENAME, "w");
    if (file != NULL)
    {
        fprintf (file, content, project_name);
        fclose (file);
        status = true;
    }

    return status;
}