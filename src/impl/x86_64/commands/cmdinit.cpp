extern "C" void cmdinit(char input_char);
extern "C" void print_str(char* string);
extern "C" void print_char(char charecter);
extern "C" void print_newline();
extern void commands_init();

struct command{
	char* name;
    int run;
    char *about;
};

extern command commands[1];

char input_charecter = '/';

void cmdinit(char input_char)
{
    input_charecter = input_char;
    print_char(input_char);
	commands_init();
}

command current;

void run_command(char *incmd){
	print_newline();
	for (int k = 0; k < 1; k++){
		current = (command) commands[k];
		if((current.name) == incmd){
			current.run;
		}
	}
    print_newline();
    print_char(input_charecter);
}


