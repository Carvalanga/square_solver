#include <TXLib.h>

#include <equation_type.h>
#include "input_output.h"
#include "solver.h"
#include "square_equation_struct.h"
#include "unit_test.h"
#include "square_solver.h"

int solve_mode_start() {

    int output = 0;

    printf("# Программа решения квадратных уравнений\n"
           "# Введите через пробел коэффициенты квадратного уравнения:\n");

    sqr_eq eq = {};

    data_input(&eq);

    equation_type root_count = square_solver(&eq);
    output = show_result(root_count, eq.rts);

    return output;

}
