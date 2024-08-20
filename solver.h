#ifndef SOLVER_H
#define SOLVER_H

#include "input_output.h"
enum cmp {
    less_than_zero = -1,
    equal_zero,
    more_than_zero
};

equation_type square_solver(double first_coef, double second_coef, double third_coef, double* root1, double* root2);
cmp dbl_zero_cmp(double number);
equation_type linear_eq_solver(double first_coef, double second_coef, double* root);

#endif //SOLVER_H
