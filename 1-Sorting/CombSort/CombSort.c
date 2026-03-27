/*
 * ============================================================================
 * SORTING ALGORITHM TEMPLATE
 * Course: Algorithms and Complexity
 * Algorithm: Comb Sort
 * Time Complexity:
 *      Best Case: O(n log n)
 *      Average Case: Ω(N²/2^p)
 *      Worst Case: O(n²)
 * Space Complexity: O(1)
 * ============================================================================
 */

#include "../../0-Testing/sorting_algorithms.h"

/* ============================================================================
 * ALGORITHM IMPLEMENTATION
 * ============================================================================ */

void combSort(int arr[], int size) {
    bool swapped;
    for(int gap = floor(size / 1.3); gap >= 1; gap = floor(gap / 1.3) < 1 ? 1 : floor(gap / 1.3)){
        swapped = false;
        for(int i = 0; i < size - gap; i++){
            if(arr[i] > arr[i + gap]){
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                if(gap == 1) swapped = true;
            }
        }
        if(gap == 1 && swapped == false) break;
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
    
    combSort(test_small, small_size);
    
    printf("After sorting:  ");
    print_array(test_small, small_size);
    printf("Is sorted: %s\n\n", is_sorted(test_small, small_size) ? "YES" : "NO");
    
    // Test with medium dataset
    printf("--- Medium Dataset (Size: %d) ---\n", medium_size);
    int test_medium[medium_size];
    copy_array(medium_dataset, test_medium, medium_size);
    
    printf("Before sorting (first 10): ");
    print_array(test_medium, 10);
    
    double time_medium = measure_time(test_medium, medium_size, combSort);
    
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
    
    double time_large = measure_time(test_large, large_size, combSort);
    
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
    
    combSort(test_random, 20);
    
    printf("After sorting:  ");
    print_array(test_random, 20);
    printf("Is sorted: %s\n\n", is_sorted(test_random, 20) ? "YES" : "NO");
    
    printf("========================================\n");
    printf("All tests completed!\n");
    printf("========================================\n");
    
    return 0;
}