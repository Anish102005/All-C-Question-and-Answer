#include <stdio.h>
#include <stdlib.h>

void insert(int **arr, int *size, int value) {
    *arr = realloc(*arr, (*size + 1) * sizeof(int));
    (*arr)[*size] = value;
    (*size)++;
}

void delete(int **arr, int *size, int index) {
    if (index < 0 || index >= *size) {
        printf("Index out of bounds.\n");
        return;
    }
    for (int i = index; i < *size - 1; i++) {
        (*arr)[i] = (*arr)[i + 1];
    }
    *arr = realloc(*arr, (*size - 1) * sizeof(int));
    (*size)--;
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int *arr = NULL;
    int size = 0;

    insert(&arr, &size, 10);
    insert(&arr, &size, 20);
    insert(&arr, &size, 30);

    printf("Array after insertions: ");
    printArray(arr, size);

    delete(&arr, &size, 1);

    printf("Array after deletion: ");
    printArray(arr, size);

    free(arr);
    return 0;
}
