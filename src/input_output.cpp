/*!
    \file
    \brief Обеспечивает ввод и вывод программы
*/


#include <stdio.h>
#include <assert.h>

#include<TXlib.h>

#include "input_output.h"
#include "square_equation_struct.h"

static void skip_char_line(void);

/*!
    \param[in,out] ptr_eq
        Указатель на структуру квадратного уравнения

    \brief Функция, обрабатывающая входные данные
            для квадратного уравнения

    \details Принимает указатель на структуру квадратного
                уравнения и записывает в ее коэффициенты данные
                    из потока ввода
*/

void data_input(sqr_eq* ptr_eq) {

    assert(ptr_eq != NULL);

    const int correct_var_count = 3;
    int var_count = 0;
    while (var_count != correct_var_count){
        var_count = scanf("%lf %lf %lf", &ptr_eq->cfs.first,
                                         &ptr_eq->cfs.second,
                                         &ptr_eq->cfs.third);
        if (var_count != correct_var_count) {
            printf("Ошибка: неправильный ввод данных, повторите попытку:\n");
            skip_char_line();
        }
    }
}

/*!
    \param[in]  root_count Количество корней квадратного уравнения,
                определяющее дальнейший вывод данных программы

    \param[in]  rts Структура данных, содержащая корни решенного
                квадратного уравнения

    \return 0 - при правильном завершении работы программы,
            1 - при ошибке

    \brief Выводит результат работы квадратного уравнения в поток вывода
*/

int show_result(equation_type root_count, roots rts) {

    switch (root_count) {

        case zero_root_eq:
            printf("У данного уравнения нет решений\n");
            return 0;

        case infinity_root_eq:
            printf("У данного уравнения существует бесконечно много решений\n");
            return 0;

        case one_root_eq:
            printf("У данного уравнения существует один корень:\n\tx = %.3f\n", rts.x1);
            return 0;

        case two_root_eq:
            printf("У данного уравнения существует два корня:\n\tx1 = %.3f\n\tx2 = %.3f\n", rts.x1,
                                                                                          rts.x2);
            return 0;

        case error:
            return 1;

        default:
            printf("Ошибка: неопознанное значение количества корней\n");
            return 2;
    }
}

/// \details Убирает неверные данные из потока ввода, чистит карму, приносит удачу

void skip_char_line(void){
    while (getchar() != '\n');
}
