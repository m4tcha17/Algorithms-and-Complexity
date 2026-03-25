/*
 * ============================================================================
 * SORTING ALGORITHM TEMPLATE
 * Course: Algorithms and Complexity
 * Algorithm: Counting Sort
 * Time Complexity:
 *      Best Case: O(n + k)
 *      Average Case: O(n + k)
 *      Worst Case: O(n + k)
 * Space Complexity: O(k) where k is the range of the inputs
 * ============================================================================
 */

#include "../../0-Testing/sorting_algorithms.h"

/* ============================================================================
 * ALGORITHM IMPLEMENTATION
 * ============================================================================ */

void countingSort(int arr[], int size) {
    int largest = arr[0];
    for(int i = 1; i < size; i++) if(arr[i] > largest) largest = arr[i];
    int *countArr = calloc(largest + 1, sizeof(int));
    for(int j = 0; j < size; j++) countArr[arr[j]]++;        
    for(int k = 0; k < largest; k++) countArr[k + 1] += countArr[k];
    int newArr[size];
    for(int l = size - 1; l >= 0; l--){
        newArr[--countArr[arr[l]]] = arr[l];
    }
    free(countArr);
    memcpy(arr, newArr, sizeof(newArr));
}

/* ============================================================================
 * HELPER FUNCTIONS (if needed)
 * ============================================================================ */

/**
 * Helper function description
 * @param arr Array parameter
 * @param left Left count
 * @param right Right count
 */
void helper_function(int arr[], int left, int right) {
    // TODO: Implement helper function if needed
}

/* ============================================================================
 * MAIN FUNCTION - TESTING
 * ============================================================================ */

int main() {
    printf("========================================\n");
    printf("Testing [ALGORITHM NAME]\n");
    printf("========================================\n\n");
    
    // Test with small dataset
    printf("--- Small Dataset (Size: %d) ---\n", small_size);
    int test_small[small_size];
    copy_array(small_dataset, test_small, small_size);
    
    printf("Before sorting: ");
    print_array(test_small, small_size);
    
    countingSort(test_small, small_size);
    
    printf("After sorting:  ");
    print_array(test_small, small_size);
    printf("Is sorted: %s\n\n", is_sorted(test_small, small_size) ? "YES" : "NO");
    
    // Test with medium dataset
    printf("--- Medium Dataset (Size: %d) ---\n", medium_size);
    int test_medium[medium_size];
    copy_array(medium_dataset, test_medium, medium_size);
    
    printf("Before sorting (first 10): ");
    print_array(test_medium, 10);
    
    double time_medium = measure_time(test_medium, medium_size, countingSort);
    
    printf("After sorting (first 10):  ");
    print_array(test_medium, 10);
    printf("Is sorted: %s\n", is_sorted(test_medium, medium_size) ? "YES" : "NO");
    printf("Time taken: %.6f microseconds\n\n", time_medium);
    
    // Test with large dataset
    printf("--- Large Dataset (Size: %d) ---\n", large_size);
    int test_large[large_size];
    copy_array(large_dataset, test_large, large_size);
    
    printf("Before sorting (first 10): ");
    print_array(test_large, 10);
    
    double time_large = measure_time(test_large, large_size, countingSort);
    
    printf("After sorting (first 10):  ");
    print_array(test_large, 10);
    printf("Is sorted: %s\n", is_sorted(test_large, large_size) ? "YES" : "NO");
    printf("Time taken: %.6f microseconds\n\n", time_large);
    
    // Test with custom random dataset
    printf("--- Custom Random Dataset (Size: 20) ---\n");
    int test_random[20];
    generate_random_array(test_random, 20, 500);
    
    printf("Before sorting: ");
    print_array(test_random, 20);
    
    countingSort(test_random, 20);
    
    printf("After sorting:  ");
    print_array(test_random, 20);
    printf("Is sorted: %s\n\n", is_sorted(test_random, 20) ? "YES" : "NO");
    
    printf("========================================\n");
    printf("All tests completed!\n");
    printf("========================================\n");
    
    return 0;
}