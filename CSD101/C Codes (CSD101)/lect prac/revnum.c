//to reverse the number

#include<stdio.h>

int main(){
    int num;
    int revnum;
    int newnum=0;
    printf("Enter a number to reverse: ");
    scanf("%d", &num);
    while(num!=0){
        revnum=num%10;
        newnum=(newnum*10)+revnum;
        num=num/10;

    }
    printf("%d", newnum);
    

}