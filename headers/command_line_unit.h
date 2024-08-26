#ifndef COMMAND_LINE_UNIT_H
#define COMMAND_LINE_UNIT_H

enum MODES {
    SOLVE,
    TEST,
    HELP
};

struct Cmd_arg {

    MODES mode;
    const char *short_name;
    const char *full_name;
    const char *discription;

};

void change_input_file(MODES mode);
void change_mode(MODES* mode, MODES cur_md);
void check_args(int argc_cp, char** argv_cp, MODES* mode);
int help(void);

#endif //COMMAND_LINE_UNIT_H
