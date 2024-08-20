#include <stdio.h>
#include <assert.h>

#include "input_output.h"

static void skip_char_line(void);

void data_input(double* first_coef, double* second_coef, double* third_coef) {

    assert(first_coef != NULL);
    assert(second_coef != NULL);
    assert(third_coef != NULL);

    const int correct_var_count = 3;
    int var_count = 0;
    while (var_count != correct_var_count){
        var_count = scanf("%lf %lf %lf", first_coef, second_coef, third_coef);
        if (var_count != correct_var_count) {
            printf("Ошибка: неправильный ввод данных, повторите попытку:\n");
            skip_char_line();
        }
    }
}

int show_result(equation_type root_count, double root1, double root2) {
    switch (root_count) {
        case SS_not_solve_eq:
            printf("У данного уравнения нет решений\n");
            return 0;
        case SS_infinity_root_eq:
            printf("У данного уравнения существует бесконечно много решений\n");
            return 0;
        case SS_linear_eq:
            printf("У данного линейного уравнения существует один корень:\n\tx = %.3f", root1);
            return 0;
        case SS_square_eq:
            printf("У данного квадратного уравнения существует два корня:\n\tx1 = %.3f\n\tx2 = %.3f", root1, root2);
            return 0;
        case SS_square_one_root_eq:
            printf("У данного квадратного уравнения один корень:\n\tx = %.3f", root1);
            return 0;
        default:
            printf("Ошибка: неопознанное значение количества корней");
            return 1;
    }
}

void skip_char_line(void){
    while (getchar() != '\n');
}
