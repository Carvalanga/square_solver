/*!

    \mainpage
    \file
    \brief Обеспечивает работу всей программы

*/

#include <stdio.h>
#include <stdlib.h>

#include <TXlib.h>

#include "unit_test.h"
#include "square_solver.h"
#include "command_line_unit.h"

/// \brief Обесчивает работу всей программы

void start_program(MODES program_mode);

int main(int argc, char* argv[]) {

    MODES mode = SOLVE;

    if (argc > 1)
        check_args(argc, argv, &mode);

}

void start_program(MODES program_mode) {
    switch (program_mode){
        case SOLVE:
            return solve_mode_start();

        case TEST:
            unit_test_start();
            return 0;

        default:
            txSetConsoleAttr(2);
            printf("Ошибка: неизвестый режим работы программы\n");
            txSetConsoleAttr(15);
            return -1;
    }
}
