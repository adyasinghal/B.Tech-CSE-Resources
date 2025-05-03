#include<stdio.h>

int main()
         {
            int days;
            float waste;
            printf("Enter the number of days: ");
            scanf("%d" , &days);
            waste = (days* 10.8); //(24x60x60)/8000 =10.8
            printf("The amount of water wasted in litres in 20 days is: %f\n" , waste);
         }