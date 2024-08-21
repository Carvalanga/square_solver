#ifndef SQUARE_EQUATION_STRUCT_H
#define SQUARE_EQUATION_STRUCT_H

struct coeffs {
    double first;
    double second;
    double third;
};

struct roots {
    double* x1;
    double* x2;
};

struct square_equation {
    coeffs cfs;
    roots rts;
};

#ednif //SQUARE_EQUATION_STRUCT_H
