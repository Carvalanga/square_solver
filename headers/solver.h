/*!
    \file
    \brief Заголовочный файл для решения квадратного уравнения
*/

#ifndef SOLVER_H
#define SOLVER_H

#include "input_output.h"
#include "square_equation_struct.h"

enum cmp {                  ///Перечисление типов сравнения числа с нулем
    less_than_zero = -1,    ///<Меньше нуля
    equal_zero,             ///<Равно нулю
    more_than_zero          ///<Больше нуля
};

equation_type square_solver(sqr_eq* ptr_eq);
cmp dbl_zero_cmp(double number);
equation_type linear_eq_solver(sqr_eq* ptr_eq);

#endif //SOLVER_H
