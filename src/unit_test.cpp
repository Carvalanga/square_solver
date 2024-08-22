/*!
    \file
    \brief Обеспечивает тестирование программы для проверки корректности
        работы
*/


#include <TXLib.h>
#include <stdlib.h>
#include <assert.h>

#include "square_equation_struct.h"
#include "solver.h"
#include "unit_test.h"

/// Объявление структры для проверки работы основной программы
struct expected_eq {
    sqr_eq test_eq         = {};
    roots correct_roots    = {};
    int correct_root_count = 0;
};

static int is_double_num_equal(double num1, double num2);
static void test_iteration(int test_num, expected_eq* ptr_ex_eq);
static void change_root_to_zero(expected_eq* ptr_ex_eq);
static int compare_correct_and_test_roots (expected_eq* peq);

/// Запускает модуль тестирования

void unit_test_start(void) {

    FILE* ptr_to_file = fopen("../data/answers.txt", "r");
    if (ptr_to_file == NULL) {

            perror ("Cannot open answers.txt");
            return;

        }
    int line_count = 0, test_num = 0;
    expected_eq ex_eq = {};

    fscanf(ptr_to_file, "%i", &line_count);

    for (; line_count > 0; line_count--) {
        fscanf(ptr_to_file, "%lf %lf %lf %lf %lf %i\n", &ex_eq.test_eq.cfs.first,
                                                        &ex_eq.test_eq.cfs.second,
                                                        &ex_eq.test_eq.cfs.third,
                                                        &ex_eq.correct_roots.x1,
                                                        &ex_eq.correct_roots.x2,
                                                        &ex_eq.correct_root_count);

        change_root_to_zero(&ex_eq);

        test_iteration(test_num, &ex_eq);
        test_num++;
    }

    fclose (ptr_to_file);
}

/*!
    \param[in] test_num Номер теста для удобства отслеживания места ошибки
    \param[in,out] ptr_ex_eq Указатель на структуру для проверки работы основной программы
    \brief Сравнивает результат работы программы с ожидаемым результом и при несоответствии выводит ошибку
*/
static void test_iteration(int test_num, expected_eq* ptr_ex_eq){

    int root_count = square_solver(&ptr_ex_eq->test_eq);

    if (root_count != ptr_ex_eq->correct_root_count || !compare_correct_and_test_roots(ptr_ex_eq))

        printf("Ошибка в тесте номер %d\n"
               "Итоговые значения:  root_count = %d, x1 = %lg, x2 = %lg\n"
               "Ожидаемые значения: root_count = %d, x1 = %lg, x2 = %lg\n"
               "\n",
                test_num+1,
                root_count,
                ptr_ex_eq->test_eq.rts.x1,
                ptr_ex_eq->test_eq.rts.x2,
                ptr_ex_eq->correct_root_count,
                ptr_ex_eq->correct_roots.x1,
                ptr_ex_eq->correct_roots.x2);

}

/// Сбрасывает значения корней на стандартные для корректной работы программы
static void change_root_to_zero(expected_eq* ptr_ex_eq) {

    assert(ptr_ex_eq != NULL);

    ptr_ex_eq->test_eq.rts.x1     = 0;
    ptr_ex_eq->test_eq.rts.x2     = 0;

}

/// Сравнивание чисел типа double
static int compare_correct_and_test_roots (expected_eq* peq) {
    return (is_double_num_equal(peq->test_eq.rts.x1, peq->correct_roots.x1) &&
            is_double_num_equal(peq->test_eq.rts.x2, peq->correct_roots.x2));

}
/// Вспомогательная функция для сравнивания чисел типа double
static int is_double_num_equal(double num1, double num2){
    const double accuracy = 0.0001;
    return (fabs(num1 - num2) < accuracy);
}
