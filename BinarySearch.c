#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int size, int target) {
    int low = 0;             // Starting index of the array
    int high = size - 1;      // Ending index of the array

    while (low <= high) {
        int mid = (low + high) / 2;  // Find the middle index

        // Check if the target is at the middle index
        if (arr[mid] == target) {
            return mid;  // Target found, return its index
        }
        // If the target is greater than the mid element, ignore the left half
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        // If the target is smaller than the mid element, ignore the right half
        else {
            high = mid - 1;
        }
    }

    return -1;  // Target not found in the array
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};  // Sorted array
    int size = sizeof(arr) / sizeof(arr[0]);  // Calculate size of the array
    int target;

    printf("Enter the element to search: ");
    scanf("%d", &target);  // Take the target element as input

    // Perform binary search
    int result = binarySearch(arr, size, target);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    return 0;
}
