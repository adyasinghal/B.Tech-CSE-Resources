#include <stdio.h> //including header file

float C;
float K;
float F;

int main()
         {
            printf("Temperature in Celsius: ");
            scanf("%f" , &C);
            K = (C + 273.15);
            F = ((C*1.8) + 32);
            printf("Temperature in Fahrenheit: %f\n", F);
            printf("Temperature in Kelvin: %f\n", K);
         }
         
