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
