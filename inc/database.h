#ifndef DATABASE_H
#define DATABASE_H

#include "main.h"
#include <stdio.h>
#include <stdbool.h>

FILE* database_connect(const char* data_filepath, const char* mode);
int database_disconnect(FILE* p_file);

void database_load_text_app(FILE* p_file, text_app_t* p_text_app);
void database_free_text_app(text_app_t* p_text_app);

#endif