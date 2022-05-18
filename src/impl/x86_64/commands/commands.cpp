//this is where the commands will be defined

extern "C" void print_str(char *string);

struct command{
	char* name;
    int run;
    char *about;
};

int help_run(){print_str((char*) "Hello this is the W.I.P help page!");return 0;}

struct command commands[1];
void commands_init(){
	command help{
		name: (char*) "help",
		run : help_run(),
		about: (char*) "testing"
	};
	commands[0] = help;
}
