#include<stdio.h>

int fibo(int n){
    if (n==0){
        return 0;
    }
    else if(n==1){
        return 10;
    }
    else{
        return (fibo(n-1) + fibo(n-2));
    }
}

int fibosum(int b){
    int sum=0;
    for (int i=0; i<=b; i++){
        sum+=fibo(i);
    }
    return sum;
}

int main(){
    int a;
    printf("Enter the month number (starting from 0) to calculate your savings: ");
    scanf("%d", &a);
    int res1= fibo(a);
    printf("For month %d, based on the Fibonacci savings strategy, you will save: INR %d", a, res1);
    int res2= fibosum(a);
    printf("\nYour total savings after %d months will be: INR %d", a, res2);

}
