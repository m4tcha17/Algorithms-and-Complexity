#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/* ============================================================================
 * UNSORTED DATA ARRAYS FOR TESTING
 * ============================================================================ */

// Small dataset for debugging and initial testing
int small_dataset[] = {64, 34, 25, 12, 22, 11, 90, 88, 45, 50};
int small_size = 10;

// Medium dataset
int medium_dataset[] = {
    156, 47, 89, 23, 178, 92, 34, 67, 145, 8,
    198, 56, 123, 78, 45, 189, 12, 167, 90, 234,
    76, 134, 23, 98, 56, 187, 45, 123, 67, 201,
    89, 145, 34, 178, 92, 56, 167, 23, 134, 78,
    212, 45, 189, 67, 123, 98, 156, 34, 201, 87
};
int medium_size = 50;

// Large dataset
int large_dataset[] = {
    847, 219, 563, 901, 742, 386, 129, 654, 478, 235,
    891, 567, 312, 749, 423, 685, 197, 834, 526, 378,
    652, 914, 287, 539, 761, 408, 673, 195, 842, 316,
    729, 564, 401, 258, 937, 612, 485, 723, 349, 816,
    572, 294, 638, 451, 789, 326, 905, 547, 213, 869,
    734, 492, 165, 821, 376, 659, 128, 943, 587, 214,
    736, 459, 802, 351, 687, 425, 793, 518, 264, 839,
    476, 652, 391, 725, 148, 863, 537, 219, 694, 382,
    756, 429, 615, 873, 341, 708, 526, 194, 867, 453,
    782, 369, 641, 917, 284, 735, 498, 562, 901, 378
};
int large_size = 100;

/* ============================================================================
 * UTILITY FUNCTIONS
 * ============================================================================ */

/**
 * Print an array
 * @param arr Array to print
 * @param size Size of the array
 */
void print_array(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

/**
 * Copy an array
 * @param source Source array
 * @param dest Destination array
 * @param size Size of the arrays
 */
void copy_array(int source[], int dest[], int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = source[i];
    }
}

/**
 * Check if an array is sorted in ascending order
 * @param arr Array to check
 * @param size Size of the array
 * @return true if sorted, false otherwise
 */
bool is_sorted(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

/**
 * Swap two integers
 * @param a Pointer to first integer
 * @param b Pointer to second integer
 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Generate a random array
 * @param arr Array to fill with random numbers
 * @param size Size of the array
 * @param max_value Maximum value for random numbers
 */
void generate_random_array(int arr[], int size, int max_value) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % max_value;
    }
}

/**
 * Measure execution time of a sorting algorithm
 * @param arr Array to sort
 * @param size Size of the array
 * @param sort_func Pointer to sorting function
 * @return Execution time in seconds
 */
double measure_time(int arr[], int size, void (*sort_func)(int[], int)) {
    clock_t start, end;
    start = clock();
    sort_func(arr, size);
    end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

#endif /* SORTING_ALGORITHMS_H */
