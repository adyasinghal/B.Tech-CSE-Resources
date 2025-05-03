#include<stdio.h>

int main(){
int id;
int temp;
int s=0;

printf("Enter id");
scanf("%d", &id);
while(id>0){
temp=id%10;
s=s+temp;
id=id/10;
}
if (s%3==0){
printf("Team A");
}
else if (s%5==0){
printf("Team B");
}
else if (s%7==0){
printf("Team C");
}
else{
printf("None");
}
}

