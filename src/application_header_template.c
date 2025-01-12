#include <templates.h>
#include <stdio.h>

#define APPLICATION_HEADER_FILENAME     "include/application.h"

static const char *content = 
{
    "#ifndef APPLICATION_H_\n"
    "#define APPLICATION_H_\n\n"
    "#include <sat.h>\n\n"
    "typedef struct\n"
    "{\n"
    "    int dummy; // your context\n"
    "} %s_t;\n\n"
    "typedef struct \n"
    "{\n"
    "    int dummy;\n"
    "} %s_args_t;\n\n"
    "sat_status_t %s_init (%s_t *object);\n"
    "sat_status_t %s_open (%s_t *object, %s_args_t *args);\n"
    "sat_status_t %s_run (%s_t *object);\n"
    "sat_status_t %s_close (%s_t *object);\n\n"
    "#endif/* APPLICATION_H_ */"
};


bool sat_scaffolding_create_application_header_template (const char *binary_name)
{
    bool status = false;

    FILE *file = fopen (APPLICATION_HEADER_FILENAME, "w");
    if (file != NULL)
    {
        fprintf (file, content, binary_name,
                                binary_name,
                                binary_name,
                                binary_name,
                                binary_name,
                                binary_name,
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