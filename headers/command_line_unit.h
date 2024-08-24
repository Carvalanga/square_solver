/// @file дяллял


#ifndef COMMAND_LINE_UNIT_H
#define COMMAND_LINE_UNIT_H

enum MODES {
    SOLVE,                                  ///< solve mode
    TEST,
    HELP
};

struct Cmd_arg {

    MODES num_mode;
    const char *short_name;
    const char *full_name;
    const char *discription;

};

Cmd_arg cmd_arg_init(MODES mode, char shrt_nm[], char fl_nm[], char discr[]);
MODES change_mode(int argc_cp, char** argv_cp);
void skip_file_name_arg(int* c, char*** v);
void help(void);

#endif //COMMAND_LINE_UNIT_H
