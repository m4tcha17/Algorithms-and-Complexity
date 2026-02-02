/*
 * ============================================================================
 * SORTING ALGORITHM TEMPLATE
 * Course: Algorithms and Complexity
 * Algorithm: [ALGORITHM NAME HERE]
 * Time Complexity: [BEST/AVERAGE/WORST CASE]
 * Space Complexity: [COMPLEXITY]
 * ============================================================================
 */

#include "../../0-Testing/sorting_algorithms.h"

/* ============================================================================
 * ALGORITHM IMPLEMENTATION
 * ============================================================================ */

/**
 * [Algorithm Name] - [Brief Description]
 * 
 * @param arr Array to be sorted
 * @param size Size of the array
 * 
 * Algorithm Steps:
 * 1. [Step 1]
 * 2. [Step 2]
 * 3. [Step 3]
 * ...
 */
void mergeSort(int[], int, int);
void merge(int[], int, int, int);

void sort(int arr[], int size) {
    // Begin Merge Sort Algorithm
    mergeSort(arr, 0, size - 1);
}

// Handles the Recursion of Merge Sort
void mergeSort(int arr[], int start, int end){
    if(start < end){
        int mid = (start + end) / 2;
        // Handles Recursion on left Half
        mergeSort(arr, start, mid);
        // Handles Recursion on Right Half
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void merge(int mainArr[], int start, int mid, int end){
    // Count for Array Indices
    int leftCount, rightCount, mainCount;
    // Size of Left Array
    int sizeLeft = mid - start + 1;
    // Size of Right Array
    int sizeRight = end - mid;

    int left[sizeLeft], right[sizeRight];

    for(leftCount = 0; leftCount < sizeLeft; leftCount++){
        left[leftCount] = mainArr[start + leftCount];
    }
    for(rightCount = 0; rightCount < sizeRight; rightCount++){
        right[rightCount] = mainArr[mid + 1 + rightCount];
    }

    leftCount = 0;
    rightCount = 0;
    mainCount = start;

    while(leftCount < sizeLeft && rightCount < sizeRight){
        if(left[leftCount] <= right[rightCount]){
            mainArr[mainCount] = left[leftCount];
            leftCount++;
        }
        else{
            mainArr[mainCount] = right[rightCount];
            rightCount++;
        }
        mainCount++;
    }

    while(leftCount < sizeLeft){
        mainArr[mainCount] = left[leftCount];
        leftCount++;
        mainCount++;
    }

    while(leftCount < sizeLeft){
        mainArr[mainCount] = right[rightCount];
        rightCount++;
        mainCount++;
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
    
    sort(test_small, small_size);
    
    printf("After sorting:  ");
    print_array(test_small, small_size);
    printf("Is sorted: %s\n\n", is_sorted(test_small, small_size) ? "YES" : "NO");
    
    // Test with medium dataset
    printf("--- Medium Dataset (Size: %d) ---\n", medium_size);
    int test_medium[medium_size];
    copy_array(medium_dataset, test_medium, medium_size);
    
    printf("Before sorting (first 10): ");
    print_array(test_medium, 10);
    
    double time_medium = measure_time(test_medium, medium_size, sort);
    
    printf("After sorting (first 10):  ");
    print_array(test_medium, 10);
    printf("Is sorted: %s\n", is_sorted(test_medium, medium_size) ? "YES" : "NO");
    printf("Time taken: %.6f seconds\n\n", time_medium);
    
    // Test with large dataset
    printf("--- Large Dataset (Size: %d) ---\n", large_size);
    int test_large[large_size];
    copy_array(large_dataset, test_large, large_size);
    
    printf("Before sorting (first 10): ");
    print_array(test_large, 10);
    
    double time_large = measure_time(test_large, large_size, sort);
    
    printf("After sorting (first 10):  ");
    print_array(test_large, 10);
    printf("Is sorted: %s\n", is_sorted(test_large, large_size) ? "YES" : "NO");
    printf("Time taken: %.6f seconds\n\n", time_large);
    
    // Test with custom random dataset
    printf("--- Custom Random Dataset (Size: 20) ---\n");
    int test_random[20];
    generate_random_array(test_random, 20, 500);
    
    printf("Before sorting: ");
    print_array(test_random, 20);
    
    sort(test_random, 20);
    
    printf("After sorting:  ");
    print_array(test_random, 20);
    printf("Is sorted: %s\n\n", is_sorted(test_random, 20) ? "YES" : "NO");
    
    printf("========================================\n");
    printf("All tests completed!\n");
    printf("========================================\n");
    
    return 0;
}
