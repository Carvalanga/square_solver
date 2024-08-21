#ifndef SQUARE_EQUATION_STRUCT_H
#define SQUARE_EQUATION_STRUCT_H

struct coeffs {
    double first = 0;
    double second = 0;
    double third = 0;
};

struct roots {
    double x1 = 0;
    double x2 = 0;
};

struct sqr_eq {
    coeffs cfs = {};
    roots rts = {};
};

#endif //SQUARE_EQUATION_STRUCT_H
