#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define f(x) ((x) * log10(x) - 1.2)

int main() {
    float x0, x1, x2, f0, f1, f2, e;
    int step = 1, max_iter;

    // Input
    printf("\nEnter two initial guesses:\n");
    scanf("%f %f", &x0, &x1);
    printf("Enter tolerable error:\n");
    scanf("%f", &e);
    printf("Enter maximum iterations:\n");
    scanf("%d", &max_iter);

    f0 = f(x0);
    f1 = f(x1);

    // Check if guesses are valid
    if (f0 * f1 > 0.0) {
        printf("Incorrect initial guesses (f(x0)*f(x1) > 0). Try again.\n");
        return 1;
    }

    printf("\nStep\t\tx0\t\tx1\t\tx2\t\tf(x2)\n");

    do {
        // Regula Falsi formula
        x2 = x0 - (x0 - x1) * f0 / (f0 - f1);
        f2 = f(x2);

        printf("%d\t\t%f\t%f\t%f\t%f\n", step, x0, x1, x2, f2);

        if (f0 * f2 < 0) {
            x1 = x2;
            f1 = f2;
        } else {
            x0 = x2;
            f0 = f2;
        }

        step++;

        if (step > max_iter) {
            printf("\nNot convergent (reached maximum iterations)\n");
            return 1;
        }

    } while (fabs(f2) > e);

    printf("\nRoot is: %f\n", x2);
    return 0;
}
