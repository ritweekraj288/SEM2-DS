//Write a C or C++ program to sort the input array [12, 45, 33, 87, 56, 9, 11, 7,67] using the Bucket Sort algorithm with 7 buckets.

#include <stdio.h>
#include <stdlib.h>

#define SIZE 9
#define BUCKET_COUNT 7


typedef struct {
    int *values;
    int count;
    int capacity;
} Bucket;


void initBucket(Bucket *bucket) {
    bucket->count = 0;
    bucket->capacity = 5;
    bucket->values = (int *)malloc(sizeof(int) * bucket->capacity);
}


void insertBucket(Bucket *bucket, int value) {
    if (bucket->count == bucket->capacity) {
        bucket->capacity *= 2;
        bucket->values = (int *)realloc(bucket->values, sizeof(int) * bucket->capacity);
    }
    bucket->values[bucket->count++] = value;
}


int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}


void bucketSort(int arr[], int size) {
    Bucket buckets[BUCKET_COUNT];

    
    for (int i = 0; i < BUCKET_COUNT; i++) {
        initBucket(&buckets[i]);
    }

    
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    
    for (int i = 0; i < size; i++) {
        int index = (arr[i] * BUCKET_COUNT) / (max + 1);
        insertBucket(&buckets[index], arr[i]);
    }

    
    int idx = 0;
    for (int i = 0; i < BUCKET_COUNT; i++) {
        qsort(buckets[i].values, buckets[i].count, sizeof(int), compare);
        for (int j = 0; j < buckets[i].count; j++) {
            arr[idx++] = buckets[i].values[j];
        }
        free(buckets[i].values);
    }
}


int main() {
    int arr[SIZE] = {12, 45, 33, 87, 56, 9, 11, 7, 67};

    printf("Original array:\n");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", arr[i]);
    printf("\n");

    bucketSort(arr, SIZE);

    printf("Sorted array:\n");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
