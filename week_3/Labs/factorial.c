#include <stdio.h>

int get_factorial(int n);

int main(void) {

    int n;
    
    printf("Enter a number: ");
    scanf("%d", &n);

    int factorial = get_factorial(n);

    printf("%d", factorial);
}

int get_factorial(int n) {
    
    if (n == 1) {
        return 1;
    }

    return n * get_factorial(n-1);
}