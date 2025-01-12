#ifndef TEMPLATES_H_
#define TEMPLATES_H_

#include <stdbool.h>

bool sat_scaffolding_create_main_template (const char *binary_name);
bool sat_scaffolding_create_application_header_template (const char *binary_name);
bool sat_scaffolding_create_application_source_template (const char *binary_name);
bool sat_scaffolding_create_cmake_template (const char *project_name, const char *binary_name);
bool sat_scaffolding_create_dockerfile_template ();
bool sat_scaffolding_create_docker_compose_template (const char *project_name);
bool sat_scaffolding_create_gitignore_template (void);




#endif/* TEMPLATES_H_ */
