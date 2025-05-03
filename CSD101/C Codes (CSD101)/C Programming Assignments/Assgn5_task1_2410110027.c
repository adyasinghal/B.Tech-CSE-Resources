#include<stdio.h>

int main(){
float weight;
float height;
float bmi;
int num;

printf("Enter number of students: ");
scanf("%d", &num);

if (num<0){
printf("Invalid Input");
}

for (int i=1;i<=num;i++){
printf("\nEnter the weight of student %d: ", i);
scanf("%f",&weight);
printf("Enter the height: ");
scanf("%f",&height);
bmi=weight/(height*height);
printf("%f\n", bmi);

if (bmi>=17 && bmi<=18.5){
printf("\nMild thinness");
}

else if (bmi>18.5 && bmi<=25){
printf("\nNormal");
}

else if (bmi>25){
printf("\noverweight");
}
else{
printf("\nInhumane status");
}
}


}

