#include<stdio.h>

void swap1(int *num1, int *num2) {
    *num1 = *num2;  
}

void swap2(int *num1, int *num2) {
    *num2 = *num1;  
}

int main() {
    int a, b;
    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    printf("Before swapping: first num = %d, second num = %d\n", a, b);

    swap1(&a, &b);
    swap2(&a, &b);
    printf("After swapping: first num = %d, second num = %d\n", a, b);
}
