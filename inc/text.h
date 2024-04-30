#ifndef TEXT_H
#define TEXT_H

typedef struct {
    union {
        char* messages[8];
        struct {
            char* welcome_msg;
            char* mode_list_msg;
            char* mode_input_select_msg;
            char* mode_input_invalid_msg;
            char* mode_selected_msg;
            char* continue_msg;
            char* goodbye_msg;
            char* exit_msg;
        };
    };
} text_app_t;


typedef struct {
    text_app_t text_app;
} text_t;

text_t* get_sc_text();

#endif