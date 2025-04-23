#include <stdio.h>

void mergeAndCount(int arr[], int temp[], int left, int right, int *invCount);
void merge(int arr[], int temp[], int left, int mid, int right, int *invCount);
int countInversions(int arr[], int n);

int main() {
    int n;

    // Take input for the size of the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Take input for the array elements
    printf("Enter %d distinct integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate and display the number of inversions
    printf("Number of inversions: %d\n", countInversions(arr, n));
    return 0;
}

// Function to count inversions using merge sort
int countInversions(int arr[], int n) {
    int temp[n];
    int invCount = 0;
    mergeAndCount(arr, temp, 0, n - 1, &invCount);
    return invCount;
}

// Helper function that performs merge sort and counts inversions
void mergeAndCount(int arr[], int temp[], int left, int right, int *invCount) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Count inversions in the left half, right half and during merge
        mergeAndCount(arr, temp, left, mid, invCount);
        mergeAndCount(arr, temp, mid + 1, right, invCount);

        // Merge the two halves and count inversions
        merge(arr, temp, left, mid, right, invCount);
    }
}

// Function to merge two halves of the array and count the inversions
void merge(int arr[], int temp[], int left, int mid, int right, int *invCount) {
    int i = left;    // Starting index for left subarray
    int j = mid + 1; // Starting index for right subarray
    int k = left;    // Starting index to be sorted

    // Merge the two subarrays while counting inversions
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            *invCount += (mid - i + 1); // All remaining elements in left subarray are greater than arr[j]
        }
    }

    // Copy the remaining elements of the left subarray
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy the remaining elements of the right subarray
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy the sorted subarray into the original array
    for (int i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}
