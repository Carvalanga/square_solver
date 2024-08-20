#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

enum equation_type {
    SS_not_solve_eq,
    SS_infinity_root_eq,
    SS_linear_eq,
    SS_square_eq,
    SS_square_one_root_eq,
    SS_error
};

void data_input(double* first_coef, double* second_coef, double* third_coef);

int show_result(equation_type root_count, double root1, double root2);

#endif // INPUT_OUTPUT_H
