#include <stdio.h>

#define ROWS 4
#define COLS 4

int isSparse(int matrix[ROWS][COLS]) {
    int count = 0;
    int totalElements = ROWS * COLS;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (matrix[i][j] == 0) {
                count++;
            }
        }
    }

    return count > totalElements / 2;
}

int main() {
    int matrix[ROWS][COLS] = {
        {1, 0, 0, 4},
        {0, 0, 0, 0},
        {9, 0, 0, 0},
        {0, 14, 15, 0}
    };

    if (isSparse(matrix)) {
        printf("The matrix is sparse.\n");
    } else {
        printf("The matrix is not sparse.\n");
    }

    return 0;
}
