#include <stdio.h>

#define N 4

int main() {
    int matrix[N][N] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int primaryDiagonalSum = 0;
    int secondaryDiagonalSum = 0;

    for (int i = 0; i < N; i++) {
        primaryDiagonalSum += matrix[i][i];
        secondaryDiagonalSum += matrix[i][N - i - 1];
    }

    printf("Sum of primary diagonal: %d\n", primaryDiagonalSum);
    printf("Sum of secondary diagonal: %d\n", secondaryDiagonalSum);

    return 0;
}
