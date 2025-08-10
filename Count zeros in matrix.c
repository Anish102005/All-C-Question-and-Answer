#include <stdio.h>

int main() {
    int rows, cols, i, j, zeroCount = 0;
    
    scanf("%d %d", &rows, &cols);
    
    int matrix[rows][cols];
    
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
            if(matrix[i][j] == 0) {
                zeroCount++;
            }
        }
    }
    
    printf("%d", zeroCount);
    
    return 0;
}
