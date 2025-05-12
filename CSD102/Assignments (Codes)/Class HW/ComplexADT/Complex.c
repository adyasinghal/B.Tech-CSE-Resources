#include <stdio.h>
#include <stdlib.h>
#include "Complex.h"

// read a complex number 
complex ReadComplex() {
    complex c;
    printf("Enter real part: ");
    scanf("%f", &c.re);
    printf("Enter imaginary part: ");
    scanf("%f", &c.im);
    return c;
}

// add two complex numbers
complex *AddComplex(complex a, complex b) {
    complex *result = (complex *)malloc(sizeof(complex));
    result->re = a.re + b.re;
    result->im = a.im + b.im;
    return result;
}

// subtract two complex numbers
complex *SubComplex(complex a, complex b) {
    complex *result = (complex *)malloc(sizeof(complex));
    result->re = a.re - b.re;
    result->im = a.im - b.im;
    return result;
}

// multiply two complex numbers
complex *MulComplex(complex a, complex b) {
    complex *result = (complex *)malloc(sizeof(complex));
    result->re = (a.re * b.re) - (a.im * b.im);
    result->im = (a.re * b.im) + (a.im * b.re);
    return result;
}

// divide two complex numbers
complex *DivComplex(complex a, complex b) {
    complex *result = (complex *)malloc(sizeof(complex));
    
    float denominator = (b.re * b.re) + (b.im * b.im);
    
    if (denominator == 0) {
        printf("Error: Division by zero!\n");
        exit(1);
    }

    result->re = ((a.re * b.re) + (a.im * b.im)) / denominator;
    result->im = ((a.im * b.re) - (a.re * b.im)) / denominator;

    return result;
}
