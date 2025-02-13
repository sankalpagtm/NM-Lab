#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define f(x) ((x) * log10(x) - 1.2)

int main() {
    float x0, x1, x2, f0, f1, f2, e;
    int step = 1, max_iter;

    printf("\nEnter two initial guesses:\n");
    scanf("%f %f", &x0, &x1);
    printf("Enter tolerable error:\n");
    scanf("%f", &e);
    printf("Enter maximum iterations:\n");
    scanf("%d", &max_iter);

    printf("\nStep\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");

    do {
        f0 = f(x0);
        f1 = f(x1);

        if (f1 - f0 == 0.0) {
            printf("Mathematical error (division by zero)\n");
            exit(0);
        }

        x2 = x1 - (x1 - x0) * f1 / (f1 - f0);
        f2 = f(x2);

        printf("%d\t\t%f\t%f\t%f\t%f\n", step, x0, x1, x2, f2);

        x0 = x1;
        x1 = x2;
        step++;

        if (step > max_iter) {
            printf("\nNot convergent (reached maximum iterations)\n");
            exit(0);
        }

    } while (fabs(f2) > e);

    printf("\nRoot is: %f\n", x2);
    return 0;
}
