#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "solver.h"
#include "equation_type.h"

cmp dbl_zero_cmp(double n1) {
    const double accuracy = 0.0000001;
    if (n1 > accuracy)
        return more_than_zero;
    else if (fabs(n1) < accuracy)
        return equal_zero;
    else
        return less_than_zero;
}

equation_type square_solver(double first_coef, double second_coef, double third_coef, double* root1, double* root2) {

    assert(root1 != NULL);
    assert(root2 != NULL);

    if (dbl_zero_cmp(first_coef) == equal_zero) {
        if (dbl_zero_cmp(second_coef) == equal_zero) {
            return (dbl_zero_cmp(third_coef) == equal_zero) ? SS_infinity_root_eq : SS_not_solve_eq;
        }
        return linear_eq_solver(second_coef, third_coef, root1);
    }
    else {
        double disc = second_coef*second_coef - 4 * first_coef * third_coef;
        switch (dbl_zero_cmp(disc)) {
            case more_than_zero: {

                double sqrt_disc = sqrt(disc);
                *root1 = (-second_coef + sqrt_disc)/(2 * first_coef);
                *root2 = (-second_coef - sqrt_disc)/(2 * first_coef);
                return SS_square_eq;
            }
            case equal_zero:
                *root1 = (-second_coef)/2;
                return SS_square_one_root_eq;
            case less_than_zero:
                return SS_not_solve_eq;
            default:
                printf("������: �������� �������� ��������� � �����");
                return SS_error;
        }
    }
}

equation_type linear_eq_solver(double first_coef, double second_coef, double* root) {
    *root = second_coef / first_coef;
    return SS_linear_eq;
}
