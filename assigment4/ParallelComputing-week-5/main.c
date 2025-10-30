//
// Created by Adnan Hajro on 29. 10. 2025..
//

#define _POSIX_C_SOURCE 199309L

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "sum_algorithms.h"

#define ORDERS_OF_MAGNITUDE 1.0e9

void cpu_timer_start(struct timespec *tstart_cpu) {
    clock_gettime(CLOCK_MONOTONIC, tstart_cpu);
}

double cpu_timer_stop(struct timespec tstart_cpu) {
    struct timespec tstop_cpu, tresult;

    clock_gettime(CLOCK_MONOTONIC, &tstop_cpu);

    tresult.tv_sec = tstop_cpu.tv_sec - tstart_cpu.tv_sec;
    tresult.tv_nsec = tstop_cpu.tv_nsec - tstart_cpu.tv_nsec;

    double result = (double)tresult.tv_sec + (double)tresult.tv_nsec * 1.0e-9;
    return result;
}

int main(int argc, char *argv[])
{
    printf("========================================\n\n");

    for (int pow_of_two = 10; pow_of_two <= 27; pow_of_two++) {
        long ncells = (long)pow(2.0, (double)pow_of_two);
        long ncellsdiv2 = ncells / 2;

        printf("========================================\n");
        printf("TESTING WITH 2^%d = %ld elements\n", pow_of_two, ncells);
        printf("========================================\n");

        double high_value = 1.0e-1;
        double low_value  = 1.0e-1 / ORDERS_OF_MAGNITUDE;

        double accurate_sum = (double)ncellsdiv2 * high_value +
                              (double)ncellsdiv2 * low_value;

        double *energy = (double *)malloc(ncells * sizeof(double));
        if (!energy) {
            fprintf(stderr, "Error: Failed to allocate memory for %ld elements\n", ncells);
            return 1;
        }

        for (long i = 0; i < ncells; i++)
            energy[i] = (i < ncellsdiv2) ? high_value : low_value;

        printf("Expected accurate sum: %-17.16lg\n\n", accurate_sum);

        struct timespec cpu_timer;
        double cpu_time;
        double test_sum;
        long double ld_sum;

        // Standard double sum
        cpu_timer_start(&cpu_timer);
        test_sum = do_sum(energy, ncells);
        cpu_time = cpu_timer_stop(cpu_timer);
        printf("Method: Standard double      Sum: %-17.16lg Diff: %10.4lg Relative Diff: %10.4lg Runtime: %lf\n",
               test_sum, test_sum - accurate_sum, (test_sum - accurate_sum)/accurate_sum, cpu_time);

        // Pairwise sum
        cpu_timer_start(&cpu_timer);
        test_sum = do_pairwise_sum(energy, ncells);
        cpu_time = cpu_timer_stop(cpu_timer);
        printf("Method: Pairwise sum         Sum: %-17.16lg Diff: %10.4lg Relative Diff: %10.4lg Runtime: %lf\n",
               test_sum, test_sum - accurate_sum, (test_sum - accurate_sum)/accurate_sum, cpu_time);

        // Kahan sum
        cpu_timer_start(&cpu_timer);
        test_sum = do_kahan_sum(energy, ncells);
        cpu_time = cpu_timer_stop(cpu_timer);
        printf("Method: Kahan sum            Sum: %-17.16lg Diff: %10.4lg Relative Diff: %10.4lg Runtime: %lf\n",
               test_sum, test_sum - accurate_sum, (test_sum - accurate_sum)/accurate_sum, cpu_time);

        // Knuth sum
        cpu_timer_start(&cpu_timer);
        test_sum = do_knuth_sum(energy, ncells);
        cpu_time = cpu_timer_stop(cpu_timer);
        printf("Method: Knuth sum            Sum: %-17.16lg Diff: %10.4lg Relative Diff: %10.4lg Runtime: %lf\n",
               test_sum, test_sum - accurate_sum, (test_sum - accurate_sum)/accurate_sum, cpu_time);

        // Long double sum
        cpu_timer_start(&cpu_timer);
        ld_sum = do_long_double_sum(energy, ncells);
        cpu_time = cpu_timer_stop(cpu_timer);
        printf("Method: Long double sum      Sum: %-21.18Lg Diff: %10.4Lg Relative Diff: %10.4Lg Runtime: %lf\n",
               ld_sum, ld_sum - (long double)accurate_sum,
               (ld_sum - (long double)accurate_sum)/(long double)accurate_sum, cpu_time);

        free(energy);
        printf("\n");
    }

    printf("========================================\n");
    printf("All tests complete!\n");
    printf("========================================\n");

    return 0;
}
