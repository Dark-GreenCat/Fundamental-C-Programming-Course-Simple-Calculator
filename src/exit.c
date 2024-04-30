#include "exit.h"

#include <stdlib.h>
#include "ui.h"

void launch_exit() {
    ui_printf("Hope to see you again!");
    ui_printf("\n[Simple Calculator exitted]");
    exit(0);
}