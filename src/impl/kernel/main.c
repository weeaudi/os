#include "print.h"

void InitilizeIDT();
void cmdinit(char input_char);

void kernel_main() {
    InitilizeIDT();
    print_clear();
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    print_str("Hello welcome to aidos!");
	print_newline();
	print_str("This operating system will be a small system that");
	print_newline();
	print_str("will be able to run windows and linux programs.");
	print_newline();
	print_str("Hope you enjoy!");
	print_newline();
    cmdinit('>');
    while(1){};
}
