#include <stdio.h>

#define MAX_TERMS 100

struct Term {
    int coeff;
    int exp;
};

void multiplyPolynomials(struct Term poly1[], int n1, struct Term poly2[], int n2, struct Term result[], int *nResult) {
    int k = 0;

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            result[k].coeff = poly1[i].coeff * poly2[j].coeff;
            result[k].exp = poly1[i].exp + poly2[j].exp;
            k++;
        }
    }

    // Combine like terms
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            if (result[i].exp == result[j].exp) {
                result[i].coeff += result[j].coeff;
                result[j].coeff = 0; // Mark as combined
            }
        }
    }

    // Filter out zero coefficients
    *nResult = 0;
    for (int i = 0; i < k; i++) {
        if (result[i].coeff != 0) {
            result[*nResult] = result[i];
            (*nResult)++;
        }
    }
}

void printPolynomial(struct Term poly[], int n) {
    for (int i = 0; i < n; i++) {
        if (i > 0 && poly[i].coeff > 0) {
            printf("+");
        }
        printf("%dx^%d ", poly[i].coeff, poly[i].exp);
    }
    printf("\n");
}

int main() {
    struct Term poly1[MAX_TERMS] = {{3, 2}, {5, 1}, {6, 0}};
    struct Term poly2[MAX_TERMS] = {{4, 1}, {2, 0}};
    struct Term result[MAX_TERMS];
    int nResult;

    multiplyPolynomials(poly1, 3, poly2, 2, result, &nResult);

    printf("Resultant Polynomial: ");
    printPolynomial(result, nResult);

    return 0;
}
