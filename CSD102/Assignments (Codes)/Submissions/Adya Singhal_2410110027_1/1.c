#include<stdio.h>

int swap1(int num1, int num2){
    num1=num2;
    return num2;
}

int swap2(int num1, int num2){
    num2=num1;
    return num1;
}

int main(){
    int a,b;
    printf("Enter first number: ");
    scanf("%d",&a);
    printf("Enter second number: ");
    scanf("%d",&b);
    printf("first num= %d , second num= %d" , swap1(a,b), swap2(a,b));

}