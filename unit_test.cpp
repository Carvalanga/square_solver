#include "square_equation_struct.h"

int test_start();
void test_iteration();


int test_start(){

}
//”казывать так, что x1 > x2
void test_iteration(int test_num, sqr_eq* ptr_eq, roots* ptr_correct_roots, int correct_root_count){
    int root_count = solver(ptr_eq->cfs.first, ptr_eq->cfs.second, ptr_eq->cfs.third, &ptr_eq->rts.x1, &ptr_eq->rts.x2);
    if (root_count != correct_root_count || ptr_eq->rts.x1 != ptr_correct_roots->x1 || ptr_eq->rts.x2 != ptr_correct_roots->x2){
        printf("ќшибка в тесте номер %d\n"
               "»тоговые значени€:  root_count = %d, x1 = %lg, x2 = %lg\n"
               "ќжидаемые значени€: root_count = %d, x1 = %lg, x2 = %lg\n",
                root_count, ptr_eq->rts.x1, ptr_eq->rts.x2,
                correct_root_count, ptr_correct_roots->x1, ptr_correct_roots->x2);
    }
}
