#include<stdio.h>

int main()
{
int assign;
int rain;
int sum;
printf("Enter whether it will rain or not(0/1): ");
scanf("%d", &rain);
printf("Enter assignment done or not(0/1): ");
scanf("%d", &assign);
sum= (assign*2 + rain);

switch(sum)
{
case 0:
  printf("Study");
  break;
case 1:
  printf("Study");
  break;
case 2:
  printf("hangout with friends");
  break;
case 3:
  printf("watch a movie");

}

}

