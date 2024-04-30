#ifndef DATABASE_H
#define DATABASE_H

#include "main.h"
#include <stdio.h>
#include <stdbool.h>

FILE* database_connect(const char* data_filepath, const char* mode);
int database_disconnect(FILE* p_file);

#endif