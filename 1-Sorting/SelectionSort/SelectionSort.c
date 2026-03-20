/*
 * ============================================================================
 * SORTING ALGORITHM TEMPLATE
 * Course: Algorithms and Complexity
 * Algorithm: Selection Sort
 * Time Complexity:
 *      Best Case: O(n²)
 *      Average Case: O(n²)
 *      Worst Case: O(n²)
 * Space Complexity: O(1)
 * ============================================================================
 */

#include "../../0-Testing/sorting_algorithms.h"

/* ============================================================================
 * ALGORITHM IMPLEMENTATION
 * ============================================================================ */

void selectionSort(int arr[], int size) {
    for(int i = 0; i < size - 1; i++){
        int minIdx = i;

        for(int j = i + 1; j < size; j++){
            int smallest = arr[j];
            if(arr[j] < arr[minIdx]) minIdx = j;
        }

        int temp = arr[minIdx];
        arr[minIdx] = arr[i];
        arr[i] = temp;
    }
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
    
    selectionSort(test_small, small_size);
    
    printf("After sorting:  ");
    print_array(test_small, small_size);
    printf("Is sorted: %s\n\n", is_sorted(test_small, small_size) ? "YES" : "NO");
    
    // Test with medium dataset
    printf("--- Medium Dataset (Size: %d) ---\n", medium_size);
    int test_medium[medium_size];
    copy_array(medium_dataset, test_medium, medium_size);
    
    printf("Before sorting (first 10): ");
    print_array(test_medium, 10);
    
    double time_medium = measure_time(test_medium, medium_size, selectionSort);
    
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
    
    double time_large = measure_time(test_large, large_size, selectionSort);
    
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
    
    selectionSort(test_random, 20);
    
    printf("After sorting:  ");
    print_array(test_random, 20);
    printf("Is sorted: %s\n\n", is_sorted(test_random, 20) ? "YES" : "NO");
    
    printf("========================================\n");
    printf("All tests completed!\n");
    printf("========================================\n");
    
    return 0;
}