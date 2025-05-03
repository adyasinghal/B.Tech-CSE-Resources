#include<stdio.h>

int main(){
    char str1[10]="ShivNadar";
    int i=0, count=0;
    while(str1[i]!='\0'){
        count++;
        i++;
    }
    printf("%d",count);
}