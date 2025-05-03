#include<stdio.h>

int main(){

int Isbook;

int boxmove;
for (int i=1;;i++){
printf("\nMoving box %d:",i);
for (int j=1;j<=3;j++){
printf("Item %d", j);
printf(" IsBook-");
scanf("%d", &Isbook);
if (Isbook==1){
printf("\nYay I found the book");
break;
}
}
printf("Are all boxes moved: ");
scanf("%d", &boxmove);
if (boxmove==1){
printf("Finally, I'm done ");
break;
}
}
}
