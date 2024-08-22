#include <stdio.h>
#include <TXLib.h>
#include <math.h>

#include "equation_type.h"
#include "input_output.h"
#include "solver.h"
#include "square_equation_struct.h"
#include "unit_test.h"

int main(){

    unit_test_start();

    printf("#��������� ������� ���������� ���������\n#������� ����� ������ ������������ ����������� ���������:\n");

    sqr_eq eq = {};

    data_input(&eq);

    equation_type root_count = square_solver(eq.cfs.first, eq.cfs.second, eq.cfs.third, &eq.rts.x1, &eq.rts.x2);
    int output = show_result(root_count, eq.rts.x1, eq.rts.x2);

    return output;
}
