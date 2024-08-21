#include <stdio.h>
#include <TXLib.h>
#include <math.h>

#include "equation_type.h"
#include "input_output.h"
#include "solver.h"

int main(){
    printf("#Программа решения квадратных уравнений\n#Введите через пробел коээфициенты квадратного уравнения:\n");

    double first_coef = 0, second_coef = 0, third_coef = 0;

    data_input(&first_coef, &second_coef, &third_coef);

    double root1 = 0, root2 = 0;

    equation_type root_count = square_solver(first_coef, second_coef, third_coef, &root1, &root2);
    int output = show_result(root_count, root1, root2);

    return output;
}
