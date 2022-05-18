#include "print.h"

void InitilizeIDT();
void cmdinit(char input_char);

void kernel_main() {
    InitilizeIDT();
    print_clear();
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    print_str("Hello welcome to aidos!\nThis operating system will be a small system that\n will be able to run windows and linux programs\n");
    cmdinit('>');
    while(1){};
}
