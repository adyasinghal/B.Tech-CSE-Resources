typedef struct ComplexNumber {
    float real;       
    float imaginary;  
} complex;

complex *Add(complex x, complex y);
complex *Subtract(complex x, complex y);
complex *Multiply(complex x, complex y);
complex *Divide(complex x, complex y);
complex InputComplex();
void PrintComplex(complex x);


