/// @file дяллял


#ifndef COMMAND_LINE_UNIT_H
#define COMMAND_LINE_UNIT_H

enum MODES {
    SOLVE,                                  ///< solve mode
    TEST,
    HELP
};

struct Cmd_arg {

    MODES mode = SOLVE;

    const char *short_name;
    const char *full_name;
    const char *discription;

};

MODES check_args(int argc_cp, char** argv_cp);
void skip_file_name_arg(int* c, char*** v);
int help(void);

#endif //COMMAND_LINE_UNIT_H
