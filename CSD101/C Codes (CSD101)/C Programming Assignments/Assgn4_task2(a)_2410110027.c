#include<stdio.h>

int main(){
int assign;
int rain;

printf("Enter whether it will rain or not(0/1): ");
scanf("%d", &rain);
printf("Enter assignment done or not(0/1): ");
scanf("%d", &assign);

if(assign==0){
printf("Study");
}
else if(assign==1 && rain==0){
printf("Hangout with friends");
}
else{
printf("Watch a movie");
}
}
