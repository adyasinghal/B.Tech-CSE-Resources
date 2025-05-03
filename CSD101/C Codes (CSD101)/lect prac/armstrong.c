// to check whether armstrong or not
#include<stdio.h>
#include<math.h>

int main(){
    int num, num1, num2;
    int count=0;
    int sum=0;    
    int rem1;
    printf("Enter number to check armstrong: ");
    scanf("%d", &num);
    num1=num;
    num2=num;
    if (num<=0){
        printf("Invalid input");    
    }
    else{
        while(num!=0){
            num=num/10;
            count++;                      

        }
        //printf("%d\n", count);
        while(num1!=0){
            rem1=num1%10;
            sum+=pow(rem1,count);
            num1=num1/10;
        }
        //printf("%d\n", sum);
        if (num2==sum){
            printf("Armstrong number");
        }
        else{
            printf("Not armstrong");
        }
    }
}