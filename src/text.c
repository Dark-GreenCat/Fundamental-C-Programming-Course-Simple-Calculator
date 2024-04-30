#include "text.h"

text_t sc_text = {
    .text_app = {
        .welcome_msg = "Welcome to Simple Calculator",
        .mode_list_msg = "Simple Calculator Mode",
        .mode_input_select_msg = "Select mode",
        .mode_input_invalid_msg = "[ERROR] Invalid mode!",
        .mode_selected_msg = "Mode selected",
        .continue_msg = "Press any to continue...",
        .goodbye_msg = "Hope to see you again!",
        .exit_msg = "[Simple Calculator exitted]"
    }
};

text_t* get_sc_text() {
    return &sc_text;
}
