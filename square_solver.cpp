#include <stdio.h>
#include <TXLib.h>
#include <math.h>

int square_solver(double, double, double, double*, double*);
int dbl_zero_cmp(double, double);
void data_input(double*, double*, double*);

enum equation_cases {SS_not_solve_eq, SS_infinity_root_eq, SS_linear_eq, SS_square_eq, SS_square_one_root_eq};
enum cmp_cases {less_than_zero = -1, equal_zero, more_than_zero};

const double accuracy = 0.0000001;
const int correct_var_count = 3;

int main(){

    double first_coef = 0, second_coef = 0, third_coef = 0;

    data_input(&first_coef, &second_coef, &third_coef);

    double root1 = 0, root2 = 0;

    int root_count = square_solver(first_coef, second_coef, third_coef, &root1, &root2);

    switch (root_count) {
        case SS_not_solve_eq:
            printf("� ������� ��������� ��� �������\n");
            break;
        case SS_infinity_root_eq:
            printf("� ������� ��������� ���������� ���������� ����� �������\n");
            break;
        case SS_linear_eq:
            printf("� ������� ��������� ���������� ���� ������:\n\tx = %.3f", root1);
            break;
        case SS_square_eq:
            printf("� ������� ��������� ���������� ��� �����:\n\tx1 = %.3f\n\tx2 = %.3f", root1, root2);
            break;
        default:
            printf("������");
            return 2;
    }

    return 0;
}

void data_input(double* first_coef, double* second_coef, double* third_coef) {
    printf("#��������� ������� ���������� ���������\n#������� ����� ������ ������������ ����������� ���������:\n");
    int var_count = 0;
    while (var_count != correct_var_count){
        var_count = scanf("%lf %lf %lf", &first_coef, &second_coef, &third_coef);
        if (var_count != correct_var_count) {
            printf("������: ������������ ���� ������, ��������� �������:");
        }
    }
}

int dbl_zero_cmp(double n1) {
    if (n1 > accuracy)
        return more_than_zero;
    else if (fabs(n1) < accuracy)
        return equal_zero;
    else
        return less_than_zero;
}

int square_solver(double first_coef, double second_coef, double third_coef, double* root1, double* root2) {
    if (dbl_zero_cmp(first_coef) == 0) {
        if (dbl_zero_cmp(second_coef) == 0){
            return (dbl_zero_cmp(third_coef) == 0) ? SS_infinity_root_eq : SS_not_solve_eq;
        }
        *root1 = *root2 = (-third_coef / second_coef);
        return SS_linear_eq;
    }
    else {
        double disc = second_coef*second_coef - 4 * first_coef * third_coef;
        switch (dbl_zero_cmp(disc)) {
            case more_than_zero:
                *root1 = (-second_coef + sqrt(disc))/2;
                *root2 = (-second_coef - sqrt(disc))/2;
                return SS_square_eq;
            case equal_zero:
                *root1 = (-second_coef)/2;
                return SS_square_one_root_eq;
            case less_than_zero:
                return SS_not_solve_eq;
        }
    }
}
