#include <stdio.h>
#include "Complex.h"

// Function to display a complex number
void DisplayComplex(complex num) {
    printf("%.2f + %.2fi\n", num.real, num.imaginary);
}

// Main function to test operations on complex numbers
int main() {
    complex num1, num2, result;

    printf("Input the first complex number:\n");
    num1 = InputComplex();

    printf("Input the second complex number:\n");
    num2 = InputComplex();

    // Perform addition
    result = *Add(num1, num2);
    printf("\nSum: ");
    DisplayComplex(result);

    // Perform subtraction
    result = *Subtract(num1, num2);
    printf("\nDifference: ");
    DisplayComplex(result);

    // Perform multiplication
    result = *Multiply(num1, num2);
    printf("\nProduct: ");
    DisplayComplex(result);

    // Perform division
    result = *Divide(num1, num2);
    printf("\nQuotient: ");
    DisplayComplex(result);

    return 0;
}
