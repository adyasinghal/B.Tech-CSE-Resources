#include <stdio.h>
#include <stdlib.h>
#include "Complex.h"

// Function to input a complex number from the user
complex InputComplex() {
    complex temp;
    printf("Enter the real part: ");
    scanf("%f", &temp.real);
    printf("Enter the imaginary part: ");
    scanf("%f", &temp.imaginary);
    return temp;
}

// Function to add two complex numbers
complex *Add(complex x, complex y) {
    complex *result = (complex *)malloc(sizeof(complex));
    result->real = x.real + y.real;
    result->imaginary = x.imaginary + y.imaginary;
    return result;
}

// Function to subtract two complex numbers
complex *Subtract(complex x, complex y) {
    complex *result = (complex *)malloc(sizeof(complex));
    result->real = x.real - y.real;
    result->imaginary = x.imaginary - y.imaginary;
    return result;
}

// Function to multiply two complex numbers
complex *Multiply(complex x, complex y) {
    complex *result = (complex *)malloc(sizeof(complex));
    result->real = (x.real * y.real) - (x.imaginary * y.imaginary);
    result->imaginary = (x.real * y.imaginary) + (x.imaginary * y.real);
    return result;
}

// Function to divide two complex numbers
complex *Divide(complex x, complex y) {
    float denominator = (y.real * y.real) + (y.imaginary * y.imaginary);

    if (denominator == 0) {
        printf("Error: Division by zero is not allowed.\n");
        exit(1);
    }

    complex *result = (complex *)malloc(sizeof(complex));
    
    result->real = ((x.real * y.real) + (x.imaginary * y.imaginary)) / denominator;
    
    result->imaginary = ((x.imaginary * y.real) - (x.real * y.imaginary)) / denominator;

    return result;
}
