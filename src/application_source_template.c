#include <templates.h>
#include <stdio.h>

#define APPLICATION_SOURCE_FILENAME     "src/application.c"

static const char *content = 
{
    "#include <application.h>\n"
    "#include <string.h>\n\n"
    "sat_status_t %s_init (%s_t *object)\n"
    "{\n"
    "    sat_status_t status = sat_status_set (&status, false, \"%s init error\");\n\n"
    "    if (object != NULL)\n"
    "    {\n\n"
    "        memset (object, 0, sizeof (%s_t))\n\n"
    "        sat_status_set (&status, true, \"\");\n"
    "    }\n\n"
    "    return status;\n"
    "}\n\n"
    "sat_status_t %s_open (%s_t *object, %s_args_t *args)\n"
    "{\n"
    "    sat_status_t status = sat_status_set (&status, false, \"%s open error\");\n\n"
    "    if (object != NULL && args != NULL)\n"
    "    {\n\n"
    "        sat_status_set (&status, true, \"\");\n"
    "    }\n\n"
    "    return status;\n"
    "}\n\n"
    "sat_status_t %s_run (%s_t *object)\n"
    "{\n"
    "    sat_status_t status = sat_status_set (&status, false, \"%s run error\");\n\n"
    "    if (object != NULL)\n"
    "    {\n\n"
    "        sat_status_set (&status, true, \"\");\n"
    "    }\n\n"
    "    return status;\n"
    "}\n\n"
    "sat_status_t %s_close (%s_t *object)\n"
    "{\n"
    "    sat_status_t status = sat_status_set (&status, false, \"%s close error\");\n\n"
    "    if (object != NULL)\n"
    "    {\n\n"
    "        sat_status_set (&status, true, \"\");\n"
    "    }\n\n"
    "    return status;\n"
    "}"
};


bool sat_scaffolding_create_application_source_template (const char *binary_name)
{
    bool status = false;

    FILE *file = fopen (APPLICATION_SOURCE_FILENAME, "w");
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
                                binary_name,
                                binary_name,
                                binary_name,
                                binary_name);

        fclose (file);
        status = true;
    }

    return status;
}