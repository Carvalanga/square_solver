/*!
    \file
    \brief Заголовочный файл с определением структуры квадратного уравнения
*/

#ifndef SQUARE_EQUATION_STRUCT_H
#define SQUARE_EQUATION_STRUCT_H

struct coeffs {         ///Структура коэффициентов квадратного уравнения
    double first = 0;   ///<Первый коэффициент
    double second = 0;  ///<Второй коэффициент
    double third = 0;   ///<Третий коэффициент
};

struct roots {          ///Структура корней квадратного уравнения
    double x1 = 0;      ///<Первый корень уравнения
    double x2 = 0;      ///<Второй корень уравнения
};

struct sqr_eq {         ///Структура квадратного уравнения
    coeffs cfs = {};    ///<Коэффициенты квадратного уравнения
    roots rts = {};     ///<Корни квадратнтго уравнения
};

#endif //SQUARE_EQUATION_STRUCT_H
