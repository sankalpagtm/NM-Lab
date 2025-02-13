#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define f(x) (3*x - cos(x) - 1)
#define g(x) (3 + sin(x))

int main() {
    float x0, x1, f0, f1, g0, e;
    int step = 1, N;

    printf("\nEnter initial value: ");
    scanf("%f", &x0);
    printf("\nEnter tolerable error: ");
    scanf("%f", &e);
    printf("Enter maximum iterations: ");
    scanf("%d", &N);

    printf("\nStep\t\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");

    do {
        g0 = g(x0);
        f0 = f(x0);

        if (g0 == 0.0) {
            printf("Mathematical error (division by zero)\n");
            exit(0);
        }

        x1 = x0 - f0 / g0;
        f1 = f(x1);

        printf("%d\t\t%f\t\t%f\t\t%f\t\t%f\n", step, x0, f0, x1, f1);

        x0 = x1;
        step++;

        if (step > N) {
            printf("\nNot Convergent (Maximum iterations reached)\n");
            exit(0);
        }

    } while (fabs(f1) > e);

    printf("\nRoot is: %f\n", x1);
    return 0;
}
