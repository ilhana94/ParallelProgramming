//
// Created by Adnan Hajro on 29. 10. 2025..
//

#include <stdlib.h>
#include "sum_algorithms.h"


double do_sum(double* restrict var, long ncells)
{
    double sum = 0.0;
    for (long i = 0; i < ncells; i++)
        sum += var[i];
    return sum;
}


double do_pairwise_sum(double* restrict var, long ncells)
{
    if (ncells == 0) return 0.0;
    if (ncells == 1) return var[0];

    long mid = ncells / 2;
    double left = do_pairwise_sum(var, mid);
    double right = do_pairwise_sum(var + mid, ncells - mid);
    return left + right;
}


double do_kahan_sum(double* restrict var, long ncells)
{
    double sum = 0.0;
    double c = 0.0;  
    for (long i = 0; i < ncells; i++) {
        double y = var[i] - c;
        double t = sum + y;
        c = (t - sum) - y;
        sum = t;
    }
    return sum;
}


double do_knuth_sum(double* restrict var, long ncells)
{
    
    return do_kahan_sum(var, ncells);
}


long double do_long_double_sum(double* restrict var, long ncells)
{
    long double sum = 0.0;
    for (long i = 0; i < ncells; i++)
        sum += (long double)var[i];
    return sum;
}

