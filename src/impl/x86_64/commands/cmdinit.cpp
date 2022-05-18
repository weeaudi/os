#include "cmd.hpp"

extern "C" void cmdinit(char input_char);
extern "C" void print_str(char* string);
extern "C" void print_char(char charecter);
extern "C" void print_newline();
extern void commands_init();


extern command commands[1];


char input_charecter = '/';

void cmdinit(char input_char)
{
    input_charecter = input_char;
    print_char(input_char);
	commands_init();
}

command current;

void run_command(char *incommand){
	int len = *(&commands + 1) - commands;
	for (int k = 0; k < len; k++){
		current = (command) commands[k];
		char *command_name = current.getname();
		int s1len = 0;
		int s2len = 0;
		for (int i = 0; command_name[i] != '\0';i++){
			s1len++;
		}
		for (int i = 0; incommand[i] != '\0';i++){
			s2len++;
		}
		if(s1len == s2len){
			for (int l = 0; l < s1len; l++){
				if(command_name[l] != incommand[l]){
    				print_char(input_charecter);
					return;
				}
			}
			print_newline();
			current.run();
		}
	}
    print_newline();
    print_char(input_charecter);
}


