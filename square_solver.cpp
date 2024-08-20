#include <stdio.h>
#include <TXLib.h>
#include <math.h>

enum equation_type {SS_not_solve_eq, SS_infinity_root_eq, SS_linear_eq, SS_square_eq, SS_square_one_root_eq, SS_error};
enum cmp {less_than_zero = -1, equal_zero, more_than_zero};

equation_type square_solver(double first_coef, double second_coef, double third_coef, double* root1, double* root2);
cmp dbl_zero_cmp(double number);
void data_input(double* first_coef, double* second_coef, double* third_coef);
int show_result(equation_type root_count, double root1, double root2);
void skip_char_line(void);


int main(){
    printf("#��������� ������� ���������� ���������\n#������� ����� ������ ������������ ����������� ���������:\n");

    double first_coef = 0, second_coef = 0, third_coef = 0;

    data_input(&first_coef, &second_coef, &third_coef);

    double root1 = 0, root2 = 0;

    equation_type root_count = square_solver(first_coef, second_coef, third_coef, &root1, &root2);
    int output = show_result(root_count, root1, root2);

    return output;
}

void data_input(double* first_coef, double* second_coef, double* third_coef) {

    assert(first_coef != NULL);
    assert(second_coef != NULL);
    assert(third_coef != NULL);

    const int correct_var_count = 3;
    int var_count = 0;
    while (var_count != correct_var_count){
        var_count = scanf("%lf %lf %lf", first_coef, second_coef, third_coef);
        if (var_count != correct_var_count) {
            printf("������: ������������ ���� ������, ��������� �������:\n");
            skip_char_line();
        }
    }
}

void skip_char_line(void){
    while (getchar() != '\n');
}

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
        *root1 = *root2 = (-third_coef / second_coef);
        return SS_linear_eq;
    }
    else {
        double disc = second_coef*second_coef - 4 * first_coef * third_coef;
        switch (dbl_zero_cmp(disc)) {
            case more_than_zero: {

                double sqrt_disc = sqrt(disc);
                *root1 = (-second_coef + sqrt_disc)/2;
                *root2 = (-second_coef - sqrt_disc)/2;
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

int show_result(equation_type root_count, double root1, double root2) {
    switch (root_count) {
        case SS_not_solve_eq:
            printf("� ������� ��������� ��� �������\n");
            return 0;
        case SS_infinity_root_eq:
            printf("� ������� ��������� ���������� ���������� ����� �������\n");
            return 0;
        case SS_linear_eq:
            printf("� ������� ��������� ���������� ���� ������:\n\tx = %.3f", root1);
            return 0;
        case SS_square_eq:
            printf("� ������� ��������� ���������� ��� �����:\n\tx1 = %.3f\n\tx2 = %.3f", root1, root2);
            return 0;
        default:
            printf("������: ������������ �������� ���������� ������");
            return 1;
    }
}
