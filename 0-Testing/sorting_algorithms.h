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
    423, 156, 789, 234, 567, 890, 123, 456, 678, 901,
    234, 567, 345, 678, 789, 456, 123, 890, 234, 567,
    678, 345, 890, 123, 456, 789, 234, 567, 901, 345,
    678, 123, 890, 456, 234, 789, 567, 345, 901, 123,
    456, 678, 234, 890, 567, 345, 789, 123, 901, 456,
    678, 234, 567, 890, 345, 123, 789, 456, 901, 234,
    567, 678, 123, 890, 456, 345, 789, 234, 901, 567,
    123, 678, 456, 890, 234, 345, 789, 567, 901, 123,
    456, 234, 678, 890, 567, 345, 123, 789, 456, 901,
    234, 567, 678, 890, 123, 456, 345, 789, 234, 901
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
