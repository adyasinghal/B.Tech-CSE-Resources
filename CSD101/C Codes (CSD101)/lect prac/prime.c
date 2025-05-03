//to check prime or not

#include<stdio.h>
int main(){
    int num;
    int num1;
    printf("Enter number to check for prime: ");
    scanf("%d", &num);

    for (int i=2; i<num; i++){
        num1=num%i;
        if(num1==0){
            printf("Not prime");
            break;
        }
        else{
            printf("prime");
            break;
        }

    }
}