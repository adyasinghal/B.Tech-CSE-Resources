#include<stdio.h>

int main(){

float avgscore;

printf("Enter Average score");
scanf("%f", &avgscore);


if(avgscore>= 85){
printf("Your grade is A");
}
else if(avgscore>= 75 && avgscore< 85){
printf("Your grade is B");
}
else if(avgscore>= 65 && avgscore< 75){
printf("Your grade is C");
}
else if(avgscore>= 50 && avgscore< 65){
printf("Your grade is D");
}
else if(avgscore>= 30 && avgscore< 50){
printf("Your grade is E");
}
else if(avgscore>= 0 && avgscore< 30){
printf("Your grade is F");
}
else{
    printf("Invalid score");
}

}
