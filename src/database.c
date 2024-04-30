#include "database.h"

#include <string.h>
#include <stdlib.h>
#include "text.h"

FILE* database_connect(const char* data_filepath, const char* mode) {
    FILE* p_file = NULL;
    p_file = fopen(data_filepath, mode);

    if (p_file == NULL) {
        ui_printf("\n[ERROR] Unable to open file: %s\n", data_filepath);
        app_exit();
    }

    return p_file;
}

int database_disconnect(FILE* p_file) {
    return fclose(p_file);
}

void database_load_text_app(FILE* p_file, text_app_t* p_text_app) {
    int number_of_msg = sizeof(*p_text_app) / sizeof(p_text_app->messages[0]);

    char buffer[50] = { 0 };
    while(!feof(p_file)) {
        while (fgetc(p_file) != '#');
        fscanf(p_file, "%49[^,\n]%*c", buffer);
        if (strcmp(buffer, "app") == 0) break;
        while (fgetc(p_file) != '\n');
    }

    for (int i = 0; i < number_of_msg; i++) {
        if(!fscanf(p_file, "%49[^,\n]%*c", buffer)) break;

        p_text_app->messages[i] = (char*) malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(p_text_app->messages[i], buffer);
    }
}

void database_free_text_app(text_app_t* p_text_app) {
    int number_of_msg = sizeof(*p_text_app) / sizeof(p_text_app->messages[0]);
    for (int i = 0; i < number_of_msg; i++) {
        free(p_text_app->messages[i]);
    }
}
