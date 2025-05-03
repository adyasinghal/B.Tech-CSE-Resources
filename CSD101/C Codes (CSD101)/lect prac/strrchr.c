#include<stdio.h>
#include<string.h>

int main(){
    char *s="Hello";
    char ch='l';
    char *result =strrchr(s, ch);
    if(result!=NULL){
        printf("Position %ld", result-s);
    }
    else{
        printf("\nChar not in str!");
    }
}