#include <stdio.h>
#include <assert.h>

#include "input_output.h"
#include "square_equation_struct.h"

static void skip_char_line(void);

void data_input(sqr_eq* ptr_eq) {

    assert(ptr_eq != NULL);

    const int correct_var_count = 3;
    int var_count = 0;
    while (var_count != correct_var_count){
        var_count = scanf("%lf %lf %lf", &ptr_eq->cfs.first,
                                         &ptr_eq->cfs.second,
                                         &ptr_eq->cfs.third);
        if (var_count != correct_var_count) {
            printf("������: ������������ ���� ������, ��������� �������:\n");
            skip_char_line();
        }
    }
}

int show_result(equation_type root_count, double root1, double root2) {
    switch (root_count) {
        case zero_root_eq:
            printf("� ������� ��������� ��� �������\n");
            return 0;
        case infinity_root_eq:
            printf("� ������� ��������� ���������� ���������� ����� �������\n");
            return 0;
        case one_root_eq:
            printf("� ������� ��������� ���������� ���� ������:\n\tx = %.3f", root1);
            return 0;
        case two_root_eq:
            printf("� ������� ��������� ���������� ��� �����:\n\tx1 = %.3f\n\tx2 = %.3f", root1, root2);
            return 0;
        case error:
            return 1;
        default:
            printf("������: ������������ �������� ���������� ������");
            return 1;
    }
}

void skip_char_line(void){
    while (getchar() != '\n');
}
