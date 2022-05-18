class command {
	//private:
    //	std::function<void()> run;
	
	public:
		void (* run)();
		char *cmdname;
		char *cmdabout;
		void set_command(char *inname, void function(), char *inabout){
			//std::function<void()> run;
			cmdname = inname;
			run = function;
			cmdabout = inabout;
		};
		char *getname(){
			return cmdname;
		}
};
//command commands[10];