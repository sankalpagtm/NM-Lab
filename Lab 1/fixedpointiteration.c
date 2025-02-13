#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define f(x) cos(x) - 3*x + 1
#define g(x) (1 + cos(x)) / 3

int main() {
    int step = 1, N;
    float x0, x1, e;
    
    printf("Enter the initial guess: ");
    scanf("%f", &x0);
    printf("Enter tolerable error: ");
    scanf("%f", &e);
    printf("Enter maximum iteration: ");
    scanf("%d", &N);
    
    printf("\nStep\t\tx0\t\tf(x0)\t\tx1\t\tf(x1)\n");
    
    do {
        x1 = g(x0);
        printf("%d\t\t%f\t\t%f\t\t%f\t\t%f\n", step, x0, f(x0), x1, f(x1));
        
        step++;
        
        if (step > N) {
            printf("Not Convergent\n");
            exit(0);
        }
        
        if (fabs(x1 - x0) < e) {
            break;
        }
        
        x0 = x1;
        
    } while (1);
    
    printf("Converged to: %f\n", x1);
    
    return 0;
}
