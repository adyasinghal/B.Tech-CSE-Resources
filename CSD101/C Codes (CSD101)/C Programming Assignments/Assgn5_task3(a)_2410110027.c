#include<stdio.h>

int main(){

int Isbook;
int boxnum;
printf("Enter the number of boxes: ");
scanf("%d", &boxnum);

for (int i=1;i<=boxnum;i++){
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


}
}
