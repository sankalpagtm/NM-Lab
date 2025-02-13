#include <stdio.h>
#include <math.h>

double f(double x) {
    return cos(x) - x * exp(x);
}

int main() {
    double x0, x1, x2, f0, f1, f2, e;
    int step = 1;

    // Input Section
    printf("\nEnter two initial guesses:\n");
    scanf("%lf %lf", &x0, &x1);
    printf("Enter tolerable error:\n");
    scanf("%lf", &e);

    f0 = f(x0);
    f1 = f(x1);

    // Validate initial guesses
    while (f0 * f1 > 0.0) {
        printf("Incorrect initial guesses. Enter again:\n");
        scanf("%lf %lf", &x0, &x1);
        f0 = f(x0);
        f1 = f(x1);
    }

    printf("\nStep \t\tx0 \t\tx1 \t\tx2 \t\tf(x2)\n");
    
    // Bisection Method
    do {
        x2 = (x0 + x1) / 2;
        f2 = f(x2);
        printf("%d\t\t%lf\t%lf\t%lf\t%lf\n", step, x0, x1, x2, f2);

        if (f0 * f2 < 0) {
            x1 = x2;
            f1 = f2;
        } else {
            x0 = x2;
            f0 = f2;
        }

        step = step + 1;

    } while (fabs(f2) > e);

    // Output Result
    printf("\nRoot is: %lf\n", x2);

    return 0;
}
