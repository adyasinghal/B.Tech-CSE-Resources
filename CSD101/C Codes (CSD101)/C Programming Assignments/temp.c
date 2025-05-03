#include<stdio.h>
#include <string.h>

int main(){
    char str1[30];
    int flag=0;
    printf("Type a string: \n");
    scanf("%s", str1);

    int len = strlen(str1);

    for(int i=0; i<len/2; i++){
        if(str1[i]!=str1[len-i-1]){
            flag=1;
            break;
        }
    }

    if (flag){
        printf("Not palindrome");
    }
    else{
        printf("Palindrome");
    }

}