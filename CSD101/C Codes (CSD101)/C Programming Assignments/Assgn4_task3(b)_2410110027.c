#include<stdio.h>

int main(){

float avgscore;
int a;

printf("Enter Average score");
scanf("%f", &avgscore);

if(avgscore>= 85){
a=1;
}
else if(avgscore>= 75 && avgscore< 85){
a=2;
}
else if(avgscore>= 65 && avgscore< 75){
a=3;
}
else if(avgscore>= 50 && avgscore< 65){
a=4;
}
else if(avgscore>= 30 && avgscore< 50){
a=5;
}
else if(avgscore>= 0 && avgscore< 30){
a=6;
}
else{
a=7;
}

switch(a){

case 1:
  printf("Garde is A");
  break;
case 2:
  printf("Grade is B");
  break;
case 3:
  printf("Grade is C");
  break;
case 4:
  printf("Garde is D");
  break;
case 5:
  printf("Grade is E");
  break;
case 6:
  printf("Grade is F");
  break;
case 7:
  printf("Invalid Input");
  break;



}

}
