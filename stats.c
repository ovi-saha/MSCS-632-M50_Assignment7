#include <stdio.h>
#include <stdlib.h>

// Comparison function used by qsort to sort integers in ascending order
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to calculate the mean (average) of an array
double mean(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) 
        sum += arr[i]; // Accumulate the sum of all elements
    return (double)sum / size; // Return average as a double
}

// Function to calculate the median of an array
double median(int arr[], int size) {
    qsort(arr, size, sizeof(int), compare); // Sort the array
    if (size % 2 == 0)
        // If even number of elements, return average of two middle elements
        return (arr[size/2 - 1] + arr[size/2]) / 2.0;
    else
        // If odd, return the middle element
        return arr[size/2];
}

// Function to find and print the mode(s) of an array
void mode(int arr[], int size) {
    int maxCount = 0; // Tracks the highest frequency
    int count = 1;    // Tracks frequency of current number

    qsort(arr, size, sizeof(int), compare); // Sort the array first

    // First pass: find the maximum frequency
    for (int i = 1; i <= size; i++) {
        if (i < size && arr[i] == arr[i-1]) {
            count++; // Increment count if current and previous are equal
        } else {
            if (count > maxCount) {
                maxCount = count; // Update maxCount if current count is higher
            }
            count = 1; // Reset count for the next number
        }
    }

    count = 1;
    printf("Mode: ");
    // Second pass: print all numbers that appear maxCount times
    for (int i = 1; i <= size; i++) {
        if (i < size && arr[i] == arr[i-1]) {
            count++;
        } else {
            if (count == maxCount) {
                printf("%d ", arr[i-1]); // Print mode(s)
            }
            count = 1;
        }
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 3, 3, 6, 7, 8, 9}; // Sample data
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate array size

    // Display the calculated statistics
    printf("Mean: %.2f\n", mean(arr, size));
    printf("Median: %.2f\n", median(arr, size));
    mode(arr, size);

    return 0;
}
