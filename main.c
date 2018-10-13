//
// Created by Neville Walo on 13.10.2018.
//

#include <math.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

int comparefct(int *a, int *b) {
    return *a < *b;
};

int main() {
    int Max2Pow = 10;
    int Repetitions = 1;
    for (int i = 0; i < Max2Pow; ++i) {
        int size = pow(2, i);
        double TimeSum = 0;

        for (int j = 0; j < Repetitions; ++j) {
            int *array = malloc(size * sizeof(int));

            for (int k = 0; k < size; ++k) {
                array[k] = rand();
            }
            clock_t start = clock();
            qsort(array, size, sizeof(int), comparefct);
            clock_t end = clock() - start;
            double timetaken = (double) end / CLOCKS_PER_SEC;
            TimeSum+=timetaken;


        }
        double averagetime = TimeSum/Repetitions;
        printf("%e\n",averagetime);
    }
}