typedef struct cplx {
    float re; // Real part
    float im; // Imaginary part
} complex;

complex *AddComplex(complex a, complex b);
complex *SubComplex(complex a, complex b);
complex *MulComplex(complex a, complex b);
complex *DivComplex(complex a, complex b);
complex ReadComplex();


