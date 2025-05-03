#include<stdio.h>

int main(){
    int terms;
    int nt=0;
    printf("Enter number of terms: ");
    scanf("%d", &terms);

    int t1=0;
    int t2=1;
    for (int i=1; i<=terms; i++){
        printf("%d,", nt);
        t1=t2;
        t2=nt;
        nt=t1+t2;

    }
}