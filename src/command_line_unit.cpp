#include <string.h>
#include <stdio.h>

#include "command_line_unit.h"


static Cmd_arg arg_array[] = {

    {SOLVE, "-s", "--solve_mode", "-s ��� --solve_mode - ������� ����������� ���������\n"},
    {TEST,  "-t", "--test_mode",  "-t ��� --test_mode - ������������ ������ ���������\n"},
    {HELP,  "-h", "--help",       "-h ��� --help - ������� ������ � ����������� ����������\n"}

};

MODES change_mode(int argc_cp, char** argv_cp) {

    for (int iter = 0; iter < argc_cp; iter++) {

        for (size_t arg_num = 0; arg_num < sizeof(arg_array)/sizeof(arg_array[0]); arg_num++) {

            if (

                strcmp(arg_array[arg_num].short_name, argv_cp[iter]) == 0 ||
                strcmp(arg_array[arg_num].full_name,  argv_cp[iter]) == 0) {

                    return arg_array[arg_num].num_mode;

            }
        }
    }

    return SOLVE;

}

void help(void) {
    for (size_t iter = 0; iter < sizeof(arg_array)/sizeof(arg_array[0]); iter++) {
        printf("%s\n", arg_array[iter].discription);
    }
}
