#include <templates.h>
#include <stdio.h>

#define GITIGNORE_FILENAME      ".gitignore"

static const char *content = 
{
    "build\n"
    ".vscode"
};

bool sat_scaffolding_create_gitignore_template (void)
{
    bool status = false;

    FILE *file = fopen (GITIGNORE_FILENAME, "w");
    if (file != NULL)
    {
        fputs (content, file);
        fclose (file);
        status = true;
    }

    return status;
}