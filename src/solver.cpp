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
            return (dbl_zero_cmp(third_coef) == equal_zero) ? infinity_root_eq : zero_root_eq;
        }

        equation_type result = linear_eq_solver(second_coef, third_coef, root1);
        *root2 = *root1;
        return result;
    }

    double disc = second_coef*second_coef - 4 * first_coef * third_coef;
    switch (dbl_zero_cmp(disc)) {
        case more_than_zero: {

            double sqrt_disc = sqrt(disc);
            *root1 = (-second_coef + sqrt_disc)/(2 * first_coef);
            *root2 = (-second_coef - sqrt_disc)/(2 * first_coef);
            return two_root_eq;

        }
        case equal_zero:
            *root1 = *root2 = (-second_coef)/(2 * first_coef);
            return one_root_eq;
        case less_than_zero:
            return zero_root_eq;
        default:
            printf("Ошибка: неверное значение сравнения с нулем");
            return error;
    }
}

equation_type linear_eq_solver(double first_coef, double second_coef, double* root) {
    *root = (-second_coef / first_coef);
    return one_root_eq;
}
