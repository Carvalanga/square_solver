/*!
    \file
    \brief ������������ ������� ����������� ���������
*/


#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "solver.h"
#include "equation_type.h"
#include "square_equation_struct.h"


/// \brief ��������� ����� ���� double � �����
cmp dbl_zero_cmp(double n1) {
    const double accuracy = 0.0000001;
    if (n1 > accuracy)
        return more_than_zero;
    else if (fabs(n1) < accuracy)
        return equal_zero;
    else
        return less_than_zero;
}
/*!
    \param[in] ptr_eq ��������� �� ��������� ����������� ���������
    \return ��� ����������� ���������
    \brief ������� ����������� ���������
    \details ������� ������ ���������� ��������� ������ �� �������� � ��������� �������������:
            ����� ��������� ������������ � ���������, � �� ����� ��������� ��� ����������� ���������,
                ������� ������������ �������������� �������� ������
*/
equation_type square_solver(sqr_eq* ptr_eq) {

    assert(ptr_eq != NULL);


    if (dbl_zero_cmp(ptr_eq->cfs.first) == equal_zero) {
        if (dbl_zero_cmp(ptr_eq->cfs.second) == equal_zero) {
            return (dbl_zero_cmp(ptr_eq->cfs.third) == equal_zero) ? infinity_root_eq : zero_root_eq;
        }

        equation_type result = linear_eq_solver(ptr_eq);
        ptr_eq->rts.x2 = ptr_eq->rts.x1;
        return result;
    }

    double disc = ptr_eq->cfs.second * ptr_eq->cfs.second - 4 * ptr_eq->cfs.first * ptr_eq->cfs.third;
    switch (dbl_zero_cmp(disc)) {
        case more_than_zero: {

            double sqrt_disc = sqrt(disc);
            ptr_eq->rts.x1 = (-ptr_eq->cfs.second + sqrt_disc)/(2 * ptr_eq->cfs.first);
            ptr_eq->rts.x2 = (-ptr_eq->cfs.second - sqrt_disc)/(2 * ptr_eq->cfs.first);
            return two_root_eq;
        }
        case equal_zero:
            ptr_eq->rts.x1 = ptr_eq->rts.x2 = (-ptr_eq->cfs.second)/(2 * ptr_eq->cfs.first);
            return one_root_eq;
        case less_than_zero:
            return zero_root_eq;
        default:
            printf("������: �������� �������� ��������� � �����");
            return error;
    }
}
/// \brief ������� ������ ��� ������� ��������� ���������
equation_type linear_eq_solver(sqr_eq* ptr_eq) {
    ptr_eq->rts.x1 = (-ptr_eq->cfs.third / ptr_eq->cfs.second);
    return one_root_eq;
}
