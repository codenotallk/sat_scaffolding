#include <templates.h>
#include <stdio.h>

#define MAIN_FILENAME       "src/main.c"

static const char *content = 
{
    "#include <stdio.h>\n"
    "#include <stdlib.h>\n"
    "#include <string.h>\n"
    "#include <stdio.h>\n"
    "#include <application.h>\n\n"
    "int main(int argc, char *argv[])\n"
    "{\n"
    "    sat_status_t status;\n\n"
    "    %s_t %s;\n"
    "    %s_args_t args =\n"
    "    {\n"
    "        .dummy = 1\n"
    "    };\n\n"
    "    do\n"
    "    {\n"
    "        status = %s_init (&%s);\n"
    "        if (sat_status_get_result (&status) == false)\n"
    "        {\n"
    "            break;\n"
    "        }\n\n"
    "        status = %s_open (&%s, &args);\n"
    "        if (sat_status_get_result (&status) == false)\n"
    "        {\n"
    "            break;\n"
    "        }\n\n"
    "        status = %s_run (&%s);\n"
    "        if (sat_status_get_result (&status) == false)\n"
    "        {\n"
    "            break;\n"
    "        }\n\n"
    "        else\n"
    "            status = %s_close (&%s);\n\n"
    "    } while (false);\n\n"
    "    printf (\"%%s\\n\", sat_status_get_motive (&status));\n\n"
    "    return sat_status_get_result (&status) == true ? EXIT_SUCCESS : EXIT_FAILURE;\n"
    "}"
};


bool sat_scaffolding_create_main_template (const char *binary_name)
{
    bool status = false;

    FILE *file = fopen (MAIN_FILENAME, "w");
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