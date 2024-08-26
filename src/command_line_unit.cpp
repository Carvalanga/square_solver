/*!
    \file
    \brief Обеспечивает работу ввода аргументов командной строки
*/

#include <string.h>
#include <stdio.h>
#include <assert.h>

#include "command_line_unit.h"


static Cmd_arg arg_array[] = {

    {SOLVE,      "-s", "--solve_mode", "-s или --solve_mode - Решение квадратного уравнения\n"},
    {TEST,       "-t", "--test_mode",  "-t или --test_mode - Тестирование работы программы\n"},
    {HELP,       "-h", "--help",       "-h или --help - Вывести данные о принимаемых аргументах\n"}

};

/*!
    \param[in] argc_cp Копия количества аргументов командной строки
    \param[in] argv_cp Копия аргументов командной строки
    \param[in,out] mode Режим работы, который может быть изменен благодаря аргументам командной строки
    \brief Просматривает аргументы командной строки для дальнейшей работы с каждым из них
*/
void check_args(int argc_cp, char** argv_cp, MODES *mode) {

    for (int iter = 0; iter < argc_cp; iter++) {

        for (size_t arg_num = 0; arg_num < sizeof(arg_array)/sizeof(arg_array[0]); arg_num++) {

            if (
                strcmp(arg_array[arg_num].short_name, argv_cp[iter]) == 0 ||
                strcmp(arg_array[arg_num].full_name,  argv_cp[iter]) == 0) {
                    change_mode(mode, arg_array[arg_num].mode);

            }
        }
    }
}

/*!
    \return Возвращает 0 - успешное завершение программы
    \brief  Выводит информацию о каждом допустимом аргументе командной строки
*/
int help(void) {
    for (size_t iter = 0; iter < sizeof(arg_array)/sizeof(arg_array[0]); iter++) {
        printf("%s\n", arg_array[iter].discription);
    }
    return 0;
}


/*!
    \param[in,out] mode Режим работы программы, который будет изменен
    \param[in] cur_md Режим работы программы, который будет активирован
    \brief Меняет режим работы программы
*/
void change_mode(MODES* mode, MODES md) {

    switch (md) {

        case SOLVE:
            *mode = SOLVE;
            break;

        case TEST:
            *mode = TEST;
            break;

        case HELP:
            *mode = HELP;
            break;

        default:
            printf("Ошибка: неопознанный режим работы");
            break;

    }
}
