/*
 * ============================================================================
 * SORTING ALGORITHM TEMPLATE
 * Course: Algorithms and Complexity
 * Algorithm: Merge Sort (Own Variation)
 * Time Complexity: 
 *      Best Case: O(n)
 *      Average Case: O(n log n)
 *      Worst Case: O(n log n)
 * Space Complexity: O(n)
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

 typedef struct {
    int *arr;
    int size;
} DynamicList;

void variationMergeSort(int[], int, int);
void merge(int[], int, int, int);
bool isSorted(int[], int);

void sort(int arr[], int size) {
    // Begin Merge Sort Algorithm
    DynamicList D; // Declaration
    D.arr = arr; // Assignment
    D.size = size; // Assignment
    if(!isSorted(arr, size)){
        variationMergeSort(D.arr, 0, D.size - 1);
    }
}

// Handles the Recursion of Merge Sort
void variationMergeSort(int arr[], int start, int end){
    int mid = (start + end) / 2;
    if(end - start > 1){
        variationMergeSort(arr, start, mid); // Handles Recursion on left Half
        variationMergeSort(arr, mid + 1, end); // Handles Recursion on Right Half
    }
    merge(arr, start, mid, end);
}

void merge(int mainArr[], int start, int mid, int end){
    // Count for Array Indices
    int leftCount, rightCount, mainCount;
    int sizeLeft = mid - start + 1; // Size of Left Array
    int sizeRight = end - mid; // Size of Right Array

    // Initialize Temporary Arrays for Dividing
    int left[sizeLeft], right[sizeRight];

    // Insert Left Side of the Array
    for(leftCount = 0; leftCount < sizeLeft; leftCount++){
        left[leftCount] = mainArr[start + leftCount];
    }
    // Insert Right Side of the Array
    for(rightCount = 0; rightCount < sizeRight; rightCount++){
        right[rightCount] = mainArr[mid + 1 + rightCount];
    }

    // Reset Counts to Zero
    leftCount = 0;
    rightCount = 0;
    mainCount = start;
    
    // Inserts the Elements and Sorts them back into the Main Array after Division
    while(leftCount < sizeLeft && rightCount < sizeRight){
        // If left Element is less than Right Element, insert left element and increment left index else vice versa
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

    // Insert Remaining Elements into the Main Array
    while(leftCount < sizeLeft){
        mainArr[mainCount] = left[leftCount];
        leftCount++;
        mainCount++;
    }

    while(rightCount < sizeRight){
        mainArr[mainCount] = right[rightCount];
        rightCount++;
        mainCount++;
    }
}

bool isSorted(int arr[], int size){
    for(int i = 0; i < size; i++){
        if(arr[i] > arr[i + 1]) return false;
    }
    return true;
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
    printf("Time taken: %.6f microseconds\n\n", time_medium);
    
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
    printf("Time taken: %.6f microseconds\n\n", time_large);
    
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