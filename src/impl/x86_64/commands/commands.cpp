//this is where the commands will be defined
#include "cmd.hpp"


extern "C" void print_str(char *string);

/*class command {
	//private:
    //	std::function<void()> run;
	
	public:
		void (* run)();
		char *name;
		char *about;
		void set_command(char *inname, void function(), char *inabout){
			//std::function<void()> run;
			name = name;
			run = function;
			about = inabout;
		};
};*/

void help_run(){print_str((char*) "Hello this is the W.I.P help page!");return;}

command commands[1];

void commands_init(){
	commands[0].set_command((char*) "help", help_run, (char*) "testing");
}
