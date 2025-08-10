#include <stdio.h>

int main() {
    int n, i, j, isIdentity = 1;
    
    scanf("%d", &n);
    
    int matrix[n][n];
    
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(i == j) {
                if(matrix[i][j] != 1) {
                    isIdentity = 0;
                    break;
                }
            }
            else {
                if(matrix[i][j] != 0) {
                    isIdentity = 0;
                    break;
                }
            }
        }
        if(!isIdentity) break;
    }
    
    if(isIdentity) {
        printf("Identity Matrix");
    } else {
        printf("Not an Identity Matrix");
    }
    
    return 0;
}
