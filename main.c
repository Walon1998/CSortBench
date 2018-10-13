//
// Created by Neville Walo on 13.10.2018.
//

#include <math.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

int cmpfunc(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

int main() {
    int Max2Pow = 30;
    int Repetitions = 100;
    for (int i = 0; i < Max2Pow; ++i) {
        int size = pow(2, i);
        double TimeSum = 0;

        for (int j = 0; j < Repetitions; ++j) {
            int *array = malloc(size * sizeof(int));

            for (int k = 0; k < size; ++k) {
                array[k] = rand();
            }
            clock_t start = clock();
            qsort(array, size, sizeof(int), cmpfunc);
            clock_t end = clock() - start;
            double TimeTaken = (double) end;
            TimeSum += TimeTaken;
            free(array);
        }
        double AverageTime = TimeSum / (Repetitions * CLOCKS_PER_SEC);
//        printf("2^%d: %g\n",i, AverageTime);
        printf("%g \n", AverageTime);
    }
}