#include<stdio.h>

int main(){
float weight;
float height;
float bmi;
int num;
float arrheight[100];
float arrweight[100];
float arrbmi[100];
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


for(int j=0; j<num; j++){
if(arrbmi[j]>18.5 && arrbmi[j]<=25){
    printf("\nStudent %d BMI is Normal ", j+1);
    printf("Height: %f ", arrheight[j]);
    printf("Weight: %f ", arrweight[j]);
    printf("BMI: %f ", arrbmi[j]);
}
}
}