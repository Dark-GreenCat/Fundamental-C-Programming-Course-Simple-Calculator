#include "database.h"

const char text_filepath[] = "../data/text.csv";

FILE* database_connect(const char* data_filepath, const char* mode) {
    FILE* p_file = NULL;
    p_file = fopen(data_filepath, mode);

    if (p_file == NULL) {
        ui_printf("\n[ERROR] Unable to open file: %s", data_filepath);
    }

    return p_file;
}

int database_disconnect(FILE* p_file) {
    return fclose(p_file);
}
