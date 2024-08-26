/*!
    \file
    \brief Заголовочный файл для типов квадратного уравнения
*/

#ifndef EQUATION_TYPE_H
#define EQUATION_TYPE_H

enum equation_type {    ///Типы квадратных уравнений

    error = -1,         ///<Ошибочный тип
    zero_root_eq,       ///<Уравнение без корней
    one_root_eq,        ///<Уравнение с одним корнем
    two_root_eq,        ///<Уравнение с двумя корнями
    infinity_root_eq    ///<Уравнение с бесконечным количеством корней

};

#endif //EQUATION_TYPE_H
