/*!
    \file
    \brief Заголовочный файл для ввода и вывода данных
*/

#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include "equation_type.h"
#include "square_equation_struct.h"

void data_input(sqr_eq* prt_eq);

int show_result(equation_type root_count, roots rts);

#endif // INPUT_OUTPUT_H
