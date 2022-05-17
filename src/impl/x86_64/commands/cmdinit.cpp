#include "commands.cpp"

extern "C" void cmdinit(char input_char);
extern "C" void print_str(char* string);
extern "C" void print_char(char charecter);
extern "C" void print_newline();

char input_charecter = '/';

void cmdinit(char input_char)
{
    input_charecter = input_char;
    print_char(input_char);
}

void run_command(char *incmd){
	print_newline();
	print_str(incmd);
    print_newline();
    print_char(input_charecter);
}


