#include <stdio.h>

#define MAX_TERMS 100

struct Term {
    int coeff;
    int exp;
};

void addPolynomials(struct Term poly1[], int n1, struct Term poly2[], int n2, struct Term result[], int *nResult) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (poly1[i].exp > poly2[j].exp) {
            result[k++] = poly1[i++];
        } else if (poly1[i].exp < poly2[j].exp) {
            result[k++] = poly2[j++];
        } else {
            result[k].exp = poly1[i].exp;
            result[k++].coeff = poly1[i++].coeff + poly2[j++].coeff;
        }
    }

    while (i < n1) {
        result[k++] = poly1[i++];
    }

    while (j < n2) {
        result[k++] = poly2[j++];
    }

    *nResult = k;
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

    addPolynomials(poly1, 3, poly2, 2, result, &nResult);

    printf("Resultant Polynomial: ");
    printPolynomial(result, nResult);

    return 0;
}
