#include <stdio.h> //including header file

float height;
int weight;
float BMI;
int main()
         {
         printf("Enter height in metres: ");
         scanf("%f" , &height);
         printf("Enter weight in kg: ");
         scanf("%d" , &weight);
         BMI = (weight)/(height*height);
         printf("BMI is %f\n" , BMI);
         }