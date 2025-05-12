#include <stdio.h>

int multiply(int a, int b) {
    if(b == 0) return 0;
    return a + multiply(a, b - 1);
}

int main() {
    int a = 12, b = 9;
    int result = multiply(a, b);
    printf("Multiplication of %d and %d is: %d\n", a, b, result);
}
