#include<stdio.h>

int main(){
    char str1[10]="ShivNadar";
    int i=0, count=0;
    while(i<10){
        if(str1[i]=='a'||str1[i]=='e'||str1[i]=='i'||str1[i]=='o'||str1[i]=='u'){
            count++;
        }
        i++;
    }
    printf("%d", count);
}