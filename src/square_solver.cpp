/*!
    \file
    \brief Обеспечивает работу всей программы

    \mainpage


*/


#include <stdio.h>
#include <TXLib.h>
#include <math.h>

#include "equation_type.h"
#include "input_output.h"
#include "solver.h"
#include "square_equation_struct.h"
#include "unit_test.h"

/// \brief Обесчивает работу всей программы
int main(){

    unit_test_start();

    printf("# Программа решения квадратных уравнений\n"
           "# Введите через пробел коэффициенты квадратного уравнения:\n");

    sqr_eq eq = {};

    data_input(&eq);

    equation_type root_count = square_solver(&eq);
    int output = show_result(root_count, eq.rts);

    return output;
}
