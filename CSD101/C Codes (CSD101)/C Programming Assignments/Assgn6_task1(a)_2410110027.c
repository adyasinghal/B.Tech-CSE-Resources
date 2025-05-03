#include<stdio.h>

int main(){
float weight;
float height;
float bmi;
int num;
int arrheight[100];
int arrweight[100];
int arrbmi[100];
int num2;


printf("Enter number of students: ");
scanf("%d", &num);

if (num<0){
printf("Invalid Input");
}

for (int i=1;i<=num;i++){
printf("\nEnter the weight of student %d: ", i);
scanf("%f",&weight);
arrweight[i-1]=weight;
printf("Enter the height: ");
scanf("%f",&height);
arrheight[i-1]=height;
bmi=weight/(height*height);
arrbmi[i-1]=bmi;


}
printf("You would like to search for which student: ");
scanf("%d", &num2);

printf("Height: %d ", arrheight[num2-1]);
printf("Weight: %d ", arrweight[num2-1]);
printf("BMI: %d ", arrbmi[num2-1]);
if (arrbmi[num2-1]>=17 && arrbmi[num2-1]<=18.5){
printf("\nMild thinness");
}

else if (arrbmi[num2-1]>18.5 && arrbmi[num2-1]<=25){
printf("\nNormal");
}

else if (arrbmi[num2-1]>25){
printf("\noverweight");
}
else{
printf("\nInhumane status");
}

}