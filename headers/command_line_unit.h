/*!
    \file
    \brief Обеспечивает ввод аргументов командной строки
*/


#ifndef COMMAND_LINE_UNIT_H
#define COMMAND_LINE_UNIT_H
                                    /// \breif Перечисление режимов работы программы
enum MODES {
    SOLVE,                          ///<Режим решения квадратного уравнения с вводом коэффициентов из консоли
    TEST,                           ///<Режим тестирования работы квадратного уравнения
    HELP                            ///<Вывод подсказок для запуска режимов работы
};

                                    /// \breif Структура для работы с заданными аргументами командной строки
struct Cmd_arg {

    MODES mode;                     ///<Режим работы
    const char *short_name;         ///<Короткая команда вызова
    const char *full_name;          ///<Полная команда вызова
    const char *discription;        ///<Описание режима

};

void check_args(int argc_cp, char** argv_cp, MODES* mode);

void change_mode(MODES* mode, MODES cur_md);

int help(void);

#endif //COMMAND_LINE_UNIT_H
