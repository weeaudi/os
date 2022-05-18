//this is where the commands will be defined

struct command {
    void run();
    char *about;
};

struct command help{
    run: void(){
        print_str("Hello this is the W.I.P help page!");
    },
    about: "A W.I.P help page.",
}

struct command* commands = (struct command*) {};
commands["help"] = help;
