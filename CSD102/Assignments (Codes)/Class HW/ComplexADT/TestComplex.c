#include <stdio.h>
#include "Complex.h"

// Helper function 
void PrintComplex(complex a) {
    printf("%.2f + %.2fi\n", a.re, a.im);
}

// Driver function to test the implementation of complex numbers
int main() {
    complex a, b, result;

    printf("Enter the first complex number:\n");
    a = ReadComplex();

    printf("Enter the second complex number:\n");
    b = ReadComplex();

    // Addition
    result = *AddComplex(a, b);
    printf("\nAddition: ");
    PrintComplex(result);

    // Subtraction
    result = *SubComplex(a, b);
    printf("\nSubtraction: ");
    PrintComplex(result);

    // Multiplication
    result = *MulComplex(a, b);
    printf("\nMultiplication: ");
    PrintComplex(result);

    // Division
    result = *DivComplex(a, b);
    printf("\nDivision: ");
    PrintComplex(result);

    return 0;
}
