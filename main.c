//
// Created by Neville Walo on 13.10.2018.
//

#include <math.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

static void swap(int array[], int i, int j) {
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

int teile(int array[], int *links, int *rechts) {
    int i = links;
    int j = rechts - 1;
    int pivot = array[rechts];

    while (i < j) {
        while ((array[i] < pivot) && (i < (rechts - 1))) {
            i++;
        }
        while ((array[j] > pivot) && (j > links)) {
            j--;
        }
        if (i < j) {
            swap(array, i, j);
            // int temp = array[i];
            // array[i] = array[j];
            // array[j] = temp;

        }

    }
    if (array[i] > pivot) {
        swap(array, i, rechts);
        // int temp = array[i];
        // array[i] = array[rechts];
        // array[rechts] = temp;
    }

    return i;

}

int cmpfunc(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

void quicksort(int *array, int *links, int *rechts) {
    if (*links < *rechts) {
        int *pivot = teile(array, links, rechts);
        quicksort(array, links, pivot);
        quicksort(array, links, pivot);

    }
}


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
//            qsort(array, size, sizeof(int), cmpfunc);
            quicksort(array, 0, size - 1);
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