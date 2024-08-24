/*!

    \mainpage
    \file
    \brief Обеспечивает работу всей программы

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <TXlib.h>

#include "unit_test.h"
#include "square_solver.h"



enum MODES {
    SOLVE,
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

Cmd_arg arg_array[] = {

    {SOLVE, "--s", "-solve_mode", "--s или -solve_mode - Решение квадратного уравнения\n"},
    {TEST, "--t", "-test_mode", "--t или -test_mode - Тестирование работы программы\n"},
    {HELP, "--h", "--help", "--h или -help - Вывести данные о принимаемых аргументах\n"}

};



/// \brief Обесчивает работу всей программы
int main(int argc, char* argv[]) {

    MODES mode = SOLVE;

    if (argc > 1)
        mode = change_mode(argc, argv);

    switch (mode) {

        case SOLVE:
            return solve_mode_start();

        case TEST:
            unit_test_start();
            return 0;

        case HELP:
            help();
            return 0;

        default:
            txSetConsoleAttr(2);
            printf("Ошибка: неизвестый режим работы программы\n");
            txSetConsoleAttr(15);
            return -1;

    }


}

MODES change_mode(int argc_cp, char** argv_cp) {

    for (int iter = 0; iter < argc_cp; iter++) {

        for (int arg_num = 0; arg_num < sizeof(arg_array)/sizeof(arg_array[0]); arg_num++) {

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
    for (int iter = 0; iter < sizeof(arg_array)/sizeof(arg_array[0]); iter++) {
        printf("%s\n", arg_array[iter].discription);
    }
}
