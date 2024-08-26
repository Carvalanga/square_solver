/*!
    \file
    \brief ������������ ������ ���� ���������
*/

#include <stdio.h>
#include <stdlib.h>

#include <TXlib.h>

#include "unit_test.h"
#include "square_solver.h"
#include "command_line_unit.h"

int start_program(MODES md);

int main(int argc, char* argv[]) {

    MODES main_mode = SOLVE;

    if (argc > 1) {
        check_args(argc, argv, &main_mode);
    }
    return start_program(main_mode);

}

/*!
    \param[in] md       ��� ������������ ������
    \return             ���������� 0 ��� �������� ���������� ���������, ����� - ��������� ��������
    \brief              ��������� ��������� � ��������� ������
*/
int start_program(MODES md) {
    switch (md) {
        case SOLVE:
            return solve_mode_start();

        case TEST:
            unit_test_start();
            return 0;

        case HELP:
            return help();

        default:
            txSetConsoleAttr(2);
            printf("������: ���������� ����� ������ ���������\n");
            txSetConsoleAttr(15);
            return -1;
    }
}
