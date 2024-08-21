#include <stdio.h>
#include <TXLib.h>
#include <math.h>

#include "equation_type.h"
#include "input_output.h"
#include "solver.h"
#include "square_equation_struct.h"

int main(){
    printf("#Программа решения квадратных уравнений\n#Введите через пробел коээфициенты квадратного уравнения:\n");

    sqr_eq eq = {};

    data_input(&eq.cfs.first, &eq.cfs.second, &eq.cfs.third);

    //double root1 = 0, root2 = 0;

    equation_type root_count = square_solver(eq.cfs.first, eq.cfs.second, eq.cfs.third, &eq.rts.x1, &eq.rts.x2);
    int output = show_result(root_count, eq.rts.x1, eq.rts.x2);

    return output;
}
