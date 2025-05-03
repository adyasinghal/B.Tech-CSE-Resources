#include<stdio.h>

int main()
{
float height;
float weight;
float bmi;

printf("Enter height in metres: ");
scanf("%f", &height);
printf("Enter the weight in kg: ");
scanf("%f", &weight);
bmi=(weight/(height*height));
if(bmi>=17 && bmi<=18.5){
printf("Mild thinness");
}
else if (bmi>18.5 && bmi<=25){
printf("Normal");
}
else if (bmi>25){
printf("Overweight");
}
else{
printf("inhuman status");}
}
