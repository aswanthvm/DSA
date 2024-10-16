#include <stdio.h>

struct Poly {
    int coeff, expo;
};

int main() {
    int a, b, max;
    struct Poly p1[20] = {0}, p2[20] = {0}, p3[20] = {0};

    // Input for the first polynomial
    printf("Enter Degree of first polynomial: ");
    scanf("%d", &a);

    printf("\nPolynomial 1:\n");
    for (int i = a; i >= 0; i--) {
        printf("Enter coefficient of x^%d: ", i);
        scanf("%d", &p1[i].coeff);
        p1[i].expo = i;
    }

    // Input for the second polynomial
    printf("\nEnter Degree of second polynomial: ");
    scanf("%d", &b);

    printf("\nPolynomial 2:\n");
    for (int i = b; i >= 0; i--) {
        printf("Enter coefficient of x^%d: ", i);
        scanf("%d", &p2[i].coeff);
        p2[i].expo = i;
    }

    // Determine the maximum degree
    max = (a > b) ? a : b;

    // Polynomial addition
    printf("\nThe sum is: ");
    for (int i = max; i >= 0; i--) {
        if (p1[i].expo == p2[i].expo) {
            p3[i].coeff = p1[i].coeff + p2[i].coeff;
            if (p3[i].coeff != 0) {
                printf("%dX^%d ", p3[i].coeff, p3[i].expo);
            }
        } else if (p1[i].expo > p2[i].expo) {
            p3[i] = p1[i];
            if (p3[i].coeff != 0) {
                printf("%dX^%d ", p3[i].coeff, p3[i].expo);
            }
        } else {
            p3[i] = p2[i];
            if (p3[i].coeff != 0) {
                printf("%dX^%d ", p3[i].coeff, p3[i].expo);
            }
        }
    }

    return 0;
}
