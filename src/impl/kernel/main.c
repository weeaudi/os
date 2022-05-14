#include "print.h"

void InitilizeIDT();

void kernel_main() {
    InitilizeIDT();
    print_clear();
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    //print_str("Hello world!");
    while(1){};
}
