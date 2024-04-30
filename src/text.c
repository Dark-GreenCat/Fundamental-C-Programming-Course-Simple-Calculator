#include "text.h"

text_t sc_text = {
    .text_app = {
        .welcome_msg = "",
        .mode_list_msg = "",
        .mode_input_select_msg = "",
        .mode_input_invalid_msg = "",
        .mode_selected_msg = "",
        .continue_msg = "",
        .goodbye_msg = "",
        .exit_msg = ""
    }
};

text_t* get_sc_text() {
    return &sc_text;
}
