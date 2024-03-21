#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp;
    
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int* arr, int leftIndex, int rightIndex) {
    int pivot, i, j;
    
    pivot = arr[rightIndex];
    i = leftIndex - 1;
    
    for (j = leftIndex; j < rightIndex; ++j) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[rightIndex]);
    return (i + 1);
}

void quickSort(int* arr, int leftIndex, int rightIndex) {
    int pivotIndex;
    
    if (leftIndex < rightIndex) {
        pivotIndex = partition(arr, leftIndex, rightIndex);
        quickSort(arr, leftIndex, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, rightIndex);
    }
}

void printArray(int* arr, int size) {
    int i;
    
    for (i = 0; i < size; ++i) {
        printf("%d\n", arr[i]);
    }
}

void removeDuplicateValues(int* arr, int* size) {
    int i, j, k;
    
    for (i = 0; i < *size; ++i) {
        for (j = i + 1; j < *size ; ++j) {
            if (arr[i] == arr[j]) {
                for (k = j; k < *size; ++k) {
                    arr[k] = arr[k + 1];
                }
                (*size)--;
                j--;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int size = 0, n, i;
    int capacity = 1;
    int* arr = (int*)malloc(sizeof(int) * capacity);
    int* temp;
    
    scanf("%d", &n);
    do {
        if (size >= capacity) {
            temp = malloc(sizeof(int) * capacity * 2);
            if (temp == NULL) {
                exit(1);
            }
            for (i = 0; i < size; ++i) {
                temp[i] = arr[i];
            }
            free(arr);
            arr = temp;
            capacity *= 2;
            size++;
            
        }
        arr[size] = n;
        size++;
        scanf("%d", &n);
    } while (n > - 1);
    
    removeDuplicateValues(arr, &size);
    quickSort(arr, 0, size - 1);
    printArray(arr, size);
    
    free(arr);
    return 0;
}
