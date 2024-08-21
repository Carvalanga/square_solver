#include <stdio.h>
#include <assert.h>

#include "square_equation_struct.h"
#include "solver.h"

struct expected_eq {
    sqr_eq test_eq = {};
    roots correct_roots = {};
    int correct_root_count = 0;
};

static void test_iteration(int test_num, expected_eq* ptr_ex_eq);
static void change_ex_eq_value(expected_eq* ptr_ex_eq, double a, double b, double c, double cor_x1, double cor_x2, int correct_root_count);
static int compare_correct_and_test_roots (expected_eq* peq);

void unit_test_start() {

    FILE* ptr_to_file = fopen("answers.txt", "r");
    int line_count = 0, test_num = 0, correct_root_count = 0;
    expected_eq ex_eq = {};
    double a = 0, b = 0, c = 0, cor_x1 = 0, cor_x2 = 0;
    fscanf(ptr_to_file, "%i", line_count);

    for (line_count, test_num; line_count > 0; line_count--, test_num++) {
        fscanf(ptr_to_file, "%f %f %f %f %f %i\n", a, b, c, cor_x1, cor_x2, correct_root_count);
        change_ex_eq_value(&ex_eq, a, b, c, cor_x1, cor_x2, correct_root_count);
        test_iteration(test_num, &ex_eq);

    }
}

static void test_iteration(int test_num, expected_eq* ptr_ex_eq){

    int root_count = square_solver(ptr_ex_eq->test_eq.cfs.first, ptr_ex_eq->test_eq.cfs.second, ptr_ex_eq->test_eq.cfs.third, &ptr_ex_eq->test_eq.rts.x1, &ptr_ex_eq->test_eq.rts.x2);
    if (root_count != ptr_ex_eq->correct_root_count || !compare_correct_and_test_roots(ptr_ex_eq)){
        printf("Ошибка в тесте номер %d\n"
               "Итоговые значения:  root_count = %d, x1 = %lg, x2 = %lg\n"
               "Ожидаемые значения: root_count = %d, x1 = %lg, x2 = %lg\n",
                test_num,
                root_count, ptr_ex_eq->test_eq.rts.x1, ptr_ex_eq->test_eq.rts.x2,
                ptr_ex_eq->correct_root_count, ptr_ex_eq->correct_roots.x1, ptr_ex_eq->correct_roots.x1);
    }

}

static void change_ex_eq_value(expected_eq* ptr_ex_eq, double a, double b, double c, double cor_x1, double cor_x2, int correct_root_count) {

    assert(ptr_ex_eq != NULL);

    ptr_ex_eq->test_eq.cfs.first = a;
    ptr_ex_eq->test_eq.cfs.second = b;
    ptr_ex_eq->test_eq.cfs.third = c;
    ptr_ex_eq->correct_roots.x1 = cor_x1;
    ptr_ex_eq->correct_roots.x2 = cor_x2;
    ptr_ex_eq->correct_root_count = correct_root_count;
}

static int compare_correct_and_test_roots (expected_eq* peq) {
    return((peq->test_eq.rts.x1 == peq->correct_roots.x1) && (peq->test_eq.rts.x2 == peq->correct_roots.x2));
}
