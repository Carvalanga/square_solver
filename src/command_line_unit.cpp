#include <string.h>
#include <stdio.h>

#include "command_line_unit.h"


static Cmd_arg arg_array[] = {

    {SOLVE, "-s", "--solve_mode", "-s или --solve_mode - Решение квадратного уравнения\n"},
    {TEST,  "-t", "--test_mode",  "-t или --test_mode - Тестирование работы программы\n"},
    {HELP,  "-h", "--help",       "-h или --help - Вывести данные о принимаемых аргументах\n"},
    {INPUT, "-i", "--input",      "-i или --input - Перевести режим чтения с консоли на режим чтения пользвательского файла\n"}

};

void check_args(int argc_cp, char** argv_cp, MODES* md) {

    for (int iter = 0; iter < argc_cp; iter++) {

        for (size_t arg_num = 0; arg_num < sizeof(arg_array)/sizeof(arg_array[0]); arg_num++) {

            if (

                strcmp(arg_array[arg_num].short_name, argv_cp[iter]) == 0 ||
                strcmp(arg_array[arg_num].full_name,  argv_cp[iter]) == 0) {
                    change_mode(md);

            }
        }
    }

    return SOLVE;

}

int help(void) {
    for (size_t iter = 0; iter < sizeof(arg_array)/sizeof(arg_array[0]); iter++) {
        printf("%s\n", arg_array[iter].discription);
    }
    return 0;
}

MODES solve_test_switcher(MODES prorgam_mode) {
    return (program_mode == SOLVE) ? TEST : SOLVE;
}

void change_mode(MODES* mode) {

    switch (mode) {

        case SOLVE:
        case TEST:
            *mode = solve_test_switcher;

        case HELP:
            help();

        case INPUT:

    }
}




