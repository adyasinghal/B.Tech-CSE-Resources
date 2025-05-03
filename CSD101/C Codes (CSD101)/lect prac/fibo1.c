// to display fibonacci series

#include<stdio.h>

int main(){
    int limit;
    int nextterm=0;
    printf("Enter limit for fibo: ");
    scanf("%d", &limit);

    int t1=0;
    int t2=1;
    //printf("%d" , t1);
    while (nextterm<=limit){
        printf("%d,", nextterm);
        t1=t2;
        t2=nextterm;
        nextterm=t1+t2;
        

    }

}